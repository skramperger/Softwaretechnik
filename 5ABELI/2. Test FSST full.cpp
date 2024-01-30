// Autor: Stefan Kramperger
// Date: 30.01.2024

// FSST 2nd Test
#include "mbed.h"

#define BLINK_FREQUENZ 2.5

// Eingänge
// ----------------------------------------------------------------------------------
AnalogIn poti(p19);                     // Wert von 0.0 bis 1.0
InterruptIn key_up(p15);
InterruptIn key_down(p12);
// ----------------------------------------------------------------------------------

// Ausgänge
// ----------------------------------------------------------------------------------
BusOut LEDs(LED1, LED2, LED3, LED4);    // LED Werte Zuordnungen
// ----------------------------------------------------------------------------------

// Variablen
//-----------------------------------------------------------------------------------
float poti_value = 0.0, old_poti_value = 0.0, difference_poti_value = 0.0;
float max_poti_value = 0.0, min_poti_value = 0.0, max_min_difference = 0.0;
int press_counter = 0;                  // zählt die Key presses
int old_key_up = 0, old_key_down = 0;
//-----------------------------------------------------------------------------------


// Timer und Ticker Objekte
// ----------------------------------------------------------------------------------
Timer Zeit;
Ticker frequency_tick;
// ----------------------------------------------------------------------------------

// ISR Funktion für Drücken des UP Key
// ----------------------------------------------------------------------------------
void isr_key_up_rise(){
    if (old_key_up == 0 && key_up.read() == 1){
        Zeit.start();                                                   // Zeit muss nach erstmaligem Drücken gemessen werden
        while (key_up.read() == true){                                  // Solange der Key gedrückt ist, sollen die Werte aufgenommen werden
            poti_value = poti.read();
            if (poti_value > max_poti_value){
                max_poti_value = poti_value;
            }
            if (poti_value < min_poti_value){
                min_poti_value = poti_value;
            }
        }
    }
}
// ----------------------------------------------------------------------------------

// ISR Funktion für Loslassen des UP Keys
// ----------------------------------------------------------------------------------
void isr_key_up_fall(){
    if (Zeit.read() <= 0.5){                          // Kurzes Drücken
        LEDs = 1;   // Lässt LED1 leuchten
        if (press_counter == 0){                      // counter für erstmaliges Drücken
            poti_value = poti.read();
            press_counter++;
            printf("Erster Poti-Wert gesetzt mit: %.2f", poti_value);
        }
        else if (press_counter == 1){
            old_poti_value = poti_value;
            poti_value = poti.read();
            difference_poti_value = old_poti_value - poti_value;
            printf("Differenz der beiden Poti-Werte: %.3f\n", difference_poti_value);

            // Prozent Berechnung
            if (old_poti_value < poti_value){
                poti_value *= -1;                     // Berücksichtigung von negativen Differenzen → 0.5 - 1.0 = -200% Verlust
            }
            printf("Differenz in Prozent: %.3f\n", (poti_value/(old_poti_value/100)));      
            press_counter = 0;                        // auf 0 gesetzt um wieder erstmaliges Drücken zu ermöglichen (wenn nicht erwünscht = Variable auskommentieren)
        }
    if (Zeit.read() > 1){                             // Langes Drücken
        max_min_difference = max_poti_value - min_poti_value;
        if (Zeit.read() > 1.5){                       // 0.5 Sekunden Erweiterung für "wenn nicht innerhalb von 0.5 Sekunden Reset gedrückt wird"
            printf("Der berechnete Max-Min Wert ist: %.2f", max_min_difference);
        }
    }
    }
    Zeit.stop();
    Zeit.reset();
    if (poti_value != 0.0){
        LEDs = 2; // LED2 leuchtet nach stoppen der Messung
    }
}
// ----------------------------------------------------------------------------------

// ISR Funktion für Drücken des DOWN Key
// ----------------------------------------------------------------------------------
void isr_key_down(){
    if (old_key_down == 0 && key_down.read() == 1){
        printf("Messungen wurden resetet.");
        LEDs = 4; // LED3 leuchtet
    }
}
//----------------------------------------------------------------------------------

// TICKER gestuert mit BLINK_FREQUENZ
// ----------------------------------------------------------------------------------
void ticker_func(){
    if (LEDs >= 8){LEDs = LEDs - 8;}    
    else {LEDs = LEDs + 8;}
}
// ----------------------------------------------------------------------------------

// Main Function
// ----------------------------------------------------------------------------------
int main() {

    LEDs = 0;                                                       // switcht alle LEDs off
    key_up.fall(&isr_key_up_fall);          
    key_up.rise(&isr_key_up_rise);
    key_down.rise(&isr_key_down);
    frequency_tick.attach(&ticker_func, ((1/BLINK_FREQUENZ)/2));     // Lässt LED4 an und aus blinken in Abhängigkeit von BLINK_FREQUENZ
    bool statement = true;                                          // Wert für print einmaliges Statement


// Main Loop
// ----------------------------------------------------------------------------------
  while(1) {
      if(statement == true){
        printf("Startwert gesetzt");      // Einmaliges print Statement, dass nur bei Reset angezeigt wird
        statement = false;
    }
    wait_us(20000);                       // Entprellen von 20ms
    old_key_up = key_up.read();
    old_key_down = key_down.read();

  }
// ----------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------
}
