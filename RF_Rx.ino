#include <RF24.h>
#include <SPI.h>

RF24 radio(2, 15); //ce,cs pin
const byte address[6] = "00001";

float value[2];

void setup() {
  Serial.begin(115200);
  SPI.begin();
  radio.begin();
  radio.setRetries(15, 15);
  radio.setPALevel(RF24_PA_MAX);
  radio.openReadingPipe(1, address);
  radio.startListening();
}

void loop() {
  if (radio.available())
    while (radio.available()) {
      memset(&value, ' ', sizeof(value));
      radio.read(&value, sizeof(value));
      Serial.print(value[0]);
      Serial.print("\t");
      Serial.print(value[1]);
      Serial.println();
      delay(200);
    }
}
