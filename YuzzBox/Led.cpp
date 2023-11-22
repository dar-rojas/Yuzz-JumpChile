#include "Led.h"

// Constructor
Led::Led(uint8_t o, Battery* s)
: _outputPin(o), _subject(s){
  pinMode(_outputPin, OUTPUT);
  _state = false;
}

//Methods
void Led::setState(uint8_t state){
  _state = state;
  digitalWrite(_outputPin, _state);
}

uint8_t Led::getState(){
  return _state;
}

void Led::update(Subject* subject){
  int subjectState = _subject->getState();
  if (subjectState == 1){
    setState(1);
  } else {
    setState(0);
  }
  
}