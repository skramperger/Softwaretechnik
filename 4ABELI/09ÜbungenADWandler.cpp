//-------------------------------------------------------
// Analogwandler 1
#include <Arduino.h>

#define Poti A0

void setup() {
  Serial.begin(9600);
  pinMode(Poti, INPUT);
}

void loop() {
  unsigned int Analog0;

  for (unsigned int i=0; i< 30; i++)
  {
    Analog0 = analogRead(Poti);
    Serial.println(Analog0);
    delay(1000);
  }
}
//-------------------------------------------------------
// Analogwandler 2
#include <Arduino.h>

#define LED1 13
#define LED2 12
#define LED3 11

#define Taste1 A1
#define Taste2 A2
#define Taste3 A3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(Taste1, INPUT);
  pinMode(Taste1, INPUT);
  pinMode(Taste1, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned int Analog1, Analog2, Analog3;

  Analog1 = analogRead(Taste1);
  Analog2 = analogRead(Taste2);
  Analog3 = analogRead(Taste3);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);

  Serial.println(Analog1);
  Serial.println(Analog2);
  Serial.println(Analog3);
  Serial.println("------");

  if (Analog1 > 512){
    digitalWrite(LED1, LOW);
  }
  else{
    digitalWrite(LED1, HIGH);
  }

  if (Analog2 > 512){
    digitalWrite(LED2, LOW);
  }
  else{
    digitalWrite(LED2, HIGH);
  }

  if (Analog3 > 512){
    digitalWrite(LED3, LOW);
  }
  else{
    digitalWrite(LED3, HIGH);
  }

  delay(1000);
}

//-------------------------------------------------------
// Analogwandler 3
#include <Arduino.h>

#define Array_size 30

#define LED1 13
#define LED2 12
#define LED3 11

#define Taste1 A1
#define Taste2 A2
#define Taste3 A3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int Analog1, Analog2, Analog3;
  unsigned int Array[Array_size];

  unsigned int Average_High = 0, High_Total = 0, High_Counter = 0;
  unsigned int Average_Low = 0, Low_Total = 0, Low_Counter = 0;

  for (int i = 0; i<30; i++){
    Analog1 = analogRead(Taste1);
    Array[i] = Analog1;

    if (Analog1 > 512){
      High_Total += Analog1;
      High_Counter++;
    }

    if (Analog1 <= 512){
      Low_Total += Analog1;
      Low_Counter++;
    }

    Serial.print("Wert: ");
    Serial.println(i+1);
    Serial.println(Array[i]);
    delay(1000);
  }
  
  if(High_Counter == 0){    // Division through 0 prevention
    High_Counter = 1;
  }

  if(Low_Counter == 0){     // Division through 0 prevention 
    Low_Counter = 1;
  }

  Average_High = High_Total / High_Counter;
  Average_Low = Low_Total / Low_Counter;

  Serial.println("Hoher Mittelwert: ");
  Serial.println(Average_High);
  Serial.println("Niedriger Mittelwert: ");
  Serial.println(Average_Low);

  Serial.println("Finished");
  delay(100000);
}

//-------------------------------------------------------
// Analogwandler 4
#include <Arduino.h>

#define Array_size 90
//#define Testing

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int Analog1, Analog2, Analog3, Feld[Array_size];
  unsigned long Average_High = 0, Average_High_Total = 0;
  unsigned long Average_Low = 0, Average_Low_Total = 0;
  unsigned int High_counter = 0, Low_counter = 0;

  for (int i=0; i<30; i++)
  {
    Analog1 = analogRead(A1);
    Analog2 = analogRead(A2);
    Analog3 = analogRead(A3);

    Feld[i*3] = Analog1;
    Feld[i*3+1] = Analog2;
    Feld[i*3+2] = Analog3;

    Serial.print("Runde: ");
    Serial.println(i);
    Serial.println(Analog1);
    Serial.println(Analog2);
    Serial.println(Analog3);
    Serial.println("---------");
      
    delay(1000);

  }


  for (int i = 0; i<Array_size; i++)
  {
    if (Feld[i] >= 512)
    {
      Average_High_Total += Feld[i];
      High_counter++;
    }
    else if ( Feld[i] < 512)
    {
      Average_Low_Total += Feld[i];
      Low_counter++;
    }

  // Division durch 0 gibt unendlich hohen Wert aus
  }
  if (Low_counter == 0)
  {
    Low_counter++;
  }
  if (High_counter == 0)
  {
    High_counter++;
  }
  //------------------------------

  Average_High = Average_High_Total / High_counter;
  Average_Low = Average_Low_Total / Low_counter;

  Serial.println("Mittelwerte Hoch und Niedrig: ");
  Serial.println("Hoch: ");
  Serial.println(Average_High);
  Serial.println("Niedrig: ");
  Serial.println(Average_Low);

  #ifdef Testing
  Serial.println("Hoch: ");
  Serial.println(Average_High);
  Serial.println(Average_High_Total);
  Serial.println(High_counter);
  Serial.println("Niedrig: ");
  Serial.println(Average_Low);
  Serial.println(Average_Low_Total);
  Serial.println(Low_counter);
  #endif

  delay(100000);
}
//-------------------------------------------------------
