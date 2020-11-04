#ifndef FACTORYMETHOD_SENSOR_H
#define FACTORYMETHOD_SENSOR_H

#include <string>
#include <utility>
#include "../Mediator/Mediator.h"

#define UNDEFINED (-1)

class Sensor {
public:
    enum SensorType {
        unknown, light, compressor, co2, doser, feeder, flow, pump, heater
    };

    ~Sensor() = default;

    Sensor(Mediator<Sensor> mediator, std::string name, SensorType type) {
        mMediator = mediator;
        _type = type;
        _name = name;
    }

    Sensor(Mediator<Sensor> mediator, const char *name, SensorType type,
           uint8_t pin,
           uint8_t hourOn, uint8_t minuteOn,
           uint8_t hourOff, uint8_t minuteOff,
           bool enabled, bool state) {
        mMediator = mediator;
        _type = type;
        //strcpy(_name, name);
        _pin = pin;
        _hourOn = hourOn;
        _minuteOn = minuteOn;
        _hourOff = hourOff;
        _minuteOff = minuteOff;
        _enabled = enabled;
        _state = state;
    }

    void setStateNotify(bool state) {
        this->_state = state;
        mMediator.Send("1", *this);
    }

    void setEnabledNotify(bool enabled) {
        this->_enabled = enabled;
        mMediator.Send("1", *this);
    }

    void callMediator() {
        mMediator.Send("1", *this);
    }

    void setTimeOn(const char *time) {
        splitTime(time, _hourOn, _minuteOn);
    }

    void setTimeOff(const char *time) {
        splitTime(time, _hourOff, _minuteOff);
    }

    void setPin(uint8_t pin) {
        _pin = pin;
    }

    void setState(bool b) {
        _state = b;
    }

    void setEnabled(bool b) {
        _enabled = b;
    }

    void setObjectID(std::string objectID) {
        this->_objectID = objectID;
    }

    void setName(std::string name) {
        this->_name = name;
    }

    std::string getName() {
        return this->_name;
    }

    uint8_t getHourOn() {
        return this->_hourOn;
    }

    uint8_t getHourOff() {
        return this->_hourOff;
    }

    uint8_t getMinuteOn() {
        return this->_minuteOn;
    }

    uint8_t getMinuteOff() {
        return this->_minuteOff;
    }

    uint8_t getPin() {
        return this->_pin;
    }

    bool getState() {
        return this->_state;
    }

    bool getEnabled() {
        return this->_enabled;
    }

    std::string getObjectID() {
        return this->_objectID;
    }

    std::string printDevice() {
        std::string buffer;
        buffer = this->_name + "\n" +
                 " [ON] " + std::to_string(this->_hourOn) + ":"
                 + std::to_string(this->_minuteOn) +
                 " [OFF] " + std::to_string(this->_hourOff) + ":"
                 + std::to_string(this->_minuteOff) + "\n" +
                 " [STATE] " + std::to_string(this->_state) +
                 " [ENABLED] " + std::to_string(this->_enabled) +
                 " [PIN] " + std::to_string(this->_pin) +
                 " [OBJECTID] " + this->_objectID + "\n";
        return buffer;
    }

private:
    std::string _name;
    std::string _objectID;
    SensorType _type = unknown;
    uint8_t _pin = UNDEFINED;
    uint8_t _hourOn = UNDEFINED;
    uint8_t _minuteOn = UNDEFINED;
    uint8_t _hourOff = UNDEFINED;
    uint8_t _minuteOff = UNDEFINED;
    bool _state = false;
    bool _enabled = false;
    Mediator<Sensor> mMediator;

    void splitTime(const char *payload, uint8_t &hour, uint8_t &minute) {
        char buffer[10];
        strcpy(buffer, payload);
        char *split = strtok(buffer, ":");
        char *pEnd;
        hour = strtol(split, &pEnd, 10);
        split = strtok(nullptr, ":");
        minute = strtol(split, &pEnd, 10);
    }
};

#endif //FACTORYMETHOD_SENSOR_H