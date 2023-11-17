#include "PowerRelay.h"

// Constructor
PowerRelay::PowerRelay(byte _outputPin, Battery* _battery) : outputPin(_outputPin), battery(_battery) {
  pinMode(outputPin, OUTPUT);
  setState(true);
}

// Methods
bool PowerRelay::getState() {
    return state;
}

void PowerRelay::setState(bool newState) {
    state = newState;
    if(state == false) {
      digitalWrite(outputPin, LOW);
    } else {
      digitalWrite(outputPin, HIGH);
    }
}

void PowerRelay::update(Subject* subject){
  int batteryState = battery->getState();
  if (batteryState == 1){
    setState(false);
  } else if (lastBatteryState == -1 && batteryState == -1){
    setState(true);
  } else if (batteryState == 0){
    setState(true);
  }
  lastBatteryState = batteryState;
}