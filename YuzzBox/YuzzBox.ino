#include "Battery.h"
#include "PowerRelay.h"
#include "CurrentSensor.h"
#include "SoftwareSerial.h"
#include "LedRing.h"
#include <Adafruit_NeoPixel.h>

SoftwareSerial swSerial(14,12); // RX and TX
CurrentSensor current_sensor(A0); //Analog pin 0
Battery battery(&swSerial, &current_sensor);
PowerRelay relay(5, &battery); // Relay in pin D1
Adafruit_NeoPixel ring = Adafruit_NeoPixel(16, 4, NEO_GRB + NEO_KHZ800); //D2
LedRing ledRing = LedRing(&ring);

void setup(){
  battery.attach(&relay);
  ring.begin();
}

void loop(){
  // Current and Battery state are update
  current_sensor.read();
  battery.pullState();
  if (current_sensor.isCharging()){
    ledRing.chargingAnimation(50);
  }else{
    ledRing.dischargingAnimation(50);
  }
}