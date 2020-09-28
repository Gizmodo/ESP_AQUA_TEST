//
// Created by user on 27.09.2020.
//

#ifndef FACTORYMETHOD_COMPRESSOR_H
#define FACTORYMETHOD_COMPRESSOR_H


#include "IDevice.h"

class Compressor : public IDevice {
public:
    std::string Operation() const override {
        return "{Result of the Compressor}";
    }
};


#endif //FACTORYMETHOD_COMPRESSOR_H
