#ifndef FACTORYMETHOD_COMPRESSORNEW_H
#define FACTORYMETHOD_COMPRESSORNEW_H

#include "../AbstractSensor.h"

class CompressorNew : public AbstractSensor {
public:
    CompressorNew(const char *name,
                  SensorType type,
                  std::string nameString,
                  uint8_t pin,
                  uint8_t hourOn,
                  uint8_t minuteOn,
                  uint8_t hourOff,
                  uint8_t minuteOff,
                  bool enabled,
                  bool state) :
            AbstractSensor(name, type, nameString,
                           pin, hourOn, minuteOn,
                           hourOff, minuteOff,
                           enabled, state) {};

    ~CompressorNew() = default;
};

#endif //FACTORYMETHOD_COMPRESSORNEW_H
