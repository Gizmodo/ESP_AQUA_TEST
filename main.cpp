#include <iostream>
#include <array>
#include  <charconv>
#include <memory>
#include <string>
#include <stdarg.h>
#include <cstring>
#include <stdexcept>
#include <random>
#include <cassert>
#include <ctime>
#include "Mediator/Mediator.h"
#include "Sensors/Sensor.h"
#include "Sensors/Scheduler.h"
#include "Sensors/Doser.h"

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

#define LIGHTS_COUNT (6)             // Кол-во прожекторов
#define DEVICE_COUNT (LIGHTS_COUNT)  // Кол-во всех устройств (нужно для Alarm'ов)
#define DOSERS_COUNT (3)

void clb1(Sensor param) {
    std::cout << "clb1 " << param.getName() << std::endl;
}

void callbackCompressor(Sensor device) {
    std::cout << "Вызван callback для устройства " << device.getName() << std::endl;
}

void callbackFlow(Sensor device) { std::cout << "Вызван callback для устройства " << device.getName() << std::endl; }

void callbackPump(Sensor device) { std::cout << "Вызван callback для устройства " << device.getName() << std::endl; }

void callbackLight(Sensor device) { std::cout << "Вызван callback для устройства " << device.getName() << std::endl; }

void callbackFeeder(Sensor device) { std::cout << "Вызван callback для устройства " << device.getName() << std::endl; }

void callbackCO2(Sensor device) { std::cout << "Вызван callback для устройства " << device.getName() << std::endl; }

void callbackHeater(Sensor device) { std::cout << "Вызван callback для устройства " << device.getName() << std::endl; }

void callbackDoser(Sensor device) { std::cout << "Вызван callback для устройства " << device.getName() << std::endl; }

void callbackDoser(Doser device) {
    std::cout << "Вызван callback для устройства " << device.getName() << std::endl;
}

//----------------Медиаторы----------------
//Компрессор
Mediator<Sensor> medCompressor;
//Помпа течения
Mediator<Sensor> medFlow;
//Помпа подъемная
Mediator<Sensor> medPump;
//Прожекторы
Mediator<Sensor> medLight;
//Кормушка
//TODO сменить класс Sensor на определенный класс данного устройства
Mediator<Sensor> medFeeder;
//CO2
Mediator<Sensor> medCO2;
//Нагреватель
Mediator<Sensor> medHeater;
//Дозатор
//TODO сменить класс Sensor на определенный класс данного устройства
Mediator<Sensor> medDoser;
Mediator<Doser> medDoser_;
//-----------------------------------------
//Датчики
Sensor *compressor;
Sensor *flow;
Sensor *pump;
std::array<Sensor, LIGHTS_COUNT> lights{
        Sensor(medLight, "1", Sensor::light),
        Sensor(medLight, "2", Sensor::light),
        Sensor(medLight, "3", Sensor::light),
        Sensor(medLight, "4", Sensor::light),
        Sensor(medLight, "5", Sensor::light),
        Sensor(medLight, "6", Sensor::light)
};
std::array<Doser, DOSERS_COUNT> dosers{Doser(medDoser_, "Fe", Doser::Fe),
                                       Doser(medDoser_, "K", Doser::K),
                                       Doser(medDoser_, "NP", Doser::NP)};
std::array<Scheduler, DEVICE_COUNT> schedules;
std::array<Scheduler, 3> schedulesDosers;

Sensor *feeder;
Sensor *co2;
Sensor *heater;
Sensor *doser;
struct PRNG {
    std::mt19937 engine;
};
PRNG generator;

void initGenerator(PRNG &generator) {
    // Создаём псевдо-устройство для получения случайного зерна.
    std::random_device device;
    // Получаем случайное зерно последовательности
    generator.engine.seed(device());
}

// Генерирует целое число в диапазоне [minValue, maxValue)
unsigned random(PRNG &generator, unsigned minValue, unsigned maxValue) {
    // Проверяем корректность аргументов
    assert(minValue < maxValue);

    // Создаём распределение
    std::uniform_int_distribution<unsigned> distribution(minValue, maxValue);

    // Вычисляем псевдослучайное число: вызовем распределение как функцию,
    //  передав генератор произвольных целых чисел как аргумент.
    return distribution(generator.engine);
}

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
    medDoser_.Register("1", callbackDoser);
}

void printSheduler() {
    std::cout << "Schedules doesnt print alarms ID" << std::endl;
    std::cout << "--------------Печать расписаний--------------" << std::endl;
    time_t now1 = time(nullptr);
    tm *ptm = std::localtime(&now1);
    char buffer[100];
    strftime(buffer, 100, "Internal time is %d.%m.%Y %H:%M:%S", ptm);
    std::cout << buffer << std::endl;

    for (auto item : schedules) {
        std::cout << "Sensor name ";
        std::cout << item.getDevice()->getName().c_str() << std::endl;
        auto alarmNowOn = item.getOn();
        auto alarmNowOff = item.getOff();
        std::cout << "alarmNowOn " << +alarmNowOn << std::endl;
        std::cout << "alarmNowOff " << +alarmNowOff << std::endl;
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    }
}

