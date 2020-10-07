//
// Created by user on 07.10.2020.
//

#ifndef FACTORYMETHOD_SENSOR_H
#define FACTORYMETHOD_SENSOR_H

#include <string>
#include <cstring>

class Sensor {
public:
    enum SensorType {
        lamp, compressor, co2, doser
    };

    ~Sensor() {};

    Sensor(const char *name, SensorType type, uint8_t pin) {
        strcpy(_name, name);
        _type = type;
        _pin = pin;
    }

    Sensor(const char *name, SensorType type,
           std::string str, uint8_t pin,
           uint8_t hourOn, uint8_t minuteOn,
           uint8_t hourOff, uint8_t minuteOff,
           bool enabled, bool state
    ) {
        _type = type;
        strcpy(_name, name);
        _str = str;
        _pin = pin;
        _hourOn = hourOn;
        _minuteOn = minuteOn;
        _hourOff = hourOff;
        _minuteOff = minuteOff;
        _enabled = enabled;
        _state = state;
    }

    uint8_t getPin() {
        return _pin;
    }

    char *getNameChar() {
        return _name;
    };

protected:
    std::string _str;
    char _name[8];
    SensorType _type;
    uint8_t _pin;
    uint8_t _hourOn;
    uint8_t _minuteOn;
    uint8_t _hourOff;
    uint8_t _minuteOff;
    bool _state;
    bool _enabled;
};

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


#endif //FACTORYMETHOD_SENSOR_H
