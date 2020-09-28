#include <iostream>
#include "Factory.h"
#include "ConcreteLamp.h"
#include "ConcreteCompressor.h"

void ClientCode(const Factory &creator) {
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
              << creator.SomeOperation() << std::endl;
}


int main() {
    std::cout << "App: Launched with the ConcreteLamp.\n";
    Factory *creator = new ConcreteLamp();
    ClientCode(*creator);
    std::cout << std::endl;
    std::cout << "App: Launched with the ConcreteCompressor.\n";
    Factory *creator2 = new ConcreteCompressor();
    ClientCode(*creator2);

    delete creator;
    delete creator2;
    return 0;
}
