//
// Created by user on 08.10.2020.
//

#ifndef FACTORYMETHOD_SUBJECT_H
#define FACTORYMETHOD_SUBJECT_H

#include "Observer.h"

/**
 * Interface for the Subject
 */
class Subject {

    /**
     * Register an observer
     * @param observer the observer object to be registered
     */
    virtual void registerObserver(Observer *observer) = 0;

    /**
     * Unregister an observer
     * @param observer the observer object to be unregistered
     */
    virtual void removeObserver(Observer *observer) = 0;

    /**
     * Notify all the registered observers when a change happens
     */
    virtual void notifyObservers() = 0;
};

#endif //FACTORYMETHOD_SUBJECT_H
