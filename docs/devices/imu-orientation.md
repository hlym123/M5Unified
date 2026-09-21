# IMU host reference

The host list and grouping follow M5GFX's `docs/device-orientation.md`, including
its pending figures. Kits and hardware revisions are included under their host.

**ACCEL** = accelerometer; **GYRO** = gyroscope; **MAG** = magnetometer.
**Yes** = fitted; **No** = absent from the documented configuration;
**Varies** = see the model/revision note; **Pending** = missing or conflicting evidence.
A six-axis IMU provides ACCEL/GYRO, not MAG. External sensors are excluded.

Photographs come from the [official product catalog](https://docs.m5stack.com/zh_CN/products).
Sensor availability follows the linked product specifications and may differ
across hardware revisions. CoreS3 is the first annotated axis example;
the remaining images identify their hosts without direction overlays.

Reviewed: 2026-09-21. [Hardware sources](../assets/imu/hosts/products/sources.json).

## Device figures


### Atom

<table>
<tr>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/AtomS3">AtomS3</a></strong><br>
<img src="../assets/imu/hosts/products/atoms3.webp" alt="AtomS3 catalog product photograph" width="220"><br>
ACCEL: <strong>Yes</strong> · MPU6886<br>
GYRO: <strong>Yes</strong> · MPU6886<br>
MAG: <strong>No</strong><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/AtomS3R">AtomS3R</a></strong><br>
<img src="../assets/imu/hosts/products/atoms3r.webp" alt="AtomS3R catalog product photograph" width="220"><br>
ACCEL: <strong>Yes</strong> · BMI270<br>
GYRO: <strong>Yes</strong> · BMI270<br>
MAG: <strong>Yes</strong> · BMM150<br>
</td>
<td width="25%"></td>
<td width="25%"></td>
</tr>
</table>


### Core

<table>
<tr>
<td width="25%" align="center" valign="top">
<strong>Core (<a href="https://docs.m5stack.com/zh_CN/core/basic_v2.7">Basic</a> / <a href="https://docs.m5stack.com/zh_CN/core/m5go_v2.7">M5GO</a> / <a href="https://docs.m5stack.com/zh_CN/core/gray">Gray</a>)</strong><br>
<img src="../assets/imu/hosts/products/basic-v2-7.webp" alt="Core (Basic / M5GO / Gray) catalog product photograph" width="220"><br>
ACCEL: <strong>Varies</strong><br>
GYRO: <strong>Varies</strong><br>
MAG: <strong>Varies</strong><br>
<small>Basic: no ACCEL/GYRO/MAG. Gray: MPU6886 + BMM150. M5GO: MPU6886 + BMM150 originally; no MAG since v2.6. Earlier chips vary; see product history.</small><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/Core2_v1.3">Core2</a></strong><br>
<img src="../assets/imu/hosts/products/core2-v1-3.webp" alt="Core2 catalog product photograph" width="220"><br>
ACCEL: <strong>Yes</strong> · MPU6886 / BMI270<br>
GYRO: <strong>Yes</strong> · MPU6886 / BMI270<br>
MAG: <strong>No</strong><br>
<small>Core2 and v1.1: MPU6886. v1.3: BMI270. Photograph shows v1.3.</small><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/CoreS3">CoreS3</a></strong><br>
<img src="../assets/imu/hosts/generated/cores3-imu-sample.svg" alt="CoreS3 ACCEL and MAG axes with GYRO rotation arrows" width="220"><br>
ACCEL: <strong>Yes</strong> · BMI270<br>
GYRO: <strong>Yes</strong> · BMI270<br>
MAG: <strong>Yes</strong> · BMM150<br>
<small>Includes CoreS3-Lite with the same sensors. CoreS3SE is a separate board.</small><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/fire_v2.7">Fire</a></strong><br>
<img src="../assets/imu/hosts/products/fire-v2-7.webp" alt="Fire catalog product photograph" width="220"><br>
ACCEL: <strong>Yes</strong> · MPU6886<br>
GYRO: <strong>Yes</strong> · MPU6886<br>
MAG: <strong>Varies</strong><br>
<small>v2.6 / v2.7: MPU6886, no MAG. Original Fire: MPU6886 or SH200Q + BMM150; earlier MPU9250. Photograph shows v2.7.</small><br>
</td>
</tr>
<tr>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/tough">Tough</a></strong><br>
<img src="../assets/imu/hosts/products/tough.webp" alt="Tough catalog product photograph" width="220"><br>
ACCEL: <strong>Pending</strong><br>
GYRO: <strong>Pending</strong><br>
MAG: <strong>No</strong><br>
<small>IMU pending: selector lists MPU6886; product specifications and pin map omit it.</small><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/ToughC5">ToughC5</a></strong><br>
<p><em>Catalog image pending</em></p>
ACCEL: <strong>No</strong><br>
GYRO: <strong>No</strong><br>
MAG: <strong>No</strong><br>
<small>Product specifications available; catalog image pending.</small><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/StackChan_Core">StackChan</a></strong><br>
<img src="../assets/imu/hosts/products/stackchan-core.webp" alt="StackChan catalog product photograph" width="220"><br>
ACCEL: <strong>Yes</strong> · BMI270<br>
GYRO: <strong>Yes</strong> · BMI270<br>
MAG: <strong>Yes</strong> · BMM150<br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/M5CoreS3%20SE">CoreS3SE</a></strong><br>
<img src="../assets/imu/hosts/products/cores3-se.webp" alt="CoreS3SE catalog product photograph" width="220"><br>
ACCEL: <strong>No</strong><br>
GYRO: <strong>No</strong><br>
MAG: <strong>No</strong><br>
<small>Official CoreS3 comparison explicitly excludes IMU and MAG.</small><br>
</td>
</tr>
</table>


### Paper

<table>
<tr>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/coreink">CoreInk</a></strong><br>
<img src="../assets/imu/hosts/products/coreink.webp" alt="CoreInk catalog product photograph" width="220"><br>
ACCEL: <strong>No</strong><br>
GYRO: <strong>No</strong><br>
MAG: <strong>No</strong><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/m5paper_v1.1">Paper</a></strong><br>
<img src="../assets/imu/hosts/products/paper-v1-1.webp" alt="Paper catalog product photograph" width="220"><br>
ACCEL: <strong>No</strong><br>
GYRO: <strong>No</strong><br>
MAG: <strong>No</strong><br>
<small>Includes Paper v1.1. Photograph shows v1.1.</small><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/PaperS3">PaperS3</a></strong><br>
<img src="../assets/imu/hosts/products/papers3.webp" alt="PaperS3 catalog product photograph" width="220"><br>
ACCEL: <strong>Yes</strong> · BMI270<br>
GYRO: <strong>Yes</strong> · BMI270<br>
MAG: <strong>No</strong><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/PaperColor">PaperColor</a></strong><br>
<img src="../assets/imu/hosts/products/papercolor.webp" alt="PaperColor catalog product photograph" width="220"><br>
ACCEL: <strong>No</strong><br>
GYRO: <strong>No</strong><br>
MAG: <strong>No</strong><br>
</td>
</tr>
<tr>
<td width="25%" align="center" valign="top">
<strong>PaperDIY</strong><br>
<p><em>Catalog image pending</em></p>
ACCEL: <strong>Pending</strong><br>
GYRO: <strong>Pending</strong><br>
MAG: <strong>Pending</strong><br>
<small>No matching catalog card; public kit routes did not provide verifiable specifications.</small><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/PaperMono">PaperMono</a></strong><br>
<img src="../assets/imu/hosts/products/papermono.webp" alt="PaperMono catalog product photograph" width="220"><br>
ACCEL: <strong>Yes</strong> · BMI270<br>
GYRO: <strong>Yes</strong> · BMI270<br>
MAG: <strong>No</strong><br>
<small>Includes PaperMono-Lite; both have BMI270.</small><br>
</td>
<td width="25%"></td>
<td width="25%"></td>
</tr>
</table>


### Stick

<table>
<tr>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/m5stickc">StickC</a></strong><br>
<img src="../assets/imu/hosts/products/stickc.webp" alt="StickC catalog product photograph" width="220"><br>
ACCEL: <strong>Yes</strong> · MPU6886<br>
GYRO: <strong>Yes</strong> · MPU6886<br>
MAG: <strong>No</strong><br>
<small>Earlier revisions use SH200Q.</small><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/m5stickc_plus">StickC-Plus</a></strong><br>
<img src="../assets/imu/hosts/products/stickc-plus.webp" alt="StickC-Plus catalog product photograph" width="220"><br>
ACCEL: <strong>Yes</strong> · MPU6886<br>
GYRO: <strong>Yes</strong> · MPU6886<br>
MAG: <strong>No</strong><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/M5StickC%20PLUS2">StickC-Plus2</a></strong><br>
<img src="../assets/imu/hosts/products/stickc-plus2.webp" alt="StickC-Plus2 catalog product photograph" width="220"><br>
ACCEL: <strong>Yes</strong> · MPU6886<br>
GYRO: <strong>Yes</strong> · MPU6886<br>
MAG: <strong>No</strong><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/StickS3">StickS3</a></strong><br>
<img src="../assets/imu/hosts/products/sticks3.webp" alt="StickS3 catalog product photograph" width="220"><br>
ACCEL: <strong>Yes</strong> · BMI270<br>
GYRO: <strong>Yes</strong> · BMI270<br>
MAG: <strong>No</strong><br>
</td>
</tr>
</table>


### Cardputer

<table>
<tr>
<td width="50%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/Cardputer%20V1.1">Cardputer</a></strong><br>
<img src="../assets/imu/hosts/products/cardputer-v1-1.webp" alt="Cardputer catalog product photograph" width="440"><br>
ACCEL: <strong>No</strong><br>
GYRO: <strong>No</strong><br>
MAG: <strong>No</strong><br>
<small>Includes v1.1; neither version has an IMU. Cardputer-Adv is a separate board.</small><br>
</td>
<td width="50%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/Cardputer-Adv">Cardputer-Adv</a></strong><br>
<img src="../assets/imu/hosts/products/cardputer-adv.webp" alt="Cardputer-Adv catalog product photograph" width="440"><br>
ACCEL: <strong>Yes</strong> · BMI270<br>
GYRO: <strong>Yes</strong> · BMI270<br>
MAG: <strong>No</strong><br>
</td>
</tr>
</table>


### Others

<table>
<tr>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/Tab5">Tab5</a></strong><br>
<img src="../assets/imu/hosts/products/tab5.webp" alt="Tab5 catalog product photograph" width="220"><br>
ACCEL: <strong>Yes</strong> · BMI270<br>
GYRO: <strong>Yes</strong> · BMI270<br>
MAG: <strong>No</strong><br>
</td>
<td width="25%" align="center" valign="top">
<strong>Tab5X</strong><br>
<p><em>Catalog image pending</em></p>
ACCEL: <strong>Pending</strong><br>
GYRO: <strong>Pending</strong><br>
MAG: <strong>Pending</strong><br>
<small>Official catalog image and sensor specification pending.</small><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/Air_Quality_v1.1">Air Quality</a></strong><br>
<img src="../assets/imu/hosts/products/air-quality-v1-1.webp" alt="Air Quality catalog product photograph" width="220"><br>
ACCEL: <strong>No</strong><br>
GYRO: <strong>No</strong><br>
MAG: <strong>No</strong><br>
<small>Includes v1.1. Photograph shows v1.1.</small><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/M5Dial%20V1.1">Dial</a></strong><br>
<img src="../assets/imu/hosts/products/dial-v1-1.webp" alt="Dial catalog product photograph" width="220"><br>
ACCEL: <strong>No</strong><br>
GYRO: <strong>No</strong><br>
MAG: <strong>No</strong><br>
<small>Includes v1.1. Photograph shows v1.1.</small><br>
</td>
</tr>
<tr>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/DinMeter_v1.1">DinMeter</a></strong><br>
<img src="../assets/imu/hosts/products/dinmeter-v1-1.webp" alt="DinMeter catalog product photograph" width="220"><br>
ACCEL: <strong>No</strong><br>
GYRO: <strong>No</strong><br>
MAG: <strong>No</strong><br>
<small>Includes v1.1. Photograph shows v1.1.</small><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/StamPLC">StamPLC</a></strong><br>
<img src="../assets/imu/hosts/products/stamplc.webp" alt="StamPLC catalog product photograph" width="220"><br>
ACCEL: <strong>No</strong><br>
GYRO: <strong>No</strong><br>
MAG: <strong>No</strong><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/station_bat">Station</a></strong><br>
<img src="../assets/imu/hosts/products/station-bat.webp" alt="Station catalog product photograph" width="220"><br>
ACCEL: <strong>Varies</strong><br>
GYRO: <strong>Varies</strong><br>
MAG: <strong>No</strong><br>
<small>Station-Bat: MPU6886 ACCEL/GYRO. Station-485: no ACCEL/GYRO. Neither has MAG. Photograph shows Station-Bat.</small><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/StopWatch">StopWatch</a></strong><br>
<img src="../assets/imu/hosts/products/stopwatch.webp" alt="StopWatch catalog product photograph" width="220"><br>
ACCEL: <strong>Yes</strong> · BMI270<br>
GYRO: <strong>Yes</strong> · BMI270<br>
MAG: <strong>No</strong><br>
</td>
</tr>
<tr>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/unit/Unit_C6L">Unit C6L</a></strong><br>
<img src="../assets/imu/hosts/products/unit-c6l.webp" alt="Unit C6L catalog product photograph" width="220"><br>
ACCEL: <strong>No</strong><br>
GYRO: <strong>No</strong><br>
MAG: <strong>No</strong><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/chain/Chain_Captain">Chain Captain</a></strong><br>
<p><em>Catalog image pending</em></p>
ACCEL: <strong>Yes</strong> · BMI270<br>
GYRO: <strong>Yes</strong> · BMI270<br>
MAG: <strong>Yes</strong> · BMM150<br>
<small>Preliminary official product description; catalog image pending.</small><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/Arduino_Nesso_N1">Arduino Nesso N1</a></strong><br>
<img src="../assets/imu/hosts/products/arduino-nesso-n1.jpg" alt="Arduino Nesso N1 catalog product photograph" width="220"><br>
ACCEL: <strong>Yes</strong> · BMI270<br>
GYRO: <strong>Yes</strong> · BMI270<br>
MAG: <strong>No</strong><br>
</td>
<td width="25%" align="center" valign="top">
<strong><a href="https://docs.m5stack.com/zh_CN/core/VA%20Meter">VAMeter</a></strong><br>
<img src="../assets/imu/hosts/products/vameter.webp" alt="VAMeter catalog product photograph" width="220"><br>
ACCEL: <strong>No</strong><br>
GYRO: <strong>No</strong><br>
MAG: <strong>No</strong><br>
</td>
</tr>
<tr>
<td width="25%" align="center" valign="top">
<strong>CoreP4X</strong><br>
<p><em>Catalog image pending</em></p>
ACCEL: <strong>Pending</strong><br>
GYRO: <strong>Pending</strong><br>
MAG: <strong>Pending</strong><br>
<small>Official catalog image and sensor specification pending.</small><br>
</td>
<td width="25%"></td>
<td width="25%"></td>
<td width="25%"></td>
</tr>
</table>


## Evidence notes

- **Tough:** the official Core selector lists MPU6886, but the product page's
  specifications and pin map omit it. ACCEL/GYRO remain Pending.
- **Station-Bat:** features, pin map and selector identify MPU6886; its
  specifications spell the part MPU6686. Station-485's mention of MPU6886
  describes the Bat model, not an IMU fitted to Station-485.
- **Missing images:** ToughC5, PaperDIY, Tab5X, Chain Captain and CoreP4X remain
  in the board list without substituting another host's photograph.

[IMU API](../api/imu.md) · [CoreS3 sensors](cores3-imu.md) ·
[IMU axis test](../guides/imu-axis-test.md) · [Device index](README.md)
