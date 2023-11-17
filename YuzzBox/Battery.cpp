#include "Battery.h"
//Constructor
Battery::Battery(SoftwareSerial* _swSer, CurrentSensor* _currentSensor)
    : swSer(_swSer), currentSensor(_currentSensor){
    // Initialize serial comunication
    swSer->begin(9600);
    Serial.begin(9600);
}

//Methods
int Battery::pullState() {
  // Gets actual battery state {-1:disconected, 0:charging, 1:discharging}
  state = (swSer->available() > 0) ? swSer->read() : -1;
  // Horrible "fix"
  if (state == 48){
    state = 0;
  } else if (state == 49){
    state = 1;
  }
  // Notify observers (if any) about the change in battery state
  notify();
  Serial.println(state);
}

bool Battery::pushState(int newState) {
  // Sends a message to the BatteryBox to change the battery state
  // Return true only if the battery state is synchronized
  if(newState == 1){
    swSer->write(1);
  }else if(newState == 0){
    swSer->write((uint8_t)0);
  }
  
}

int Battery::getState() {
  return state;
}

void Battery::update(Subject* subject) {
    // Update the battery state based on the current reading
    // Batteries are in a discharging state when the YuzzBox is charging a device
    if (currentSensor->isCharging()){
      pushState(1);
    } else {
      pushState(0);
    }
}