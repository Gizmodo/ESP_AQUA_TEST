#include "Mediator2.h"
#ifndef FACTORYMETHOD_SECONDCLIENT_H
#define FACTORYMETHOD_SECONDCLIENT_H

#include <string>


class SecondClient {
private:
    Mediator2<std::string> mediator;

public:
    SecondClient();

    explicit SecondClient(Mediator2<std::string> mediator);

    ~SecondClient();

    static void Notify(std::string message);

    void SendMessages();
};

#endif //FACTORYMETHOD_SECONDCLIENT_H
