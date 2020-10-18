#ifndef FACTORYMETHOD_COMPONENT1_H
#define FACTORYMETHOD_COMPONENT1_H

#include <iostream>
#include "BaseComponent.h"

class Component1 : public BaseComponent {
public :
    void DoA() {
        std::cout << "Component 1 does A." << std::endl;
        this->mediator_->Notify(this, "A");
    }

    void DoB() {
        std::cout << "Component 1 does B." << std::endl;
        this->mediator_->Notify(this, "B");
    }
};

#endif //FACTORYMETHOD_COMPONENT1_H
