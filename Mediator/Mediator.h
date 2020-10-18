#ifndef FACTORYMETHOD_MEDIATOR_H
#define FACTORYMETHOD_MEDIATOR_H
class BaseComponent;
class Mediator {
public:
    virtual void Notify(BaseComponent *sender, std::string event) const = 0;
};

#endif //FACTORYMETHOD_MEDIATOR_H
