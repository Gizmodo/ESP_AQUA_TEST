#ifndef FACTORYMETHOD_FLOW_H
#define FACTORYMETHOD_FLOW_H

#include "Sensor.h"

class Flow : public Sensor {
private:
    Mediator<Flow> mMediator;
public:
    Flow(Mediator<Flow> mediator, const char *name,
         std::string nameString,
         uint8_t pin,
         uint8_t hourOn,
         uint8_t minuteOn,
         uint8_t hourOff,
         uint8_t minuteOff,
         bool enabled,
         bool state) :
            Sensor(name, Sensor::flow, std::move(nameString),
                   pin, hourOn, minuteOn,
                   hourOff, minuteOff,
                   enabled, state) {
        mMediator = mediator;
    };

    void setHourOn(uint8_t hour) {
        hourOn(hour);
    }

    void set(bool value) {
        this->setState(value);
        setHourOn(3);
        mMediator.Send("flow", *this);
    }

    void state(bool state) {
        this->setState(state);
        mMediator.Send("flow", *this);
    }

    ~Flow() = default;
};

#endif //FACTORYMETHOD_FLOW_H
