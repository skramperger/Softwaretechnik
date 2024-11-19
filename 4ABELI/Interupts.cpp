#include <Arduino.h>

volatile unsigned int counter = 0;
volatile unsigned char ucPINC = 0xFF;

ISR(PCINT1_vect)
{
  counter++;
  ucPINC &= PINC;

}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println(PCICR, BIN);
  Serial.println(PCMSK2, BIN);
  Serial.println(PCMSK1, BIN);
  Serial.println(PCMSK0, BIN);
  PCICR = 0b00000010; //oder = 2
  PCMSK1 = 0b00001110; // oder = 14
  sei();
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  while (digitalRead(A1) == HIGH);
  while (1)
  {
    ucPINC = 0xFF;
    digitalWrite(10, LOW);
    delay(1000);
    if ((ucPINC &  0b00000100) == 0) break;
    Serial.println(counter);
    Serial.println(ucPINC, BIN);
    digitalWrite(10, HIGH);
    delay(1000);
    if ((ucPINC & 0b00000100) == 0) break;
    Serial.println(ucPINC, BIN);
  }
  digitalWrite(10, HIGH);

}
