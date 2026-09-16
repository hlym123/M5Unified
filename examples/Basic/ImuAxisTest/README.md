# IMU axis test

Requires M5Unified and M5GFX. Select your board and upload the sketch. CoreS3 is
the first reference device; the sketch also reports over serial on headless devices.

Read output at **115200 baud**. Acceleration is in g, angular velocity in deg/s,
and magnetic field uses the library's mG conversion. No sensor values are shown
until samples have been observed; data older than 500 ms is marked STALE.

The sketch does not remap axes, calibrate automatically, clear offsets or write
NVS. Existing offsets loaded during initialization remain active. Only internal
IMU detection is enabled. The displayed observed mask is based on received samples,
not a complete hardware inventory. CoreS3 should report all three sensors.

Use [CoreS3 diagrams](../../../docs/devices/cores3-imu.md) and the
[test procedure](../../../docs/guides/imu-axis-test.md). Keep the housing pose
fixed and do not assume that changing display rotation changes IMU axes.
