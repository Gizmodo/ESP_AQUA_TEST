#ifndef FACTORYMETHOD_LIGHT_H
#define FACTORYMETHOD_LIGHT_H
#include <utility>

#include "Sensor.h"

class Light : public Sensor {
public:
    Light(const char *name,
               std::string nameString,
               uint8_t pin,
               uint8_t hourOn,
               uint8_t minuteOn,
               uint8_t hourOff,
               uint8_t minuteOff,
               bool enabled,
               bool state) :
            Sensor(name, Sensor::light, std::move(nameString),
                   pin, hourOn, minuteOn,
                   hourOff, minuteOff,
                   enabled, state) {};

    ~Light() = default;
};

#endif //FACTORYMETHOD_LIGHT_H
