#ifndef FACTORYMETHOD_COMPONENT2_H
#define FACTORYMETHOD_COMPONENT2_H

#include <iostream>
#include "BaseComponent.h"

class Component2 : public BaseComponent {
public :
    void DoC() {
        std::cout << "Component 2 does C." << std::endl;
        this->mediator_->Notify(this, "C");
    }

    void DoD() {
        std::cout << "Component 2 does D." << std::endl;
        this->mediator_->Notify(this, "D");
    }
};

#endif //FACTORYMETHOD_COMPONENT2_H
