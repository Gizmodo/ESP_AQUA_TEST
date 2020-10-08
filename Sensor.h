//
// Created by user on 07.10.2020.
//

#ifndef FACTORYMETHOD_SENSOR_H
#define FACTORYMETHOD_SENSOR_H

#include <string>
#include <cstring>
#include "Subject.h"
#include  <algorithm>

class Sensor : public Subject {
private:
    std::vector<Observer *> observers; // observers
    float temp = 0.0f;
    float humidity = 0.0f;
    float pressure = 0.0f;
public:
    void registerObserver(Observer *observer) override;

    void removeObserver(Observer *observer) override;

    void notifyObservers() override;

    /**
    * Set the new state of the weather station
    * @param temp new temperature
    * @param humidity new humidity
    * @param pressure new pressure
    */
    void setState(float temp, float humidity, float pressure);

//----------------------------------------------
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

void Sensor::registerObserver(Observer *observer) {
    observers.push_back(observer);
}

void Sensor::removeObserver(Observer *observer) {
    // find the observer
    auto iterator = std::find(observers.begin(), observers.end(), observer);

    if (iterator != observers.end()) { // observer found
        observers.erase(iterator); // remove the observer
    }
}

void Sensor::notifyObservers() {
    for (Observer *observer:observers) {
        observer->update(temp, humidity, pressure);
    }
}

void Sensor::setState(float temp, float humidity, float pressure) {
    this->temp = temp;
    this->humidity = humidity;
    this->pressure = pressure;
    notifyObservers();
}

class Lamp : public Sensor, public Observer {
private:
    uint8_t newPin;
public:
    Lamp(const char *name, SensorType type, uint8_t pin) : Sensor(name, type, pin) {}
void update(float temp, float humidity, float pressure) override;
    void setNewPin(uint8_t value) {
        newPin = value;
    }

    uint8_t getNewPin() { return newPin; }

    ~Lamp() = default;;
};

void Lamp::update(float temp, float humidity, float pressure) {
// print the changed values
    std::cout << "---Client () Data---\tTemperature: " << temp
              << "\tHumidity: " << humidity
              << "\tPressure: " << pressure
              << std::endl;
}


#endif //FACTORYMETHOD_SENSOR_H
