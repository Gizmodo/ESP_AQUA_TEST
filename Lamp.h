//
// Created by IT on 14.10.2020.
//

#ifndef FACTORYMETHOD_LAMP_H
#define FACTORYMETHOD_LAMP_H

class Sensor;

class Lamp : public Sensor {
private:
    uint8_t newPin;
public:
    Lamp(const char *name, SensorType type, uint8_t pin) : Sensor(name, type, pin) {}

    void setNewPin(uint8_t value) {
        newPin = value;
    }

    uint8_t getNewPin() { return newPin; }

    ~Lamp() = default;;
};

#include "Sensor.h"

#endif //FACTORYMETHOD_LAMP_H