void initDevices() {
    compressor = new Sensor(medCompressor, "Компрессор", Sensor::compressor);
    flow = new Sensor(medFlow, "Помпа течения", Sensor::flow);
    pump = new Sensor(medPump, "Помпа подъёмная", Sensor::pump);
    feeder = new Sensor(medFeeder, "Кормушка", Sensor::feeder);
    co2 = new Sensor(medCO2, "CO2", Sensor::co2);
    heater = new Sensor(medHeater, "Нагреватель", Sensor::heater);
    doser = new Sensor(medDoser, "Дозатор", Sensor::doser);
    for (int i = 0; i < LIGHTS_COUNT; ++i) {
        std::string buffer = string_format("%s %d", "Прожектор", i + 1);
        std::string on = string_format("%02d:%02d",
                                       random(generator, 0, 24),
                                       random(generator, 0, 59));
        std::string off = string_format("%02d:%02d",
                                        random(generator, 0, 24),
                                        random(generator, 0, 59));

        auto item = lights.at(i);
        item.setName(buffer);
        item.setPin(random(generator, 0, 20));
        item.setTimeOff(off.c_str());
        item.setTimeOn(on.c_str());
        item.setMMediator(medLight);
        lights.at(i) = item;
        schedules.at(i).setDevice(&(lights.at(i)));
        schedules.at(i).setOn(10);
        schedules.at(i).setOff(20);
    }
    for (int i = 0; i < DOSERS_COUNT; ++i) {
        std::string buffer = string_format("%s %d", "Дозатор", i + 1);
        std::string on = string_format("%02d:%02d",
                                       random(generator, 0, 24),
                                       random(generator, 0, 59));
        std::string off = string_format("%02d:%02d",
                                        random(generator, 0, 24),
                                        random(generator, 0, 59));

        auto item = dosers.at(i);
        item.setName(buffer);
        item.setSteps(random(generator,10,50));
        item.setMediator(medDoser_);
        dosers.at(i) = item;
        schedulesDosers.at(i).setDevice(&(dosers.at(i)));

    }
    std::cout << "Schedules should print alarms ID" << std::endl;
    for (auto item: schedules) {
        auto dev = item.getDevice();
        std::cout << dev->printDevice() << std::endl;
        std::cout << "Schedules>>>>>>>>>>>>>>>";
        std::cout << "sensor name ";
        std::cout << item.getDevice()->getName().c_str() << std::endl;
        auto alarmNowOn = item.getOn();
        auto alarmNowOff = item.getOff();
        std::cout << "alarmNowOn " << +alarmNowOn << std::endl;
        std::cout << "alarmNowOff " << +alarmNowOff << std::endl;
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
        //Doser* dos = static_cast<Doser *>(item.getDevice());

    }
    std::cout<<"TEST"<<std::endl;
    for (auto item: schedulesDosers) {
        auto dos =static_cast<Doser *>(item.getDevice());
        std::cout<<dos->getName()<<" steps "<<+dos->getSteps()<<std::endl;
    }

}

void printDevice(Sensor *device) {
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
    /*  for(auto light:lights){
          printDevice(light);
      }*/
}

void setupDevice(Sensor *device) {
    const char *on = "7:28";
    const char *off = "17:43";
    uint8_t _pin = 12;
    bool state = false;
    bool enabled = false;
    std::string objectID = "qwdqwdefew";
    device->setTimeOn(on);
    device->setTimeOff(off);
    device->setPin(_pin);
    device->setState(state);
    device->setEnabled(enabled);
    device->setObjectID(objectID);
}

//присвоение параметров всем прожекторам
void setupDevice(Sensor *device, const std::string &response) {

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

    initGenerator(generator);

    initMediators();
    initDevices();
    std::cout << "-------------------------BEGIN " << std::endl;
    for (int i = 0; i < LIGHTS_COUNT; ++i) {
        auto item = lights.at(i);
        std::cout << "After " << item.getName() << " PIN " << +item.getPin() << std::endl;
    }
    std::cout << "-------------------------END " << std::endl;
    setupDevices();
    printSheduler();
    flow->callMediator();
    std::cout<<dosers.at(1).getEnabled()<<std::endl;
    dosers.at(1).setEnable(true);
    std::cout<<dosers.at(1).getEnabled()<<std::endl;
    //printAllDevices();
/*
    std::vector<Sensor> devices;

    Mediator<Sensor> mediator1;
    mediator1.Register("1", clb1);
    Sensor s1 = Sensor(mediator1, FLOW_NAME, Sensor::flow,
                         1, 2, 3, 4, 5, true, false);
    s1.callMediator();

    Mediator<Sensor> mediator2;
    mediator2.Register("1", clb1);*/
    /*  Sensor s2 = Sensor(mediator2, DOSER_NAME, Sensor::flow,
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