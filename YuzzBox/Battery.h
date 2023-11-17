#ifndef BATTERY_H
#define BATTERY_H
#include <Arduino.h>
#include "Subject.h"
#include "Observer.h"
#include "CurrentSensor.h"
#include "SoftwareSerial.h"

class Battery : public Subject, public Observer {
private:
    byte rxPin;
    byte txPin;
    SoftwareSerial* swSer;
    CurrentSensor* currentSensor;
    bool connectionState;
    int state; // {-1:disconected, 0:charging, 1:discharging}

public:
    Battery(SoftwareSerial* swSer, CurrentSensor* currentSensor);
    int pullState();
    bool pushState(int mode);
    int getState();
    void update(Subject* subject);
};

#endif //BATTERY_H