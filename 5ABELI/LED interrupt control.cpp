// Without Tiker
#include "mbed.h"

DigitalOut myled(LED1);
DigitalOut myled2(LED2);

DigitalIn sw(p14);
Ticker tik; // einfaches Timer-Objekt

void isr_blinky(){  // Callback-Funktion für unseren Ticker
    myled.write(!myled.read());
}

int main() {
    myled.write(1);
    int old_sw = 0;
    tik.attach_us(&isr_blinky, 500000); // Konfiguration für alle 0.5s Interrupt → isr_blinky Funktion
    // Ticker läuft ab jetzt immer bis .detach aufgerufen wird

    while(1) {      
        if(sw.read() == 1 && old_sw == 0){
            myled2 = !myled2;
        }
        old_sw = sw.read();

    }
    return 0;
}
__________________________________________________________________________________________________________
// With Tiker
#include "mbed.h"

DigitalOut myled(LED1);
DigitalOut myled2(LED2);

InterruptIn sw(p14);
Ticker tik; // einfaches Timer-Objekt

void isr_blinky() {  // Callback-Funktion für unseren Ticker
    myled.write(!myled.read());
}

void isr_toggle() {
    myled2 = !myled2;
}

int main() {
    
    myled.write(1);
    int old_sw = 0;
    tik.attach_us(&isr_blinky, 500000); // Konfiguration für alle 0.5s Interrupt → isr_blinky Funktion
    // Ticker läuft ab jetzt immer bis .detach aufgerufen wird
    sw.rise(isr_toggle);       // Steigender Flanke wird in Callback Funktion isr_toggle gesprungen

    while(1) {    
        // Empty
    }
    return 0;
}
