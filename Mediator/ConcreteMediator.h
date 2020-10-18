
#ifndef FACTORYMETHOD_CONCRETEMEDIATOR_H
#define FACTORYMETHOD_CONCRETEMEDIATOR_H

#include "Mediator.h"
#include "Component1.h"
#include "Component2.h"

class ConcreteMediator : public Mediator {
private:
    Component1 *component1_;
    Component2 *component2_;
public:
    ConcreteMediator(Component1 *c1, Component2 *c2) : component1_(c1), component2_(c2) {
        this->component1_->setMediator(this);
        this->component2_->setMediator(this);
    }

    void Notify(BaseComponent *sender, std::string event) const override {
        if (event == "A") {
            std::cout << "Mediator reacts on A and triggers following operations:\n";
            this->component2_->DoC();
        }
        if (event == "D") {
            std::cout << "Mediator reacts on D and triggers following operations:\n";
            this->component1_->DoB();
            this->component2_->DoC();
        }
    }
};

#endif //FACTORYMETHOD_CONCRETEMEDIATOR_H
