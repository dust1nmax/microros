#include <Arduino.h>



void setup() {
  Serial.begin(115200);
}

void loop() {
  if(Serial.available())
  {
    String str = Serial.readString();
  
    Serial.printf(" i recrive %s\n", str);
  
  }
  // put your main code here, to run repeatedly:
}


