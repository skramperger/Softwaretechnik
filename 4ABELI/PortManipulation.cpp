//--------------------------------------------------------------------------------------------------------
#include <Arduino.h>
// Unnötige Bitmustererzeugung

#define LED1 2  // Port B, Pin 2
#define LED2 3  // Port B, Pin 3
#define LED3 4  // Port B, Pin 4
#define LED4 5  // Port B, Pin 5

void setup() {
  // put your setup code here, to run once:

  DDRB |= 0b00111100;
  // oder
  DDRB |= (0b00100000 | 0b00010000 | 0b00001000 | 0b00000100);
  // oder 
  DDRB |= ((1<<LED4) | (1<<LED3) | (1<<LED2) | (1<<LED1));


  PORTB |= 0b00111100;
  // oder
  PORTB |= ((1<<LED4) | (1<<LED3) | (0<<LED2) | (0<<LED1));
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB &= 0b11000011;  // LED's einschalten
  // oder
  PORTB &= ~((1<<LED4) | (1<<LED3) | (1<<LED2) | (1<<LED1));  // LED's einschalten

  PORTB ^= 0b00111100;  // LED's umschalten
  // oder
  PORTB ^= ((1<<LED4) | (1<<LED3) | (1<<LED2) | (1<<LED1));  // LED's umschalten
  _delay_ms(1000);
}

//--------------------------------------------------------------------------------------------------------
// PortManipulation Beispiel

#include <Arduino.h>
// Unnötige Bitmustererzeugung


#define LED1 2  // Port B, Pin 2
#define LED2 3  // Port B, Pin 3
#define LED3 4  // Port B, Pin 4
#define LED4 5  // Port B, Pin 5

#define TASTE1 1 // Port C, Pin 1
#define TASTE2 2 // Port C, Pin 2
#define TASTE3 3 // Port C, Pin 3

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
    while ((PINC & 0b00001110) != 0b00001110) ;
    _delay_ms(3000);
  }
}
//--------------------------------------------------------------------------------------------------------
