//
// Created by IT on 08.09.2020.
//

#ifndef AQUACONTROLLER_ESP8266_SCHEDULER_H
#define AQUACONTROLLER_ESP8266_SCHEDULER_H

#include "Sensor.h"
#include "Doser.h"

typedef uint8_t AlarmID_t;

class Scheduler {
private:
    Sensor *_device = nullptr;
    //Doser *_doser = nullptr;
    AlarmID_t _on;
    AlarmID_t _off;

public:
    ~Scheduler();

    Scheduler();

    Sensor *getDevice();

    void setDevice(Sensor *device);

    AlarmID_t getOn();

    void setOn(AlarmID_t on);

    AlarmID_t getOff();

    void setOff(AlarmID_t off);
};

#endif  // AQUACONTROLLER_ESP8266_SCHEDULER_H
