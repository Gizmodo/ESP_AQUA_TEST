#ifndef FACTORYMETHOD_BASECOMPONENT_H
#define FACTORYMETHOD_BASECOMPONENT_H

#include "Mediator.h"
class BaseComponent {
protected:
    Mediator *mediator_;
public:
    BaseComponent(Mediator *mediator = nullptr) : mediator_(mediator) {}

    void setMediator(Mediator *mediator) {
        this->mediator_ = mediator;
    }
};

#endif //FACTORYMETHOD_BASECOMPONENT_H
