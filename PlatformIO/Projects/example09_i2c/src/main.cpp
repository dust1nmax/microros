#include <Arduino.h>
#include "Wire.h"

uint8_t cmd_ssd1315[] = {0xae, 0x00, 0x10, 0x40, 0x81, 0xcf, 0xa1, 0xc8, 0xa6, 0xa8,
                         0x3f, 0xd3, 0x00, 0xd5, 0x80, 0xd9, 0xf1, 0xda, 0x12, 0xdb,
                         0x40, 0x20, 0x00, 0x8d, 0x14, 0xa4, 0xa6, 0xaf};

void setup() {
  // put your setup code here, to run once:
  Wire.begin(18,19);
  Wire.beginTransmission(0x3C);
  for (int i = 0; i < 28; i++)
  {
    Wire.write(cmd_ssd1315[i]);
  }
  Wire.endTransmission();
}

void loop() {
  // put your main code here, to run repeatedly:
}

