// Stefan Kramperger

#include "mbed.h"

AnalogIn poti(p19);

InterruptIn key_up(p15);
InterruptIn key_down(p12);

float poti_value = 0.0, old_poti_value = 0.0, difference_poti_value = 0.0;
float max_poti_value = 0.0, min_poti_value = 0.0, max_min_difference = 0.0;
int counter = 0;
int old_key_up = 0, old_key_down = 0;   // Leider fehlte Zeit um Entprellen hinzuzufügen

BusOut LEDs(LED1, LED2, LED3, LED4);

Timer Zeit;
Ticker frequency_tick;

void ticker_func(){
    LEDs = 1<<4; // Sollte 1 für LED4 reinschieben
}

void isr_key_up_fall(){
    Zeit.start();
    if (Zeit.read() <= 0.5){ 
        LEDs = 1;   // Lässt LED1 leuchten
        if (counter == 0){
            poti_value = poti.read();
            counter++;
            printf("Erster Poti-Wert gesetzt mit: %.2f", poti_value);
        }
        else if (counter == 1){
            old_poti_value = poti_value;
            poti_value = poti.read();
            difference_poti_value = old_poti_value - poti_value;
            printf("Differenz der beiden Poti-Werte: %.3f\n", difference_poti_value);
            counter = 0;
        }
    if (Zeit.read() > 1){
        poti_value = poti.read();
        if (poti_value > max_poti_value){
            max_poti_value = poti_value;
        } 

        if (poti_value < min_poti_value){
            min_poti_value = poti_value;
        }

        max_min_difference = max_poti_value - min_poti_value;
        if (Zeit.read() > 1.5){
            printf("Der berechnete Max-Min Wert ist: %.2f", max_min_difference);
        }
    }
    }
    Zeit.stop();
    if (poti_value != 0.0){
        LEDs = 5; // LED1 und LED3 leuchten
    }
}

void isr_key_down(){
    printf("Messungen wurden resetet.");
    LEDs = 4; // LED3 leuchtet
    frequency_tick.attach(&ticker_func, ((1/2.5)/2));
}

int main() {

    LEDs = 0;
    key_up.fall(&isr_key_up_fall);
    key_down.rise(&isr_key_down);
    bool statement = true;

  while(1) {
      wait_us(500000);      // 5 Sekunden nur hinzugefügt damit es Putty anzeigt
      if(statement == true){
          printf("Startwert gesetzt");
          statement = false;
      }

  }
}
