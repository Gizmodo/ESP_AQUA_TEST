//
// Created by IT on 14.10.2020.
//

#ifndef FACTORYMETHOD_COMPRESSOR_H
#define FACTORYMETHOD_COMPRESSOR_H

#include "Sensor.h"

class Compressor : public Sensor {
public:
    Compressor(const char *name, SensorType type, uint8_t pin) : Sensor(name, type, pin) {};

    ~Compressor() = default;;

};

#endif //FACTORYMETHOD_COMPRESSOR_H
