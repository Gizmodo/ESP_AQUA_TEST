//
// Created by user on 27.09.2020.
//

#ifndef FACTORYMETHOD_IDEVICE_H
#define FACTORYMETHOD_IDEVICE_H


#include <string>

class IDevice {
private: uint8_t _hourOn;
public:
    virtual ~IDevice() {}
    virtual std::string Operation() const = 0;
};


#endif //FACTORYMETHOD_IDEVICE_H
