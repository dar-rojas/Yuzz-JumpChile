#include "CurrentSensor.h"

// Constructor
CurrentSensor::CurrentSensor(byte inputPin_) : inputPin(inputPin_) {
    pinMode(inputPin, INPUT);
}

//Methods
void CurrentSensor::read() {
    // Read the current value from the sensor
    current = analogRead(inputPin) * (5.0 / 1023.0);
    // Determine if there is something charging
    charging = current < 2.4;
    // Notify observers about the change
    notify();
}

bool CurrentSensor::isCharging() {
    return charging;
}