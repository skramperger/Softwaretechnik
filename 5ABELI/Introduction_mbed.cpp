#include "mbed.h"

int main() {
    // Setup Code
    // pinMode(LED1, OUTPUT);
    DigitalOut myled_1(LED1);   // Der Parameter LED1 bezeichnet einen GPIO (in MBED: PinMode)
    DigitalOut myled_2(LED2);
    DigitalIn *key_c;           // erstellt noch kein Objekt, sondern definiert einen Zeiger
    key_c = new DigitalIn(p14); // new-operator reserviert RAM für das Objekt
    // DigitalOut ist eine Klasse (OOP), myled unser Name fpr ein Objekt
  while(1) {
    // Loop Code
    myled_1.write(1); //myled=1;
    wait_us(200000);
    myled_1.write(0); //myled=0;
    wait_us(200000);
    if(key_c->read() == 1) {    // Pfeil Operator wird bei Zeigern benötigt
        myled_2.write(!myled_2.read());     // led2 wechselt den Zustand
        // myled_2 != myled_2; funktioniert gleich!
    }
  }
}
