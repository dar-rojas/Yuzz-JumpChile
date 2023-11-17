#ifndef LED_RING_H
#define LED_RING_H

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class LedRing {
  public:
    LedRing(Adafruit_NeoPixel* ring);
    void chargingAnimation(int wait);
    void dischargingAnimation(int wait);
    
  private:
    Adafruit_NeoPixel* ring;
    uint16_t size;
    int position;
};

#endif