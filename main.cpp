#include <iostream>
#include <vector>
#include "Sensors/Compressor.h"
#include "Sensors/Light.h"

#define _COMPRESSOR_NAME "Компрессор"
#define _LIGHT_NAME "Прожектор"
#define _CO2_NAME "CO2"
#define _FEEDER_NAME "Кормушка"
#define _DOSER_NAME "Дозатор"

int main() {
    std::vector<AbstractSensor> devices;
    auto air = Compressor(_COMPRESSOR_NAME,
                          "Compressor",
                          7, 10, 23, 11, 24, true, true);
    auto light = Light(_LIGHT_NAME,
                       "Прожектор", 1, 9, 0, 18, 0, true, true);
    devices.push_back(light);
    devices.push_back(air);
    std::cout << "Air pin is " << +air.getPin() << std::endl;
    std::cout << "Air enabled is " << air.getEnabled() << std::endl;
    std::cout << "Light pin is " << +light.getPin() << std::endl;
}
