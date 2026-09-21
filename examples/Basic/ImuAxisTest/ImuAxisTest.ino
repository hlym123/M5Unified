// Display the library's current axes without remapping or recalibrating them.
#include <M5Unified.h>

static constexpr uint32_t reportIntervalMs = 100;
static constexpr uint32_t staleAfterMs = 500;
static const char* names[] = {"ACCEL", "GYRO", "MAG"};
static const char* units[] = {"g", "deg/s", "mG"};
static const uint32_t axisColors[] = {0xFF6060, 0x55DE8C, 0x65B7FF};
static m5::imu_data_t sample;
static uint8_t observedMask = 0;
static uint32_t lastSampleMs[3] = {};
static uint32_t lastReportMs = 0;
static M5Canvas canvas(&M5.Display);
static bool buffered = false;
static int viewWidth = 0, viewHeight = 0;
static int viewX = 0, viewY = 0;

static const char* imuTypeName(m5::imu_t type)
{
  switch (type)
  {
  case m5::imu_sh200q: return "SH200Q";
  case m5::imu_mpu6050: return "MPU6050";
  case m5::imu_mpu6886: return "MPU6886";
  case m5::imu_mpu9250: return "MPU9250";
  case m5::imu_bmi270: return "BMI270";
  case m5::imu_unknown: return "unknown";
  default: return "none";
  }
}

static const char* statusFor(int sensor, uint32_t now)
{
  if (!(observedMask & (1u << sensor))) return "NO DATA";
  return static_cast<uint32_t>(now - lastSampleMs[sensor]) > staleAfterMs ? "STALE" : "OK";
}

static void drawValues(uint32_t now)
{
  if (viewWidth == 0) return;
  auto& display = buffered ? static_cast<lgfx::LGFXBase&>(canvas)
                           : static_cast<lgfx::LGFXBase&>(M5.Display);
  const int ox = buffered ? 0 : viewX;
  const int oy = buffered ? 0 : viewY;
  const bool large = viewWidth >= 300 && viewHeight >= 200;
  const int textSize = large ? 2 : 1;
  const int rowsTop = large ? 62 : 38;
  const int rowHeight = (viewHeight - rowsTop - 14) / 3;
  const int columnWidth = (viewWidth - 12) / 3;
  display.startWrite();
  display.fillRect(ox, oy, viewWidth, viewHeight, TFT_BLACK);
  display.setFont(&fonts::Font0);
  display.setTextWrap(false);
  display.setTextSize(textSize);
  display.setTextColor(TFT_WHITE);
  display.setCursor(ox + 6, oy + 4);
  display.print("IMU / MAG");
  display.setTextSize(1);
  display.setCursor(ox + 6, oy + (large ? 25 : 16));
  display.print(M5.Imu.isEnabled() ? imuTypeName(M5.Imu.getType()) : "IMU NOT DETECTED");

  for (int axis = 0; axis < 3; ++axis)
  {
    display.setTextSize(textSize);
    display.setTextColor(axisColors[axis]);
    const char* label = axis == 0 ? "X" : axis == 1 ? "Y" : "Z";
    const int centre = ox + 6 + columnWidth * axis + columnWidth / 2;
    display.drawString(label, centre - display.textWidth(label) / 2, oy + (large ? 42 : 27));
  }

  for (int sensor = 0; sensor < 3; ++sensor)
  {
    const int y = oy + rowsTop + rowHeight * sensor;
    const char* status = statusFor(sensor, now);
    const bool valid = status[0] == 'O';
    display.fillRoundRect(ox + 3, y, viewWidth - 6, rowHeight - 3, 3, 0x14202Cu);
    display.setTextColor(TFT_WHITE);
    display.setTextSize(textSize);
    display.setCursor(ox + 8, y + 3);
    display.printf(large ? "%s (%s)" : "%s %s", names[sensor], units[sensor]);
    display.setTextSize(1);
    display.setTextColor(valid ? 0xA9C7B4u : 0xFFCC66u);
    display.drawString(status, ox + viewWidth - 8 - display.textWidth(status), y + 4);

    for (int axis = 0; axis < 3; ++axis)
    {
      char value[32];
      if (valid) snprintf(value, sizeof(value), sensor == 0 ? "%+.2f" : "%+.1f", sample.sensor[sensor].value[axis]);
      else snprintf(value, sizeof(value), "--");
      display.setTextSize(textSize);
      // Keep wide MAG readings inside their column on compact screens.
      if (display.textWidth(value) > columnWidth - 4) display.setTextSize(1);
      if (valid && display.textWidth(value) > columnWidth - 4)
        snprintf(value, sizeof(value), "%+.0f", sample.sensor[sensor].value[axis]);
      display.setTextColor(valid ? axisColors[axis] : 0x8493A2u);
      const int centre = ox + 6 + columnWidth * axis + columnWidth / 2;
      display.drawString(value, centre - display.textWidth(value) / 2, y + (large ? 25 : 13));
    }
  }
  display.setTextSize(1);
  display.setTextColor(0x9CAABBu);
  display.setCursor(ox + 6, oy + viewHeight - 10);
  display.print(viewWidth >= 200 ? "LIVE 10 Hz | Serial 115200" : "LIVE | 115200");
  display.endWrite();
  if (buffered) canvas.pushSprite(viewX, viewY);
  M5.Display.display();
}

