#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#ifndef FACTORYMETHOD_FIRSTCLIENT_H
#define FACTORYMETHOD_FIRSTCLIENT_H

#include <string>
#include "Mediator2.h"

class FirstClient {
private:
    Mediator2<std::string> mediator;

public:
    FirstClient();

    explicit FirstClient(Mediator2<std::string> mediator);

    ~FirstClient();

    static void Notify(std::string message);

    void SendMessages();
};

#endif //FACTORYMETHOD_FIRSTCLIENT_H

#pragma clang diagnostic pop