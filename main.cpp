#include <iostream>
#include <vector>
#include "Sensor.h"
#define _PH2_NAME "CalRX"
int main() {
    std::vector<Sensor> vec;
    const char *c = "123";
    auto s = Lamp(_PH2_NAME, Sensor::co2, 8);
    s.setNewPin(32);
    std::cout<<"NePin = "<<+s.getNewPin()<<std::endl;
    vec.push_back(s);
    s.setState(1,2,3);

}
