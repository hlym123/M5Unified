#ifndef __M5_LTR553_CLASS_H__
#define __M5_LTR553_CLASS_H__

#include "I2C_Class.hpp"

namespace m5
{
    class LTR553_Class : public I2C_Device
    {
    public:
        enum als_mode_t : std::uint8_t
        {
            E_ALS_MODE_STANDBY,
            E_ALS_MODE_ACTIVE,
        };
        enum ps_mode_t : std::uint8_t
        {
            E_PS_MODE_STANDBY = 0x00,
            E_PS_MODE_ACTIVE = 0x10,
        };

        enum als_agin_t : std::uint8_t
        {
            E_ALS_MODE_X1 = 0x00,
            E_ALS_MODE_X2 = 0x04,
            E_ALS_MODE_X4 = 0x08,
            E_ALS_MODE_X8 = 0x0C,
            E_ALS_MODE_X48 = 0x18,
            E_ALS_MODE_X96 = 0x1C,
        };

        enum ps_agin_t : std::uint8_t
        {
            E_ALS_MODE_X16 = 0x00,
            E_ALS_MODE_X32 = 0x08,
            E_ALS_MODE_X64 = 0x0C,
        };

        enum led_period_t : std::uint8_t
        {
            E_LED_PERIOD_30KHZ = 0x00,
            E_LED_PERIOD_40KHZ = 0x20,
            E_LED_PERIOD_50KHZ = 0x40,
            E_LED_PERIOD_60KHZ = 0x60,
            E_LED_PERIOD_70KHZ = 0x80,
            E_LED_PERIOD_80KHZ = 0xA0,
            E_LED_PERIOD_90KHZ = 0xC0,
            E_LED_PERIOD_100KHZ = 0xE0,
        };

        enum led_duty_t : std::uint8_t
        {
            E_LED_DUTY_25 = 0x00,
            E_LED_DUTY_50 = 0x08,
            E_LED_DUTY_75 = 0x10,
            E_LED_DUTY_100 = 0x18,
        };

        enum led_current_t : std::uint8_t
        {
            E_LED_CURRENT_5MA = 0x00,
            E_LED_CURRENT_10MA = 0x01,
            E_LED_CURRENT_20MA = 0x02,
            E_LED_CURRENT_50MA = 0x03,
            E_LED_CURRENT_100MA = 0x04,
        };

        enum als_rate_t : std::uint8_t
        {
            E_ALS_RATE_50MS = 0x00,
            E_ALS_RATE_100MS = 0x01,
            E_ALS_RATE_200MS = 0x02,
            E_ALS_RATE_500MS = 0x03,
            E_ALS_RATE_1000MS = 0x04,
            E_ALS_RATE_2000MS = 0x05,
        };

        enum ps_rate_t : std::uint8_t
        {
            E_PS_RATE_50MS = 0x00,
            E_PS_RATE_70MS = 0x01,
            E_PS_RATE_100MS = 0x02,
            E_PS_RATE_200MS = 0x03,
            E_PS_RATE_500MS = 0x04,
            E_PS_RATE_1000MS = 0x05,
            E_PS_RATE_2000MS = 0x06,
            E_PS_RATE_10MS = 0x08,
        };

        static constexpr std::uint8_t DEFAULT_ADDRESS = 0x23;

        LTR553_Class(
            std::uint8_t i2c_addr = DEFAULT_ADDRESS,
            std::uint32_t freq = 400000,
            I2C_Class *i2c = &In_I2C) : I2C_Device(i2c_addr, freq, i2c)
        {
        }

        ~LTR553_Class() {}

        bool begin(I2C_Class *i2c = nullptr);
        bool sleep();
        bool softwareReset();
        void setLightSensorMode(uint8_t mode);
        void setProximitySensorMode(uint8_t mode);
        void setLightSensorGain(uint8_t gain);
        void setProximitySensorGain(uint8_t gain);
        void setProximitySensorLEDPulsePeriod(uint8_t period);
        void setProximitySensorLEDPulseDuty(uint8_t duty);
        void setProximitySensorLEDCurrent(uint8_t current);

        void setLightSensorMeasurementRate(uint8_t rate);
        void setProximitySensorMeasurementRate(uint8_t rate);

        uint16_t getLightSensorData();
        uint16_t getProximitySensorData();

        bool isEnabled(void) const { return true; }
    };
}

#endif