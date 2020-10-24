#include <iostream>
#include <vector>
#include "Sensors/Compressor.h"
#include "Sensors/Light.h"
#include "Mediator/Mediator.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#define COMPRESSOR_NAME "Компрессор"
#define LIGHT_NAME "Прожектор"
#define CO2_NAME "CO2"
#define FEEDER_NAME "Кормушка"
#define DOSER_NAME "Дозатор"

void callback(Compressor param) {
    std::cout << "It works with Compressor " << param.getState() << std::endl;
}

int main() {
    std::vector<Sensor> devices;
    Mediator<Compressor> medCom;
    medCom.Register("3", callback);
    auto compressor = Compressor(medCom, COMPRESSOR_NAME,
                                 "Compressor",
                                 7, 10, 23, 11, 24, true, true);
    auto light = Light(LIGHT_NAME,
                       "Прожектор", 1, 9, 0, 18, 0, true, true);
    devices.push_back(light);
    devices.push_back(compressor);
    std::cout << "Air pin is " << +compressor.getPin() << std::endl;
    std::cout << "Air enabled is " << compressor.getEnabled() << std::endl;
    std::cout << "Light pin is " << +light.getPin() << std::endl;

    compressor.set(!true);
}

#pragma clang diagnostic pop