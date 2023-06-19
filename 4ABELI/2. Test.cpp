//------------------------------------------------------------------------------
// Beispiel 1
// Die LED variable blinken lassen in Abhängigkeit vom analogen Wert A5 + 100 millisekunden und diesen Wert dann ausschreiben 

#include <Arduino.h>

#define LED1 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A5, INPUT);
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int Analog5 = 0;

  digitalWrite(LED1, HIGH);
  Analog5 = analogRead(A5);
  delay(Analog5 + 100);
  digitalWrite(LED1, LOW);
  delay(Analog5 + 100);
  Serial.println(Analog5 + 100);

}


//------------------------------------------------------------------------------
// Beispiel 2
// Es sollen 50 Werte von dem analogen Port A5 alle 20ms gelesen werden, in einem Feld gespeichert werden und den Durchschnitt der Werte berechnen und diesen seriell ausgeben.

#include <Arduino.h>

#define Array_size 50

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int Analog5 = 0;
  unsigned int Array[Array_size];

  unsigned int Analog_Gesamt = 0, Analog_Durchschnitt = 0;


  for (int i = 0; i<Array_size; i++){
    Analog5 = analogRead(A5);
    Array[i] = Analog5;
    Analog_Gesamt += Analog5;
    delay(20);
  }

  Analog_Durchschnitt = Analog_Gesamt / Array_size;
  Serial.print("Der Durchscnitt beträgt: ");
  Serial.println(Analog_Durchschnitt);

}
//------------------------------------------------------------------------------
// Beispiel 3
// Eine PinChangeInterruptroutine, in der ein Lauflicht fortlaufend leuchten soll. Der Interrupt zählt einen Zähler hoch, der bei jedem LED wechsel ausgegeben werden soll

#include <Arduino.h>

#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10

#define LED_interval_delay 1000

volatile unsigned int InterruptCount = 0;

ISR(PCINT1_vect)
{
  InterruptCount++;
}

void setup() {
  Serial.begin(9600);
  pinMode(LED1,OUTPUT);
  digitalWrite(LED1, HIGH);
  pinMode(LED2,OUTPUT);
  digitalWrite(LED2, HIGH);
  pinMode(LED3,OUTPUT);
  digitalWrite(LED3, HIGH);
  pinMode(LED4,OUTPUT);
  digitalWrite(LED4, HIGH);

  PCICR = 0b00000010;
  PCMSK1 = 0b00001110;
  sei();
}

void loop() {
  while (1)
  {
    unsigned int InterruptCountVar = 0;

    cli();
    InterruptCountVar = InterruptCount;
    sei();
    Serial.println(InterruptCountVar);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED1,LOW);
    delay(LED_interval_delay);
    cli();
    InterruptCountVar = InterruptCount;
    sei();
    Serial.println(InterruptCountVar);
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2, LOW);
    delay(LED_interval_delay);
    cli();
    InterruptCountVar = InterruptCount;
    sei();
    Serial.println(InterruptCountVar);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    delay(LED_interval_delay);
    cli();
    InterruptCountVar = InterruptCount;
    sei();
    Serial.println(InterruptCountVar);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    delay(LED_interval_delay);
  }
}
//------------------------------------------------------------------------------
