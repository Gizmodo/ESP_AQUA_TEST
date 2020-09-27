cmake_minimum_required(VERSION 3.17)
project(FactoryMethod)

set(CMAKE_CXX_STANDARD 17)

add_executable(FactoryMethod main.cpp Product.cpp Product.h ConcreteProduct1.cpp ConcreteProduct1.h ConcreteProduct2.cpp ConcreteProduct2.h Creator.cpp Creator.h ConcreteCreator1.cpp ConcreteCreator1.h ConcreteCreator2.cpp ConcreteCreator2.h)