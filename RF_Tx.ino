#include <RF24.h>
#include <SPI.h>

RF24 radio(7, 8);
const byte address[6] = "00001";

float value[2];

void setup() {
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
  radio.setRetries(15, 15);
  radio.setPALevel(RF24_PA_MAX);
  radio.openWritingPipe(address);
}

void loop() {
  value[0] = 6.9;
  value[1] = 7.3;

  radio.write(&value, sizeof(value));
  delay(200);
}
