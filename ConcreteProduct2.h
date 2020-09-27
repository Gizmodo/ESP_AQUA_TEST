//
// Created by user on 27.09.2020.
//

#ifndef FACTORYMETHOD_CONCRETEPRODUCT2_H
#define FACTORYMETHOD_CONCRETEPRODUCT2_H


#include "Product.h"

class ConcreteProduct2 : public Product {
public:
    std::string Operation() const override {
        return "{Result of the ConcreteProduct2}";
    }
};


#endif //FACTORYMETHOD_CONCRETEPRODUCT2_H
