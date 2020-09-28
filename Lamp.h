//
// Created by user on 27.09.2020.
//

#ifndef FACTORYMETHOD_LAMP_H
#define FACTORYMETHOD_LAMP_H


#include "IDevice.h"

class Lamp : public IDevice {
private:
    uint8_t _hourOn;
public:
    void setHour(uint8_t value) {
        this->_hourOn = value;
    }

    uint8_t getHour() {
        return this->_hourOn;
    }

    std::string Operation() const override {
        return "{Result of the Lamp}";
    }
};


#endif //FACTORYMETHOD_LAMP_H
