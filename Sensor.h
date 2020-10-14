#ifndef FACTORYMETHOD_SENSOR_H
#define FACTORYMETHOD_SENSOR_H

#include <string>
#include <cstring>
#include <algorithm>

class Sensor {
public:
    enum SensorType {
        lamp, compressor, co2, doser, feeder
    };
private:
    std::string _nameString;
    char _name[8];
    SensorType _type;
    uint8_t _pin;
    uint8_t _hourOn;
    uint8_t _minuteOn;
    uint8_t _hourOff;
    uint8_t _minuteOff;
    bool _state;
    bool _enabled;
public:

    ~Sensor() {};

    Sensor(const char *name, SensorType type, uint8_t pin) {
        strcpy(_name, name);
        _type = type;
        _pin = pin;
    }

    Sensor(const char *name, SensorType type,
           std::string nameString, uint8_t pin,
           uint8_t hourOn, uint8_t minuteOn,
           uint8_t hourOff, uint8_t minuteOff,
           bool enabled, bool state
    ) {
        _type = type;
        strcpy(_name, name);
        _nameString = nameString;
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


};


#endif //FACTORYMETHOD_SENSOR_H
