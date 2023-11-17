#include "Observer.h"
#include "Battery.h"
#include <Arduino.h>
class PowerRelay : public Observer {
private:
    byte outputPin;
    bool state;
    Battery* battery;
    int lastBatteryState;

public:
    PowerRelay(byte outputPin_, Battery* battery_);
    bool getState();
    void setState(bool newState);
    void update(Subject* subject);
};
