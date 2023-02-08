#include <Arduino.h>

#define button 13
int LED[] = {8, 7, 6};

bool ButtonState;
bool FlipFlop = false;
bool ButtonStateOld = false;
int ActiveLED = 0;
unsigned long LastSwitchTime, CurrentTime;
// Berechnung von Größe des Arrays
size_t n = sizeof(LED) / sizeof(LED[0]);

void setup() {
  // put your setup code here, to run once:

  pinMode(button, INPUT);

  for (int i=0; i<n; i++)
  {
    pinMode(LED[i], OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  CurrentTime = millis();
  bool ButtonState = digitalRead(button);

  if ((ButtonState ^ ButtonStateOld) && (ButtonState))
  {
    FlipFlop = !FlipFlop;
    LastSwitchTime = CurrentTime;
    if (FlipFlop)
    {
      ActiveLED = 0;
      digitalWrite(LED[0], HIGH);
    }
    else
    {
      digitalWrite(LED[ActiveLED], LOW);
    }
  }
  ButtonStateOld = ButtonState;

  if (FlipFlop)
  {
    if (CurrentTime >= LastSwitchTime + 1000)
    {

      digitalWrite(LED[ActiveLED], LOW);
      ActiveLED++;
      if (ActiveLED == 3)
      {
        ActiveLED = 0;
      }
      digitalWrite(LED[ActiveLED], HIGH);

      LastSwitchTime = CurrentTime;
    }
  }
}
