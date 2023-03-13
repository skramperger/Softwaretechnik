#include <Arduino.h>
// Unnötige Bitmustererzeugung


#define LED1 2  // Port B, Pin 2
#define LED2 3  // Port B, Pin 3
#define LED3 4  // Port B, Pin 4
#define LED4 5  // Port B, Pin 5

#define TASTE1 1 // Port C, Pin 1
#define TASTE2 2 // Port C, Pin 2
#define TASTE3 3 // Port C, Pin3

void setup() {
  // put your setup code here, to run once:

  DDRB |= ((1<<LED4) | (1<<LED3) | (1<<LED2) | (1<<LED1));
  PORTB |= ((1<<LED4) | (1<<LED3) | (1<<LED2) | (1<<LED1));   // LED's ausschalten
  DDRC &= ~((1<<TASTE1) | (1<<TASTE2) | (1<<TASTE3));
}

void loop() {
  // put your main code here, to run repeatedly:
  if ((PINC & 0b00001110) == 0b00001110)
  {
    // keine Taste gedrückt
    PORTB |= ((1<<LED4) | (1<<LED3) | (1<<LED2) | (1<<LED1));   // LED's ausschalten
  }
  else
  {
    // irgendeine Taste gedrückt
    PORTB &= ~((1<<LED4) | (1<<LED3) | (1<<LED2) | (1<<LED1));  // LED's einschalten
  }

}
