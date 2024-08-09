#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.printf("hello world setup\n");
}

void loop() {
  Serial.printf("hello world loop\n");
  delay(1000);
}

