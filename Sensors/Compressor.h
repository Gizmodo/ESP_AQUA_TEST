#ifndef FACTORYMETHOD_COMPRESSOR_H
#define FACTORYMETHOD_COMPRESSOR_H

#include <utility>

#include "AbstractSensor.h"

class Compressor : public AbstractSensor {
public:
    Compressor(const char *name,
               std::string nameString,
               uint8_t pin,
               uint8_t hourOn,
               uint8_t minuteOn,
               uint8_t hourOff,
               uint8_t minuteOff,
               bool enabled,
               bool state) :
            AbstractSensor(name, AbstractSensor::compressor, std::move(nameString),
                           pin, hourOn, minuteOn,
                           hourOff, minuteOff,
                           enabled, state) {
    };

    ~Compressor() = default;
};

#endif //FACTORYMETHOD_COMPRESSOR_H
