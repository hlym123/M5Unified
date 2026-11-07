#include "LTR553_Class.hpp"

namespace m5
{
    bool LTR553_Class::begin(I2C_Class* i2c) {
        if (i2c != nullptr) {
            _i2c = i2c;
            i2c->begin();
        }

        uint8_t partID = readRegister8(0x86);
        uint8_t mfrID = readRegister8(0x87);
        if (partID != 0x92 || mfrID != 0x05) {
            return false;
        }

        // software reset
        // bool ret = writeRegister8(0x80, 0x02);

        // active als
        // bool ret = bitOn(0x80, 0);
        bool ret = writeRegister8(0x80, 0x01);
        // active ps
        ret = ret && writeRegister8(0x81, 0x03);
        return ret;
    }

    bool LTR553_Class::sleep() {
        // deactivate als
        bool ret = writeRegister8(0x80, 0x00);
        // deactivate ps
        ret = ret && writeRegister8(0x81, 0x00);
        return ret;
    }

    bool LTR553_Class::softwareReset() {
        return writeRegister8(0x80, 0x02);
    }

    void LTR553_Class::setLightSensorMode(uint8_t mode)
    {
        uint8_t value = readRegister8(0x80);
        value &= (~0x01);
        value |= mode;
        writeRegister8(0x80, value);
    }

    void LTR553_Class::setProximitySensorMode(uint8_t mode)
    {
        uint8_t value = readRegister8(0x81);
        value &= (~0x03);
        value |= mode;
        writeRegister8(0x81, value);
    }

    void LTR553_Class::setLightSensorGain(uint8_t gain)
    {
        uint8_t value = readRegister8(0x80);
        value &= (~0x1C);
        value |= gain;
        writeRegister8(0x80, value);
    }

    void LTR553_Class::setProximitySensorGain(uint8_t gain)
    {
        uint8_t value = readRegister8(0x81);
        value &= ~(0x0C);
        value |= gain;
        writeRegister8(0x81, value);
    }

    void LTR553_Class::setProximitySensorLEDPulsePeriod(uint8_t period)
    {
        uint8_t value = readRegister8(0x82);
        value &= ~(0xE0);
        value |= period;
        writeRegister8(0x82, value);
    }

    void LTR553_Class::setProximitySensorLEDPulseDuty(uint8_t duty)
    {
        uint8_t value = readRegister8(0x82);
        value &= ~(0x18);
        value |= duty;
        writeRegister8(0x82, value);
    }

    void LTR553_Class::setProximitySensorLEDCurrent(uint8_t current)
    {
        uint8_t value = readRegister8(0x82);
        value &= ~(0x07);
        value |= current;
        writeRegister8(0x82, value);
    }

    void LTR553_Class::setLightSensorMeasurementRate(uint8_t rate)
    {
        uint8_t value = readRegister8(0x85);
        value &= ~(0x07);
        value |= rate;
        writeRegister8(0x85, value);
    }

    void LTR553_Class::setProximitySensorMeasurementRate(uint8_t rate)
    {
        writeRegister8(0x84, rate);
    }

    uint16_t LTR553_Class::getLightSensorData()
    {
        uint8_t buffer[4] = {0};
        uint16_t result;

        readRegister(0x88, &buffer[0], 4);

        uint16_t ch1_value, ch0_value;
        ch1_value = (buffer[1] << 8) | buffer[0];
        ch0_value = (buffer[3] << 8) | buffer[2];
        result = (ch1_value + ch0_value) >> 1;
        return result;
    }

    uint16_t LTR553_Class::getProximitySensorData()
    {
        uint8_t buffer[2];
        uint16_t result;

        readRegister(0x8D, &buffer[0], 2);
        buffer[0] &= 0xFF;
        buffer[1] &= 0x07;
        result = (buffer[1] << 8) | buffer[0];
        return result;
    }

}