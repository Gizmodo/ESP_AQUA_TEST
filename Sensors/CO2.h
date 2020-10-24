#ifndef FACTORYMETHOD_CO2_H
#define FACTORYMETHOD_CO2_H

#include <utility>

#include "Sensor.h"

class CO2 : public Sensor {
public:
    CO2(const char *name,
        std::string nameString,
        uint8_t pin,
        uint8_t hourOn,
        uint8_t minuteOn,
        uint8_t hourOff,
        uint8_t minuteOff,
        bool enabled,
        bool state) :
            Sensor(name, Sensor::co2, std::move(nameString),
                   pin, hourOn, minuteOn,
                   hourOff, minuteOff,
                   enabled, state) {};

    ~CO2() = default;
};

#endif //FACTORYMETHOD_CO2_H
