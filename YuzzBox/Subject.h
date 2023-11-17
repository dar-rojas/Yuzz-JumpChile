// Observer design pattern interface
#ifndef POWER_RELAY_H
#define POWER_RELAY_H

#include <Arduino.h>
#include "Observer.h"
#include <vector>

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify();
};

#endif 