#include <iostream>
#include <vector>
#include "Sensors/Compressor.h"
#include "Sensors/Light.h"
#include "Mediator/Component1.h"
#include "Mediator/Component2.h"
#include "Mediator/ConcreteMediator.h"
#include "Mediator2/Mediator2.h"
#include "Mediator2/FirstClient.h"
#include "Mediator2/SecondClient.h"

#define _COMPRESSOR_NAME "Компрессор"
#define _LIGHT_NAME "Прожектор"
#define _CO2_NAME "CO2"
#define _FEEDER_NAME "Кормушка"
#define _DOSER_NAME "Дозатор"

void callback(std::string message) {
    std::cout << "Callback" << std::endl;
}

void callback(AbstractSensor param) {
    std::cout << "Callback -> " << +param.getPin() << std::endl;
}

int main() {
    std::vector<AbstractSensor> devices;
    auto compressor = Compressor(_COMPRESSOR_NAME,
                          "Compressor",
                          7, 10, 23, 11, 24, true, true);
    auto light = Light(_LIGHT_NAME,
                       "Прожектор", 1, 9, 0, 18, 0, true, true);
    devices.push_back(light);
    devices.push_back(compressor);
    std::cout << "Air pin is " << +compressor.getPin() << std::endl;
    std::cout << "Air enabled is " << compressor.getEnabled() << std::endl;
    std::cout << "Light pin is " << +light.getPin() << std::endl;

    Component1 *c1 = new Component1();
    Component2 *c2 = new Component2();
    ConcreteMediator *mediator = new ConcreteMediator(c1, c2);
    std::cout << "Client triggers operation A.\n";
    c1->DoA();
    std::cout << "\n";
    std::cout << "Client triggers operation D.\n";
    c2->DoD();

    delete c1;
    delete c2;
    delete mediator;
////////////////////////////////////////////////////
    std::cout << "----------------New mediator----------------" << std::endl;
    Mediator2<std::string> med;
    med.Register("1", callback);
    med.Register("2", SecondClient::Notify);

    /*FirstClient fc(med);
    SecondClient sc(med);
    fc.SendMessages();
    sc.SendMessages();
*/
}
