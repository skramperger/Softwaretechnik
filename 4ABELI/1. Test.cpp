//-----------------------------------------------------------------------------
// Lauflicht
// Die LED's des Multifunktionsshields sollen nach angegebenem Muster aufleuchten. Zwischen den Mustern soll 1 Sekunde Pause sein. 
// Die Muster werden endlos wiederholt. Zuerst LED1 und LED3, dann LED2 und LED4 und zuletzt alle 4 LEDs.

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
// Dieselbe Angabe wie Beispiel 1, allerdings unter der Verwendung von Registern.

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
// In einer Schleife soll alle 10 Millisekunden folgendes geschehen:
//    - Wenn eine der 3 Tasten gedrückt ist, dann soll die erste LED leuchten
//    - Wenn zwei der 3 Tasten gedrückt sind, dann soll auch die zweite LED leuchten
//    - Wenn alle drei Tasten gedrückt sind, dann soll auch die dritte LED leuchten


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
