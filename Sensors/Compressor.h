#ifndef FACTORYMETHOD_COMPRESSOR_H
#define FACTORYMETHOD_COMPRESSOR_H

#include <utility>

#include "Sensor.h"
#include "../Mediator/Mediator.h"

class Compressor : public Sensor {
private:
    Mediator<Compressor> m_mediator;
public:
    Compressor(Mediator<Compressor> mediator, const char *name,
               std::string nameString,
               uint8_t pin,
               uint8_t hourOn,
               uint8_t minuteOn,
               uint8_t hourOff,
               uint8_t minuteOff,
               bool enabled,
               bool state) :
            Sensor(name, Sensor::compressor, std::move(nameString),
                   pin, hourOn, minuteOn,
                   hourOff, minuteOff,
                   enabled, state) {
        m_mediator = mediator;
    };

    void set(bool value) {
        this->setState(value);
        m_mediator.Send("3", *this);
    }

    ~Compressor() = default;
};

#endif //FACTORYMETHOD_COMPRESSOR_H
