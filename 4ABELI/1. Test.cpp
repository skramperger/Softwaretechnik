//-----------------------------------------------------------------------------
// Lauflicht
#include <Arduino.h>

#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10


void setup() {
  // put your setup code here, to run once:
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);
  pinMode (LED4, OUTPUT);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1, LOW);
  digitalWrite(LED3, LOW);
  delay(1000);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED3, HIGH);

  digitalWrite(LED2, LOW);
  digitalWrite(LED4, LOW);
  delay(1000);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED4, HIGH);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  delay(1000);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);

}
//-----------------------------------------------------------------------------
// Lauflicht 2

void setup() {
  // put your setup code here, to run once:
  DDRB |= 0b00111100;
  PORTB |= 0b00111100;

}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB &= ~(0b00101000);
  _delay_ms(1000);
  PORTB |= 0b00101000;

  PORTB &= ~(0b00010100);
  _delay_ms(1000);
  PORTB |= 0b00010100;

  PORTB &= ~(0b00111100);
  _delay_ms(1000);
  PORTB |= 0b00111100;
}
//-----------------------------------------------------------------------------
// Abfragen

#include <Arduino.h>

#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10

#define TASTE1 A1
#define TASTE2 A2
#define TASTE3 A3

void setup() {
  // put your setup code here, to run once:
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);
  pinMode (LED4, OUTPUT);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  if ((digitalRead(TASTE1) == LOW) || (digitalRead(TASTE2) == LOW) || (digitalRead(TASTE3) == LOW))
  {
    digitalWrite(LED1, LOW);
  }
  else
  {
    digitalWrite(LED1, HIGH);
  }

  if (((digitalRead(TASTE1) == LOW) && (digitalRead(TASTE2) == LOW)) || ((digitalRead(TASTE1) == LOW) && (digitalRead(TASTE3) == LOW)) || ((digitalRead(TASTE2) == LOW) && (digitalRead(TASTE3) == LOW)))
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  }
  else
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
  }

  if ((digitalRead(TASTE1) == LOW) && (digitalRead(TASTE2) == LOW) && (digitalRead(TASTE3) == LOW))
  {
    digitalWrite(LED3, LOW);
  }
  else
  {
    digitalWrite(LED3, HIGH);
  }
}

//-----------------------------------------------------------------------------
