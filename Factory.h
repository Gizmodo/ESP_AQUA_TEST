//
// Created by user on 27.09.2020.
//

#ifndef FACTORYMETHOD_FACTORY_H
#define FACTORYMETHOD_FACTORY_H


#include "IDevice.h"

class Factory {
public:
    virtual ~Factory() {};

    virtual IDevice *FactoryMethod() const = 0;

    std::string SomeOperation() const {
        // Вызываем фабричный метод, чтобы получить объект-продукт.
        IDevice *product = this->FactoryMethod();
        // Далее, работаем с этим продуктом.
        std::string result = "Factory: The same creator's code has just worked with " + product->Operation();
        delete product;
        return result;
    }
};


#endif //FACTORYMETHOD_FACTORY_H
