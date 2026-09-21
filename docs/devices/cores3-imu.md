# [CoreS3](https://docs.m5stack.com/zh_CN/core/CoreS3)

<img src="../assets/imu/hosts/generated/cores3-imu-sample.svg" alt="CoreS3 ACCEL and MAG axes with positive GYRO rotation about each axis" width="1000">

- **ACCEL: Yes — BMI270** (three-axis accelerometer).
- **GYRO: Yes — BMI270** (three-axis gyroscope).
- **MAG: Yes — BMM150** (three-axis magnetometer).

The CoreS3 reference image retains its original axis intersection and straight
arrows, with curved GYRO arrows added. Face the display with the camera edge at the bottom: +X points
right, +Y toward the top edge, and +Z out of the display face.

Straight arrows show the shared ACCEL/MAG directions. Each curved GYRO arrow
wraps around its corresponding straight axis in the perpendicular plane.
Positive rotation follows the
right-hand rule: viewed from the positive end toward O, it is counterclockwise.

MAG here uses the M5Unified output frame with no application axis override.
The [CoreS3 handling in IMU_Class](../../src/utility/IMU_Class.inl) inverts MAG Y/Z
when the BMI270 is detected at 0x69. This is not a diagram of the raw BMM150 package axes.
The annotation has been checked against the documentation and implementation;
the physical direction mapping has not been tested on a device in this documentation change.

CoreS3-Lite also documents BMI270 + BMM150. CoreS3-SE omits IMU and MAG;
see the [CoreS3-SE comparison](https://docs.m5stack.com/zh_CN/core/CoreS3-SE).

For live readings, use [ImuAxisTest](../../examples/Basic/ImuAxisTest).
Hardware availability and the direction of returned axes are separate checks.

[Host sensor reference](imu-orientation.md) · [IMU API](../api/imu.md) · [Device index](README.md)
