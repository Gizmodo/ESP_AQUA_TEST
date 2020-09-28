cmake_minimum_required(VERSION 3.17)
project(FactoryMethod)

set(CMAKE_CXX_STANDARD 17)

add_executable(FactoryMethod main.cpp IDevice.h Compressor.h Lamp.h Factory.h ConcreteLamp.h ConcreteCompressor.h)