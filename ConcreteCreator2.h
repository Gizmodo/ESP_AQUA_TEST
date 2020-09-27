//
// Created by user on 27.09.2020.
//

#ifndef FACTORYMETHOD_CONCRETECREATOR2_H
#define FACTORYMETHOD_CONCRETECREATOR2_H


#include "Creator.h"
#include "ConcreteProduct2.h"

class ConcreteCreator2 : public Creator {
public:
    Product *FactoryMethod() const override {
        return new ConcreteProduct2();
    }
};


#endif //FACTORYMETHOD_CONCRETECREATOR2_H
