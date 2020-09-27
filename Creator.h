//
// Created by user on 27.09.2020.
//

#ifndef FACTORYMETHOD_CREATOR_H
#define FACTORYMETHOD_CREATOR_H


#include "Product.h"

class Creator {
public:
    virtual ~Creator() {};

    virtual Product *FactoryMethod() const = 0;

    std::string SomeOperation() const {
        // Вызываем фабричный метод, чтобы получить объект-продукт.
        Product *product = this->FactoryMethod();
        // Далее, работаем с этим продуктом.
        std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
        delete product;
        return result;
    }
};


#endif //FACTORYMETHOD_CREATOR_H
