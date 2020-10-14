#include <iostream>
#include <vector>
#include "Sensor.h"
#include "Lamp.h"
#include "Compressor.h"
#include "Sensors/CompressorNew.h"

#define _PH2_NAME "CalRX"
#define _COMPRESSOR_NAME "Компрессор"

int main() {
    std::vector<Sensor> vec;
    const char *c = "123";
    auto s = Lamp(_PH2_NAME, Sensor::co2, 8);
    s.setNewPin(32);
    std::cout << "NePin = " << +s.getNewPin() << std::endl;
    vec.push_back(s);
    auto compressor = Compressor(_PH2_NAME, Sensor::doser, 0);
    vec.push_back(compressor);

    ////////////////////NEW////////////
    /*
     * const char *name,
                  SensorType type,
                  std::string nameString,
                  uint8_t pin,
                  uint8_t hourOn,
                  uint8_t minuteOn,
                  uint8_t hourOff,
                  uint8_t minuteOff,
                  bool enabled,
                  bool state
     */
    auto air = CompressorNew(_COMPRESSOR_NAME,
                             AbstractSensor::compressor,
                             "Compressor",
                             7, 10, 23, 11, 24, true, true);
    std::cout << "Air pin is " << +air.getPin() << std::endl;
}
