# Basic concepts

## Capabilities and updates

M5Unified exposes built-in hardware through the global `M5` object. A common API
does not mean every device has every sensor. Check initialization and actual data
availability. `M5.update()` services input; use the subsystem’s own update and
read methods where required, including `M5.Imu.update()`.

## Product and sensor coordinates

Identify the physical front and top of the housing. Sensor chip axes may require
driver mounting corrections before becoming product axes. Application remapping
is a further step. See [IMU](../api/imu.md) for units and the target right-handed frame.
Display pixel coordinates and display rotation are separate from IMU coordinates.

[API reference](../api/README.md) · [Documentation home](../README.md)
