#ifndef FACTORYMETHOD_COMPRESSOR_H
#define FACTORYMETHOD_COMPRESSOR_H

#include <utility>

#include "AbstractSensor.h"
#include "../Mediator/BaseComponent.h"
#include "../Mediator2/Mediator2.h"

class Compressor : public AbstractSensor, public BaseComponent {
private:
//    Mediator2<uint8_t> mediator;
    Mediator2<AbstractSensor> mediator;
//    Mediator2<uint8_t> mediatorUint8t;
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

    Compressor(Mediator2<AbstractSensor> mediator, const char *name,
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
        this->mediator = mediator;
    };


    void set(bool value) {
        this->setState(value);
        //this->mediator_->Notify(this, "stateChange");
        //mediator.Send("1", "param");
    }

    void setWithMediator(bool value) {
        this->setState(value);
        //mediator.Send("3", 9);
        mediator.Send("3", static_cast<AbstractSensor>(*(this)));
    }

    /*
    void set3(bool value) {
        this->setState(value);
        m3.Send("3", static_cast<AbstractSensor>(*(this)));
    }
    */

    ~Compressor() = default;
};

#endif //FACTORYMETHOD_COMPRESSOR_H
