cmake_minimum_required(VERSION 3.17)
project(FactoryMethod)

set(CMAKE_CXX_STANDARD 17)

add_executable(FactoryMethod main.cpp Sensors/AbstractSensor.h Sensors/Compressor.h Sensors/Light.h Sensors/CO2.h Sensors/Doser.h Sensors/Feeder.h Mediator/Mediator.h Mediator/BaseComponent.h Mediator/ConcreteMediator.h Mediator/Component1.h Mediator/Component2.h Mediator2/Mediator2.h Mediator2/FirstClient.cpp Mediator2/FirstClient.h)