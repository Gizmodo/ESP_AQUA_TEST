
#include <iostream>
#include "SecondClient.h"

SecondClient::SecondClient() = default;

SecondClient::SecondClient(Mediator2<std::string> mediator) {
    this->mediator = mediator;
}

SecondClient::~SecondClient() = default;

void SecondClient::Notify(std::string message) {
    std::cout << "[SecondClient]"
              << '\t'
              << message
              << std::endl;
}

void SecondClient::SendMessages() {
    mediator.Send("1", "message 1 from SecondClient");
    mediator.Send("2", "message 2 from SecondClient");
}