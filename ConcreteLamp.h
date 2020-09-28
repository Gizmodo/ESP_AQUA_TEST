//
// Created by user on 27.09.2020.
//

#ifndef FACTORYMETHOD_CONCRETELAMP_H
#define FACTORYMETHOD_CONCRETELAMP_H


#include "Factory.h"
#include "Compressor.h"
#include "Lamp.h"

class ConcreteLamp : public Factory {
public:
    IDevice *FactoryMethod() const override {
        return new Lamp();
    }
};


#endif //FACTORYMETHOD_CONCRETELAMP_H
