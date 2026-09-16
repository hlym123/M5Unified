// Observe the library's current axis mapping without changing it.
#include <M5Unified.h>

static m5::imu_data_t sample;
static uint8_t observedMask = 0;
static uint32_t lastSampleMs[3] = {};
static uint32_t lastReportMs = 0;
static const char* names[] = {"accel", "gyro", "mag"};
static const char* units[] = {"g", "deg/s", "mG"};

static const char* statusFor(int sensor, uint32_t now)
{
  if (!(observedMask & (1u << sensor))) return "NO DATA";
  return static_cast<uint32_t>(now - lastSampleMs[sensor]) > 500 ? "STALE" : "OK";
}

static void report(uint32_t now)
{
  const bool screen = M5.Display.width() > 0 && M5.Display.height() > 0;
  if (screen)
  {
    M5.Display.startWrite();
    M5.Display.fillScreen(TFT_BLACK);
    M5.Display.setCursor(0, 0);
    M5.Display.println("IMU axis test");
    M5.Display.println("      X       Y       Z");
  }
  Serial.printf("ms=%lu observed_mask=0x%02x\n", static_cast<unsigned long>(now), observedMask);
  for (int i = 0; i < 3; ++i)
  {
    const char* status = statusFor(i, now);
    Serial.printf("%s [%s] %s", names[i], units[i], status);
    if (screen) M5.Display.printf("%s [%s] %s\n", names[i], units[i], status);
    if (status[0] == 'O')
    {
      const auto& xyz = sample.sensor[i];
      Serial.printf(" x=%+.4f y=%+.4f z=%+.4f", xyz.x, xyz.y, xyz.z);
      if (screen) M5.Display.printf("%+7.2f %+7.2f %+7.2f\n", xyz.x, xyz.y, xyz.z);
    }
    else if (screen) M5.Display.println("   --      --      --");
    Serial.println();
  }
  if (screen)
  {
    M5.Display.endWrite();
    M5.Display.display();
  }
}

void setup()
{
  auto cfg = M5.config();
  cfg.internal_imu = true;
  cfg.external_imu = false;
  M5.begin(cfg);
  Serial.begin(115200);
  // Disable automatic calibration. Preserve any offsets already loaded by begin().
  M5.Imu.setCalibration(0, 0, 0);
  Serial.printf("board=%u imu_type=%u enabled=%u\n", static_cast<unsigned>(M5.getBoard()),
                static_cast<unsigned>(M5.Imu.getType()), M5.Imu.isEnabled());
  Serial.println("No axis remap or NVS writes. Loaded calibration offsets remain in use.");
  Serial.println("NO DATA = unavailable or no sample yet; STALE = no update for 500 ms.");
  Serial.println("CoreS3 expects accel + gyro + mag. Compare against the axis reference.");
  if (M5.Display.width() > 0 && M5.Display.height() > 0)
  {
    M5.Display.setFont(&fonts::Font0);
    M5.Display.setTextSize(M5.Display.width() >= 300 && M5.Display.height() >= 160 ? 2 : 1);
    M5.Display.setTextColor(TFT_WHITE, TFT_BLACK);
    M5.Display.setTextWrap(false);
  }
}

void loop()
{
  M5.update();
  const uint32_t now = millis();
  if (M5.Imu.isEnabled())
  {
    const uint8_t fresh = static_cast<uint8_t>(M5.Imu.update());
    if (fresh)
    {
      const auto data = M5.Imu.getImuData();
      for (int i = 0; i < 3; ++i)
      {
        if (fresh & (1u << i))
        {
          sample.sensor[i] = data.sensor[i];
          lastSampleMs[i] = now;
          observedMask |= 1u << i;
        }
      }
    }
  }
  if (static_cast<uint32_t>(now - lastReportMs) >= 100)
  {
    lastReportMs = now;
    report(now);
  }
  delay(1);
}
