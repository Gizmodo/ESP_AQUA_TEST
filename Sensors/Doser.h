#ifndef FACTORYMETHOD_DOSER_H
#define FACTORYMETHOD_DOSER_H

#include <utility>

#include "Sensor.h"

class Doser : public Sensor {
private:
    uint8_t _pin_m0;
    uint8_t _pin_m1;
    uint8_t _pin_m2;
    uint8_t _pin_sleep;
    uint8_t _pin_step;
    uint8_t _pin_dir;
    uint8_t _pin_enable;
    uint8_t _steps;
    uint8_t _volume;
    uint8_t _index;
public:
    Doser(const char *name,
          std::string nameString,
          uint8_t pin,
          uint8_t hourOn,
          uint8_t minuteOn,
          bool enabled,
          bool state,
          uint8_t pin_m0,
          uint8_t pin_m1,
          uint8_t pin_m2,
          uint8_t pin_sleep,
          uint8_t pin_step,
          uint8_t pin_dir,
          uint8_t pin_enable,
          uint8_t steps,
          uint8_t volume,
          uint8_t index
    ) :
            Sensor(name, Sensor::doser, std::move(nameString),
                   pin, hourOn, minuteOn,
                   enabled, state),
            _pin_m0(pin_m0),
            _pin_m1(pin_m1),
            _pin_m2(pin_m2),
            _pin_sleep(pin_sleep),
            _pin_step(pin_step),
            _pin_dir(pin_dir),
            _pin_enable(pin_enable),
            _steps(steps),
            _volume(volume),
            _index(index) {};

    ~Doser() = default;
};

#endif //FACTORYMETHOD_DOSER_H
