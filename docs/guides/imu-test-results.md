# IMU / MAG device test results

Tests use [ImuAxisTest](../../examples/Basic/ImuAxisTest) with the default
M5Unified sensor axes. User confirmation and automated serial checks are
recorded separately so a data-refresh check does not imply a full axis test.

## CoreS3 — OK

- Date: 2026-09-22.
- Result: **OK**, confirmed by the user before moving to StickS3.
- Firmware: M5Unified `64ad459` (native-size DejaVu fonts);
  M5GFX `a1e39fe02abce9f85d4e326b8f537d3f8af34b6a`.
- Device USB serial: `80:45:6B:4D:55:50`.
- Detected: CoreS3, BMI270; ACCEL, GYRO and MAG samples received (`0x07`).
- Serial validation: approximately 25 seconds on the initial UI and 8 seconds
  after the font update; all three channels refreshed without `STALE` readings.
- Firmware upload hash verification passed.
- Detailed six-pose, gyro rotation and magnetic-field axis measurements were
  not captured in the automated log.
- Separate observation: boot reports a PSRAM initialization error. This was
  already present before this example was flashed; sensor data still refreshed.
  The IMU test result does not certify PSRAM health.

## StickS3 — serial checks passed; user confirmation pending

- Date: 2026-09-22.
- Firmware: M5Unified `64ad459`;
  M5GFX `a1e39fe02abce9f85d4e326b8f537d3f8af34b6a`.
- Device USB serial: `AC:27:6E:D3:58:24`.
- Build: PlatformIO espressif32 6.10.0 / Arduino 2.0.17, generic ESP32-S3
  target with USB CDC enabled and M5Unified automatic board detection.
- Firmware upload hash verification passed; 8 MB flash detected.
- Detected: StickS3, BMI270; observed sensor mask `0x03`.
- Approximately 20 seconds of serial capture: ACCEL and GYRO each returned
  192 valid reports after the initial `NO DATA`, with no `STALE` readings.
  Maximum sample ages were 18 ms (ACCEL) and 5 ms (GYRO).
- No internal MAG is fitted. All 193 MAG reports correctly showed `NO DATA`
  with dashes, rather than numeric zeros.
- Example captured values (physical pose not recorded):
  ACCEL `(-0.9812, +0.0044, +0.2446)` g;
  GYRO `(-0.4272, +0.0000, +0.0000)` deg/s.
- Screen readability and physical axis-direction confirmation: pending user test.
