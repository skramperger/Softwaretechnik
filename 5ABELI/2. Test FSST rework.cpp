// Autor: Stefan Kramperger
// Date: 30.01.2024


// FSST 2nd Test
#include "mbed.h"

#define BLINK_FREQUENZ 2.5


// Eingänge
//-----------------------------------------------------------------------------------
Serial pc(USBTX, USBRX);    // Serielle Ausgabe
AnalogIn poti(p19);
InterruptIn key_up(p15);
InterruptIn key_down(p12);
//-----------------------------------------------------------------------------------

// Ausgänge
//-----------------------------------------------------------------------------------
BusOut LEDs (LED1, LED2, LED3, LED4);
//-----------------------------------------------------------------------------------

// Mess-Variablen
//-----------------------------------------------------------------------------------
float poti_val = 0.0, old_poti_val = 0.0, dif_poti_value = 0.0;
float max_poti_value = 0.0, min_poti_value = 0.0, max_min_dif = 0.0;
//-----------------------------------------------------------------------------------

// Zählen funktioniert nicht ganz, deshalb boolean
//-----------------------------------------------------------------------------------
bool press_counter = false;
//-----------------------------------------------------------------------------------

// Text Szenarios um diese nicht in den ISR Funktionen mit printf ausgeben zu lassen
// Verkürzt die ISR Funktionen um einiges, sodass sie erst richtig funktionieren (danke für die Info, Gödl)
//-----------------------------------------------------------------------------------
bool text_max_min_set = false;
bool text_dif_measurement_in_percent = false; //
bool text_max_min_long_press = false;
bool text_reset = false;    // sollen alle Messungen und alle Ausgaben reseten 
//-----------------------------------------------------------------------------------

// Timer und Ticker Objekte
//-----------------------------------------------------------------------------------
Timer Zeit, debounce;       // Zeit misst wie lange button gedrückt ist, debounce sorgt für's Entprellen 
Ticker freq_tick;           // Ticker für Ticker-Funktion, die LED4 blinken lässt
//-----------------------------------------------------------------------------------

// ISR Funktion für Drücken des UP Key
//-----------------------------------------------------------------------------------
void isr_key_up_rise(){
    if (debounce.read_ms() > 200){
        poti_val = poti.read();
        if (poti_val > max_poti_value){
            max_poti_value = poti_val;
        }
        if (poti_val < min_poti_value){
            min_poti_value = poti_val;
        }
        text_max_min_set = true;
    }
    debounce.reset();
}
//-----------------------------------------------------------------------------------


// ISR Funktion für Loslassen des UP Keys
//-----------------------------------------------------------------------------------
void isr_key_up_fall(){
    if (Zeit.read_us() <= 500000){
        LEDs = 1;
        if (press_counter == false){
            poti_val = poti.read();
            press_counter = true;
        }
        else{
            if(press_counter == true){
                old_poti_val = poti_val;
                poti_val = poti.read();
                dif_poti_value = old_poti_val - poti_val;

                if (old_poti_val < poti_val){
                    poti_val *= -1;
                }
                if (poti_val != 0.0){
                    LEDs = 2;
                }
                press_counter = false;
            }
        }
        text_dif_measurement_in_percent = true;
    }

    if (Zeit.read_us() > 1000000){
        max_min_dif = max_poti_value - min_poti_value;
    }
    if (Zeit.read_us() > 1000000 && Zeit.read() < 1500000){
        text_max_min_long_press = true;
    }
    Zeit.stop();
    Zeit.reset();
}
//-----------------------------------------------------------------------------------


// ISR Funktion für Drücken des DOWN Keys
//-----------------------------------------------------------------------------------
void isr_key_down_rise(){
    if (debounce.read_ms() > 200){
        LEDs = 4;
        debounce.reset();
        text_reset = true;

        // alle Werte auf 0 setzen
        poti_val = 0.0;
        old_poti_val = 0.0;
        dif_poti_value = 0.0;
        max_poti_value = 0.0;
        min_poti_value = 0.0;
        max_min_dif = 0.0;
        press_counter = false;
    }
}
//-----------------------------------------------------------------------------------

// TICKER gesteuert mit BLINK_FREQUENZ
//-----------------------------------------------------------------------------------
void ticker_func(){
    if (LEDs >= 8){LEDs = LEDs - 8;}
    else {LEDs = LEDs + 8;}
}
//-----------------------------------------------------------------------------------


// Main Funktion
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
int main() {
    
    LEDs = 0;
    key_up.fall(&isr_key_up_fall);
    key_up.rise(&isr_key_up_rise);
    key_down.rise(&isr_key_down_rise);
    freq_tick.attach(&ticker_func, ((1/BLINK_FREQUENZ)/2));

    bool statement = true;
    debounce.start();

// Main Loop
//-----------------------------------------------------------------------------------
    while(1) {
        if (statement == true){
            pc.printf("Startwert gesetzt\n");
            statement = false;
        }
// Text Ausgaben von ISR Funktionen
//-----------------------------------------------------------------------------------
        if (text_max_min_set == true){
            pc.printf("Max und Min Poti Werte gesetzt\n");
            text_max_min_set = false;
        }
        if (text_dif_measurement_in_percent == true){
            pc.printf("Differenz der beiden Poti-Werte: %.3f\n", dif_poti_value);
            pc.printf("Differenz in Prozent: %.3f%\n", (poti_val/(old_poti_val/100)));
            text_dif_measurement_in_percent = false;
        }
        if (text_max_min_long_press){
            pc.printf("Der berechnete Max-Min Wert ist: %.2f\n", max_min_dif);
            text_max_min_long_press = false;
        }
        if (text_reset == true){
            pc.printf("Messungen wurden resetet.\n");
            text_reset = false;
        }
  }
}
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
