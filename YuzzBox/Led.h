#ifndef LED_H
#define LED_H

#include "Observer.h"
#include "Battery.h"
#include <Arduino.h>

class Led: public Observer {
  public:
    Led(uint8_t, Battery*);
    void setState(uint8_t state);
    uint8_t getState();
    virtual void update(Subject* subject);

  private:
    uint8_t _outputPin;
    uint8_t _state;
    Battery* _subject;
};

#endif //LED_H