static void report(uint32_t now)
{
  drawValues(now);
  Serial.printf("ms=%lu board=%u imu=%s observed_mask=0x%02x\n",
                static_cast<unsigned long>(now), static_cast<unsigned>(M5.getBoard()),
                imuTypeName(M5.Imu.getType()), observedMask);
  for (int sensor = 0; sensor < 3; ++sensor)
  {
    const char* status = statusFor(sensor, now);
    Serial.printf("%s [%s] %s", names[sensor], units[sensor], status);
    if (observedMask & (1u << sensor))
      Serial.printf(" age_ms=%lu", static_cast<unsigned long>(now - lastSampleMs[sensor]));
    if (status[0] == 'O')
    {
      const auto& xyz = sample.sensor[sensor];
      Serial.printf(" x=%+.4f y=%+.4f z=%+.4f", xyz.x, xyz.y, xyz.z);
    }
    else Serial.print(" x=-- y=-- z=--");
    Serial.println();
  }
}

void setup()
{
  auto cfg = M5.config();
  cfg.internal_imu = true;
  cfg.external_imu = false;
  M5.begin(cfg);
  Serial.begin(115200);
  // Preserve loaded offsets and the default device axes. Never save to NVS.
  M5.Imu.setCalibration(0, 0, 0);
  Serial.println("IMU / MAG axis test: default M5.Imu output, loaded offsets retained.");
  Serial.println("NO DATA = no sample yet; STALE = last sample older than 500 ms.");
  Serial.println("ACCEL: g; GYRO: deg/s; MAG: mG. X=red, Y=green, Z=blue.");

  if (M5.Display.width() > 0 && M5.Display.height() > 0)
  {
    if (M5.Display.width() < M5.Display.height())
      M5.Display.setRotation(M5.Display.getRotation() ^ 1);
    viewWidth = M5.Display.width() > 320 ? 320 : M5.Display.width();
    viewHeight = M5.Display.height() > 240 ? 240 : M5.Display.height();
    M5.Display.fillScreen(TFT_BLACK);
    if (viewWidth < 120 || viewHeight < 120)
    {
      M5.Display.setTextSize(1);
      M5.Display.setTextColor(TFT_WHITE);
      M5.Display.setCursor(0, 0);
      M5.Display.println("IMU / MAG\nSerial: 115200");
      viewWidth = 0;  // Very small displays use the complete serial report.
    }
    else
    {
      viewX = (M5.Display.width() - viewWidth) / 2;
      viewY = (M5.Display.height() - viewHeight) / 2;
      canvas.setColorDepth(16);
      buffered = canvas.createSprite(viewWidth, viewHeight) != nullptr;
      if (!buffered) Serial.println("No sprite memory; drawing directly to the display.");
    }
  }
  report(millis());
}

void loop()
{
  M5.update();
  const uint32_t now = millis();
  if (M5.Imu.isEnabled())
  {
    // update() returns one freshness bit for each sensor, not just a boolean.
    const uint8_t fresh = static_cast<uint8_t>(M5.Imu.update());
    if (fresh)
    {
      const auto& data = M5.Imu.getImuData();
      for (int sensor = 0; sensor < 3; ++sensor)
      {
        if (fresh & (1u << sensor))
        {
          sample.sensor[sensor] = data.sensor[sensor];
          lastSampleMs[sensor] = now;
          observedMask |= 1u << sensor;
        }
      }
    }
  }
  if (static_cast<uint32_t>(now - lastReportMs) >= reportIntervalMs)
  {
    lastReportMs = now;
    report(now);
  }
  delay(1);
}
