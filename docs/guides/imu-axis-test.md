# Verify IMU axes

Run [ImuAxisTest](../../examples/Basic/ImuAxisTest) with serial output at 115200 baud.
Start with the [host sensor reference](../devices/imu-orientation.md), then use the [CoreS3 axis diagram](../devices/cores3-imu.md) when testing CoreS3. Keep the device pose independent of the displayed text orientation.

## Before testing

Record device model, hardware revision, M5Unified/M5GFX versions and loaded
calibration history. The example enables only internal IMU detection, disables
automatic calibration, leaves axis ordering unchanged and does not write NVS.

The observed sensor mask records channels that have actually returned samples.
`NO DATA` means unavailable or not sampled yet; it is not a definitive hardware
capability query. `STALE` means the last sample is more than 500 ms old. Missing
and stale channels show dashes, not invented zeros. Use the host reference to determine
which channels are expected. Stop interpretation if an expected channel has no valid samples.

## Accel: six static poses

Point +X, -X, +Y, -Y, +Z, -Z upward in turn. Allow motion to settle. Positive-up
should give about +1 g on the corresponding positive coordinate, negative-up
about -1 g; record axis swaps and sign mismatches separately from small offsets.

## Gyro: both directions around each axis

Rotate gently around one axis, following the right-hand rule for the positive
test. Reverse the motion for the negative test. Check the dominant component
and its sign, then check the still reading. Avoid using Euler-angle terminology
as a substitute for identifying the physical axis.

## Mag: controlled reference

Use a stable magnetic field and, where available, a reference magnetometer or
known field fixture. Align each positive axis with the same reference field,
then reverse it. Record the sign reversal of the projected component. Earth’s
field has a vertical component: facing geographic north alone is not a three-axis test.
Keep attachments with magnets and magnetic tools away from the setup.

## Record results

For each sensor, record **pass**, **mismatch**, **unavailable** or **not tested**,
with the pose/motion, component values, photos and proposed correction if needed.
Do not mark a checkbox complete based on compilation or a reference picture.

[IMU API](../api/imu.md) · [Documentation home](../README.md)
