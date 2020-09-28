//
// Created by user on 27.09.2020.
//

#ifndef FACTORYMETHOD_CONCRETECOMPRESSOR_H
#define FACTORYMETHOD_CONCRETECOMPRESSOR_H


#include "Factory.h"
#include "Lamp.h"

class ConcreteCompressor : public Factory {
public:
    IDevice *FactoryMethod() const override {
        return new Compressor();
    }
};


#endif //FACTORYMETHOD_CONCRETECOMPRESSOR_H
