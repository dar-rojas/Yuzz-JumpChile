#ifndef CURRENT_SENSOR_H
#define CURRENT_SENSOR_H

#include <Arduino.h>
#include "Subject.h"
// Class for ACS712 current sensor
// Acts as a subject in the implemented Observer design pattern.
class CurrentSensor : public Subject {
private:
    byte inputPin;
    float current;
    bool charging;

public:
    CurrentSensor(byte inputPin_);
    void read();
    bool isCharging();
};

#endif // CURRENT_SENSOR_H