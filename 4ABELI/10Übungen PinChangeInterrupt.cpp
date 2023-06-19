//--------------------------------------------------
/*
Valuable information: 
  This determines which button is set as interrupt
  -   PCICR = 0b00000010; // Bit 1 goes from PCINT8 to PCINT15
      PCMSK1 = 0b00000010; for the first button / PCMSK1 = 0b00000100; for the second button / PCMSK1 = 0b00001000; for the third button / PCMSK1 = 0b00001110; for all buttons, etc.

  -  sei() allows the code to be interrupted
  -  cli() disallows the code to be interrupted

  -  ISR(PCINT1_vect) is the interrupt function itself
      within there's an if ((PINC & 0b00000010) == 0) statement, which asks whether a certain button has been pressed (Important if different buttons do different things)
  
*/
//--------------------------------------------------
// Taste abfragen 1

#include <Arduino.h>

volatile unsigned int InterruptCount = 0;

ISR(PCINT1_vect)
{
  InterruptCount++;
  if ((PINC & 0b00000010) == 0){
    digitalWrite(13,LOW);
    Serial.println(InterruptCount); // increments mostly by 2 because of the nature of pin change interrupt
  }
  else digitalWrite(13,HIGH);
}

void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  PCICR = 0b00000010;
  PCMSK1 = 0b00000010;
  sei();
}

void loop() {
  while (1)
  {
    cli();
    digitalWrite(12,LOW);
    sei();
    delay(1000);
    cli();
    digitalWrite(12,HIGH);
    sei();
    delay(1000);
  }
}
//--------------------------------------------------
// Taste abfragen 2
#include <Arduino.h>

int LED[] = {13, 12, 11, 10};

volatile unsigned int InterruptCount = 0;

ISR(PCINT1_vect)
{
  InterruptCount++;
  Serial.println(InterruptCount); // increments mostly by 2 because of the nature of pin change interrupt
  if ((PINC & 0b00000010) == 0){
    digitalWrite(LED[0],LOW);
  }
  else digitalWrite(LED[0],HIGH);
  if ((PINC & 0b00000100) == 0){
    digitalWrite(LED[1], LOW);
  }
  else digitalWrite(LED[1], HIGH);
  if ((PINC & 0b00001000) == 0){
    digitalWrite(LED[2], LOW);
  }
  else digitalWrite(LED[2], HIGH);

}

void setup() {
  Serial.begin(115200);
  size_t n = sizeof(LED) / sizeof(LED[0]);

  for (int i = 0; i<n; i++){
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], HIGH);
  }

  PCICR = 0b00000010;
  PCMSK1 = 0b00001110;
  sei();
}

void loop() {
  while (1)
  {
    cli();
    digitalWrite(LED[3],LOW);
    sei();
    delay(1000);
    cli();
    digitalWrite(LED[3],HIGH);
    sei();
    delay(1000);
  }
}
//--------------------------------------------------
// Freie Leitung A5 abfragen
#include <Arduino.h>

#define Interrupt5 A5

volatile unsigned int InterruptCount = 0;

ISR(PCINT1_vect)
{
  InterruptCount++;
}

void setup() {
  Serial.begin(115200);

  pinMode(Interrupt5, INPUT);

  PCICR = 0b00000010;
  PCMSK1 = 0b00100000;
  sei();
}

void loop() {
  while (1)
  {
    cli();
    Serial.println(InterruptCount);
    InterruptCount = 0;
    sei();
    delay(1000);

  }
}
//--------------------------------------------------
