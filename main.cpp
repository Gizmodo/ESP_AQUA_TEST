#include <iostream>
#include <vector>
#include  <charconv>
#include <memory>
#include <string>
#include <stdexcept>
#include "Sensors/Compressor.h"
#include "Sensors/Light.h"
#include "Mediator/Mediator.h"
#include "Sensors/Flow.h"
#include "Sensors/sensor2.h"

std::string string_format(const std::string fmt_str, ...) {
    int final_n, n = ((int) fmt_str.size()) * 2; /* Reserve two times as much as the length of the fmt_str */
    std::unique_ptr<char[]> formatted;
    va_list ap;
    while (1) {
        formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
        strcpy(&formatted[0], fmt_str.c_str());
        va_start(ap, fmt_str);
        final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
        va_end(ap);
        if (final_n < 0 || final_n >= n)
            n += abs(final_n - n + 1);
        else
            break;
    }
    return std::string(formatted.get());
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedMacroInspection"

#define LIGHTS_COUNT (6)

void callback(Compressor param) {
    std::cout << "It works with Compressor " << param.getState() << std::endl;
}

void flowCallback(Flow param) {
    std::cout << "Обратный вызов по устройству: " << param.getState() << std::endl;
}

void clb1(sensor2 param) {
    std::cout << "clb1 " << param.getName() << std::endl;
}

void callbackCompressor(sensor2 device) {
    std::cout << "Вызван callback для устройства " << device.getName() << std::endl;
}

void callbackFlow(sensor2 device) { std::cout << "Вызван callback для устройства " << device.getName() << std::endl; }

void callbackPump(sensor2 device) { std::cout << "Вызван callback для устройства " << device.getName() << std::endl; }

void callbackLight(sensor2 device) { std::cout << "Вызван callback для устройства " << device.getName() << std::endl; }

void callbackFeeder(sensor2 device) { std::cout << "Вызван callback для устройства " << device.getName() << std::endl; }

void callbackCO2(sensor2 device) { std::cout << "Вызван callback для устройства " << device.getName() << std::endl; }

void callbackHeater(sensor2 device) { std::cout << "Вызван callback для устройства " << device.getName() << std::endl; }

void callbackDoser(sensor2 device) { std::cout << "Вызван callback для устройства " << device.getName() << std::endl; }

//----------------Медиаторы----------------
//Компрессор
Mediator<sensor2> medCompressor;
//Помпа течения
Mediator<sensor2> medFlow;
//Помпа подъемная
Mediator<sensor2> medPump;
//Прожекторы
Mediator<sensor2> medLight;
//Кормушка
//TODO сменить класс sensor2 на определенный класс данного устройства
Mediator<sensor2> medFeeder;
//CO2
Mediator<sensor2> medCO2;
//Нагреватель
Mediator<sensor2> medHeater;
//Дозатор
//TODO сменить класс sensor2 на определенный класс данного устройства
Mediator<sensor2> medDoser;

//-----------------------------------------
//Датчики
sensor2 *compressor;
sensor2 *flow;
sensor2 *pump;
std::vector<sensor2 *> lights;
sensor2 *feeder;
sensor2 *co2;
sensor2 *heater;
sensor2 *doser;

//-----------------------------------------
void initMediators() {
    medCompressor.Register("1", callbackCompressor);
    medFlow.Register("1", callbackFlow);
    medPump.Register("1", callbackPump);
    medLight.Register("1", callbackLight);
    medFeeder.Register("1", callbackFeeder);
    medCO2.Register("1", callbackCO2);
    medHeater.Register("1", callbackHeater);
    medDoser.Register("1", callbackDoser);
}

void initDevices() {
    compressor = new sensor2(medCompressor, "Компрессор", sensor2::compressor);
    flow = new sensor2(medFlow, "Помпа течения", sensor2::flow);
    pump = new sensor2(medPump, "Помпа подъёмная", sensor2::pump);
    feeder = new sensor2(medFeeder, "Кормушка", sensor2::feeder);
    co2 = new sensor2(medCO2, "CO2", sensor2::co2);
    heater = new sensor2(medHeater, "Нагреватель", sensor2::heater);
    doser = new sensor2(medDoser, "Дозатор", sensor2::doser);
    for (int i = 0; i < LIGHTS_COUNT; ++i) {
        std::string buffer;
        buffer = string_format("%s %d", "Прожектор", i + 1);
        lights.push_back(new sensor2(medLight, buffer, sensor2::light));
    }
/*
    compressor = new sensor2(medCompressor, FLOW_NAME, sensor2::flow, "1",
                             1, 2, 3, 4, 5, true, false);
    compressor->callMediator();
    */
}

void printDevice(sensor2 *device) {
    std::cout << device->printDevice() << std::endl;
}

void printAllDevices() {
    printDevice(compressor);
    printDevice(flow);
    printDevice(pump);
    printDevice(feeder);
    printDevice(co2);
    printDevice(heater);
    printDevice(doser);
    for(auto light:lights){
        printDevice(light);
    }
}

void setupDevice(sensor2 *device) {
    const char *on = "7:28";
    const char *off = "17:43";
    uint8_t _pin = 12;
    bool state = false;
    bool enabled = false;
    std::string objectID="qwdqwdefew";
    device->setTimeOn(on);
    device->setTimeOff(off);
    device->setPin(_pin);
    device->setState(state);
    device->setEnabled(enabled);
    device->setObjectID(objectID);
};
//присвоение параметров всем прожекторам
void setupDevice(sensor2* device,const std::string& response){

}

void setupDevices() {
    setupDevice(compressor);
    setupDevice(flow);
    setupDevice(pump);
    setupDevice(feeder);
    setupDevice(co2);
    setupDevice(heater);
    setupDevice(doser);
    //setupDevice(*light);
}

int main() {
    initMediators();
    initDevices();
    setupDevices();
    flow->callMediator();
    //printAllDevices();
/*
    std::vector<Sensor> devices;

    Mediator<sensor2> mediator1;
    mediator1.Register("1", clb1);
    sensor2 s1 = sensor2(mediator1, FLOW_NAME, sensor2::flow,
                         1, 2, 3, 4, 5, true, false);
    s1.callMediator();

    Mediator<sensor2> mediator2;
    mediator2.Register("1", clb1);*/
    /*  sensor2 s2 = sensor2(mediator2, DOSER_NAME, sensor2::flow,
                           1, 2, 3, 4, 5, true, false);
      s2.callMediator();
      s2.callMediator();*/
//TODO


/*

    Mediator<Flow> mediatorFlow;
    mediatorFlow.Register("flow", flowCallback);
    auto flow = Flow(mediatorFlow, FLOW_NAME, "Помпа течения", 6, 7, 0, 22, 0, true, true);
    flow.setHourOn(3);
    Mediator<Compressor> medCom;
    medCom.Register("3", callback);
    auto compressor = Compressor(medCom, FLOW_NAME,
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
    flow.set(!true);
*/

}

#pragma clang diagnostic pop