#ifndef FACTORYMETHOD_FEEDER_H
#define FACTORYMETHOD_FEEDER_H

#include <utility>

#include "AbstractSensor.h"

class Feeder : public AbstractSensor {
public:
    Feeder(const char *name,
           std::string nameString,
           uint8_t pin,
           uint8_t hourOn,
           uint8_t minuteOn,
           bool enabled,
           bool state) :
            AbstractSensor(name, AbstractSensor::feeder, std::move(nameString),
                           pin, hourOn, minuteOn,
                           enabled, state) {};

    ~Feeder() = default;
};

#endif //FACTORYMETHOD_FEEDER_H
