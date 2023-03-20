//------------------------------------------------------------------------------------------------
// Lauflicht

#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  DDRB |= 0b00111100;
  PORTB |= 0b00111100;
  DDRC &= ~(0b00001110);
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB &= ~(0b00100000);
  delay(1000);
  PORTB |= 0b00100000;
  PORTB &= ~(0b00010000);
  delay(1000);
  PORTB |= 0b00010000;
  PORTB &= ~(0b00001000);
  delay(1000);
  PORTB |= 0b00001000;
  PORTB &= ~(0b00000100);
  delay(1000);
  PORTB |= 0b00000100;
}

//------------------------------------------------------------------------------------------------
// Lauflicht 2

#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  DDRB |= 0b00111100;
  PORTB |= 0b00111100;
  DDRC &= ~(0b00001110);

}

void loop() {
  // put your main code here, to run repeatedly:
  while ((PINC & 0b00001110) != 0b00001110)
  {
    PORTB &= ~(0b00100000);
    delay(1000);
    PORTB |= 0b00100000;
    if ((PINC & 0b00001110) == 0b00001110) break;
    PORTB &= ~(0b00010000);
    delay(1000);
    PORTB |= 0b00010000;
    if ((PINC & 0b00001110) == 0b00001110) break;
    PORTB &= ~(0b00001000);
    delay(1000);
    PORTB |= 0b00001000;
    if ((PINC & 0b00001110) == 0b00001110) break;
    PORTB &= ~(0b00000100);
    delay(1000);
    PORTB |= 0b00000100;
    if ((PINC & 0b00001110) == 0b00001110) break;
  } 
  PORTB &= ~(0b00000000);
}
//------------------------------------------------------------------------------------------------
