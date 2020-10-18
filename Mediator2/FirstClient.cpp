//
// Created by IT on 19.10.2020.
//

#include "FirstClient.h"
#include <iostream>

FirstClient::FirstClient() = default;

FirstClient::FirstClient(Mediator2<std::string> mediator) {
    this->mediator = mediator;
}

FirstClient::~FirstClient() = default;

void FirstClient::Notify(std::string message) {
    std::cout << "[FirstClient]"
              << '\t'
              << message
              << std::endl;
}

void FirstClient::SendMessages() {
    mediator.Send("1", "message 1 from FirstClient");
    mediator.Send("2", "message 2 from FirstClient");
}