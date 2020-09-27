//
// Created by user on 27.09.2020.
//

#ifndef FACTORYMETHOD_PRODUCT_H
#define FACTORYMETHOD_PRODUCT_H


#include <string>

class Product {
public:
    virtual ~Product() {}
    virtual std::string Operation() const = 0;
};


#endif //FACTORYMETHOD_PRODUCT_H
