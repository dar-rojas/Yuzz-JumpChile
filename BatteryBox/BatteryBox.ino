#include <SoftwareSerial.h>


SoftwareSerial serialOutput(9,8);

void setup() {
 serialOutput.begin(9600);
 Serial.begin(9600);
}

void loop() {
  if(serialOutput){
    serialOutput.write(1);
  }
  
  
}
