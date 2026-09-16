# IMU

Use `M5.Imu` to read acceleration, angular velocity and magnetic field data.
Available sensors depend on the device and hardware revision.

## Readings and units

- `accel.x/y/z`: accelerometer specific force, in **g**. At rest, an axis pointing
  vertically upward should measure approximately +1 g in the agreed coordinate frame;
  pointing downward gives approximately -1 g. Free fall differs from resting on a desk.
- `gyro.x/y/z`: angular velocity in **degrees per second**. Positive rotation follows
  the right-hand rule. Point the thumb along the positive axis; curled fingers give
  positive rotation. Looking from that positive end toward the origin, it is counterclockwise.
- `mag.x/y/z`: magnetic-field components in **milligauss (mG)** with the current
  library conversion. 10 mG = 1 microtesla. Positive means the field has a component
  along that positive axis. These values are not heading angles; axis testing alone
  does not establish absolute field accuracy.

## Product coordinate convention

The proposed product frame is **X right, Y toward the product top, Z out of its
front**. It is right-handed: X cross Y = Z. Accel, gyro and mag share that frame.
Use a visible housing landmark to identify the front and top, rather than screen content.

These are target directions for verification. Current device mappings must be
checked before being described as conforming. Changing display `setRotation()`
does not select an IMU frame.

## Initialization and data updates

Enable `internal_imu` in `M5.config()` and initialize with `M5.begin(cfg)`.
Use `isEnabled()` and `getType()` to inspect initialization.

`update()` returns a bitmask of sensors whose readings were updated:
`sensor_mask_accel`, `sensor_mask_gyro`, `sensor_mask_mag`.
Zero means no fresh readings in that call; it does not prove no sensor is installed.
`getImuData()` retrieves the latest converted and mapped values; it is not a new sample request.
Track freshness separately for each sensor and do not display an unobserved channel as zero.

Convenience accessors include `getAccel()`, `getGyro()` and `getMag()`. For testing
all three channels and tracking freshness, use `update()` with `getImuData()`.

## Axis mapping

There are three separate frames: the sensor chip frame, the product frame after
the driver's per-sensor mounting correction, and an optional application frame.
Installation corrections for accel, gyro and mag need not be identical.

```cpp
bool setAxisOrder(axis_t axis0, axis_t axis1, axis_t axis2);
bool setAxisOrderRightHanded(axis_t axis0, axis_t axis1);
bool setAxisOrderLeftHanded(axis_t axis0, axis_t axis1);
```

The arguments select the source axis and sign for output X, Y and Z. Axis constants
are `axis_x_pos`, `axis_x_neg`, `axis_y_pos`, `axis_y_neg`, `axis_z_pos`, `axis_z_neg`.
The handed helpers derive the third axis from the first two. Check the returned
boolean: an invalid repeated-axis selection is rejected. Application remapping
is applied on top of fixed device corrections and affects all three sensors.

Leave application axis settings unchanged when checking a device's default mapping.
Calibration adjusts offsets; it does not repair an incorrect axis permutation.

## Calibration

`setCalibration(0, 0, 0)` disables automatic offset adjustment. It does not erase
previously loaded offsets. `saveOffsetToNVS()` and `loadOffsetFromNVS()` persist
and restore offsets; `clearOffsetData()` clears the current in-memory offsets.
The axis-test example preserves loaded offsets and never saves or clears them.

## Reference and examples

- [CoreS3: accel, gyro and mag](../devices/cores3-imu.md)
- [Axis verification procedure](../guides/imu-axis-test.md)
- [ImuAxisTest](../../examples/Basic/ImuAxisTest): current output and per-sensor freshness.
- [Existing Imu example](../../examples/Basic/Imu): includes calibration and NVS writes.

[API index](README.md) · [Documentation home](../README.md)
