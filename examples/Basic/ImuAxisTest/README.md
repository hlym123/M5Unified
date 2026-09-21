# IMU / MAG live axis test

Open `ImuAxisTest.ino`, select your board in Arduino IDE, and upload it with
M5Unified and M5GFX installed. CoreS3 is the first reference device.

The screen shows all nine signed readings in three fixed panels at 10 Hz:

- **ACCEL (g):** X, Y, Z acceleration.
- **GYRO (deg/s):** X, Y, Z angular velocity.
- **MAG (mG):** X, Y, Z magnetic field, using M5Unified's conversion.

Columns use **X = red, Y = green, Z = blue** and also show axis names.
The sketch uses a sprite to update the display without clearing it between
frames. It falls back to direct drawing if sprite memory is unavailable.
Compact screens use smaller text and reduce numeric precision when necessary.
Displays smaller than 120 x 120 pixels show the serial connection instructions.
Headless devices also provide the complete serial report.

Open Serial Monitor at **115200 baud** for four decimal places, the board and IMU
type, the observed sensor mask, and each sensor's sample age (`age_ms`).
`NO DATA` means no sample has been received; `STALE` means the last sample is more
than 500 ms old. Both states show `--` instead of numeric readings. In particular,
a device without MAG does not show misleading zero magnetic-field values.

To check directions on CoreS3:

1. Point each positive axis upward and hold still: ACCEL on that axis should
   approach +1 g. Reversing it should approach -1 g.
2. Rotate around one axis at a time: check the sign and dominant GYRO component
   against the right-hand rule in the [CoreS3 axis diagram](../../../docs/devices/cores3-imu.md).
3. Rotate slowly in a stable magnetic field and observe MAG X/Y/Z. Keep magnetic
   accessories and tools away; these values are field components, not heading angles.

The sketch displays the default `M5.Imu` output frame. It does not remap axes,
calibrate automatically, clear offsets or save to NVS. Existing offsets loaded
at initialization remain active. Only internal IMU detection is enabled.
Display rotation changes the text layout, not the sensor axes.

Use the [host sensor reference](../../../docs/devices/imu-orientation.md) to check
which sensors your model contains, and the [test procedure](../../../docs/guides/imu-axis-test.md)
to record the results. A successful build is not a hardware direction check.
