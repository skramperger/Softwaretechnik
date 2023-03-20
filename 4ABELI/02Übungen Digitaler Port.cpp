//----------------------------------------------------------------------------------------------------------------
// Lauflicht 

#include <Arduino.h>

#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1, LOW);
  delay(1000);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  delay(1000);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  delay(1000);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, LOW);
  delay(1000);
  digitalWrite(LED4, HIGH);
}
//----------------------------------------------------------------------------------------------------------------
// Lauflicht 2
#include <Arduino.h>

#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10

#define TASTE1 A1

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  pinMode(TASTE1, INPUT);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (digitalRead(TASTE1) == LOW)
  {
    digitalWrite(LED1, LOW);
    delay(1000);
    if (digitalRead(TASTE1) == HIGH) break;
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    delay(1000);
    if (digitalRead(TASTE1) == HIGH) break;
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    delay(1000);
    if (digitalRead(TASTE1) == HIGH) break;
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    delay(1000);
    if (digitalRead(TASTE1) == HIGH) break;
    digitalWrite(LED4, HIGH);
  }

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);

}
//----------------------------------------------------------------------------------------------------------------
// Lichtschalter

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
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  pinMode(TASTE1, INPUT);
  pinMode(TASTE1, INPUT);
  pinMode(TASTE3, INPUT);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1, digitalRead(TASTE1));
  digitalWrite(LED2, digitalRead(TASTE2));
  digitalWrite(LED3, digitalRead(TASTE3));

}
//----------------------------------------------------------------------------------------------------------------
// Gedämpftes Licht

#include <Arduino.h>

#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int counter=1; counter<9; counter++)
  {
    for (int i=0; i<100; i++)
    {
      digitalWrite(LED1, LOW);
      delay(counter);
      digitalWrite(LED1, HIGH);
      delay(10-counter);
    }
  }
}
//----------------------------------------------------------------------------------------------------------------
