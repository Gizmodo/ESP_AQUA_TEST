#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "modernize-use-nodiscard"

#ifndef FACTORYMETHOD_SENSOR_H
#define FACTORYMETHOD_SENSOR_H

#include <string>
#include <utility>
#include "../Mediator/Mediator.h"

class Sensor {
public:
    enum SensorType {
        light, compressor, co2, doser, feeder
    };

    ~Sensor() = default;;

    Sensor(const char *name, SensorType type,
           std::string nameString, uint8_t pin,
           uint8_t hourOn, uint8_t minuteOn,
           uint8_t hourOff, uint8_t minuteOff,
           bool enabled, bool state) {
        _type = type;
        strcpy(_name, name);
        _nameString = std::move(nameString);
        _pin = pin;
        _hourOn = hourOn;
        _minuteOn = minuteOn;
        _hourOff = hourOff;
        _minuteOff = minuteOff;
        _enabled = enabled;
        _state = state;
    }

    Sensor(const char *name, SensorType type,
           std::string nameString, uint8_t pin,
           uint8_t hourOn, uint8_t minuteOn,
           bool enabled, bool state) {
        _type = type;
        strcpy(_name, name);
        _nameString = std::move(nameString);
        _pin = pin;
        _hourOn = hourOn;
        _minuteOn = minuteOn;
        _hourOff = -1;
        _minuteOff = -1;
        _enabled = enabled;
        _state = state;
    }

    uint8_t getPin() const {
        return _pin;
    }

    void setPin(uint8_t pin) {
        _pin = pin;
    }

    bool getState() {
        return _state;
    }

    void setState(bool value) {
        _state = value;
    }

    bool getEnabled() {
        return _enabled;
    }

    void setEnabled(bool value) {
        _enabled = value;
    }

private:
    std::string _nameString;
    char _name[8]{};
    SensorType _type;
    uint8_t _pin;
    uint8_t _hourOn;
    uint8_t _minuteOn;
    uint8_t _hourOff;
    uint8_t _minuteOff;
    bool _state;
    bool _enabled;

};

#endif //FACTORYMETHOD_SENSOR_H

#pragma clang diagnostic pop