//
// Created by user on 27.09.2020.
//

#ifndef FACTORYMETHOD_CONCRETEPRODUCT1_H
#define FACTORYMETHOD_CONCRETEPRODUCT1_H


#include "Product.h"

class ConcreteProduct1 : public Product {
public:
    std::string Operation() const override {
        return "{Result of the ConcreteProduct1}";
    }
};


#endif //FACTORYMETHOD_CONCRETEPRODUCT1_H
