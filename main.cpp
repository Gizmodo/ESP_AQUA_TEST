#include <iostream>
#include <vector>
#include "Sensors/Compressor.h"
#include "Sensors/Light.h"
#include "Mediator2/Mediator2.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#define COMPRESSOR_NAME "Компрессор"
#define LIGHT_NAME "Прожектор"
#define CO2_NAME "CO2"
#define FEEDER_NAME "Кормушка"
#define DOSER_NAME "Дозатор"

void callback(std::string message) {
    std::cout << "It works with std::string " << message << std::endl;
}

void callback(AbstractSensor param) {
    std::cout << "It works with AbstractSensor " << param.getState() << std::endl;
}

void callback(Compressor param) {
    std::cout << "It works with Compressor " << param.getState() << std::endl;
}

void callback(uint8_t param) {
    std::cout << "It works uint8_t " << +param << std::endl;
}

int main() {
    std::vector<AbstractSensor> devices;
    auto compressor = Compressor(COMPRESSOR_NAME,
                                 "Compressor",
                                 7, 10, 23, 11, 24, true, true);
    auto light = Light(LIGHT_NAME,
                       "Прожектор", 1, 9, 0, 18, 0, true, true);
    devices.push_back(light);
    devices.push_back(compressor);
    std::cout << "Air pin is " << +compressor.getPin() << std::endl;
    std::cout << "Air enabled is " << compressor.getEnabled() << std::endl;
    std::cout << "Light pin is " << +light.getPin() << std::endl;
    compressor.set(true);
    compressor.set(false);

////////////////////////////////////////////////////
    std::cout << "----------------New mediator----------------" << std::endl;
    Mediator2<AbstractSensor> med;
    //  med.Register("1", callback);
    med.Register("3", callback);
    auto compressor2 = Compressor(med, COMPRESSOR_NAME,
                                  "Compressor",
                                  7, 10, 23, 11, 24, true, true);
    compressor2.setWithMediator(true);
/////////////////////////////////////////////////////////
    std::cout << "----------------New mediatorС----------------" << std::endl;
    Mediator2<Compressor> medCom;
    //  med.Register("1", callback);
    medCom.Register("3", callback);
    auto compressor3 = Compressor(medCom, COMPRESSOR_NAME,
                                  "Compressor",
                                  7, 10, 23, 11, 24, true, true);
    compressor3.setWithMediatorC(true);
}

#pragma clang diagnostic pop