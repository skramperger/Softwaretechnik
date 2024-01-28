#include "mbed.h"

InterruptIn key_center(p14);
InterruptIn key_down(p12);
InterruptIn key_up(p15);

// Bonus--------------------------------------------
AnalogIn Poti(p19); // liegt zwischen 0.0 bis 1.0
//--------------------------------------------------

// LED Werte. 8 lässt nur LED1 leuchten / 4 nur LED2 / 2 nur LED3 / 1 nur LED4
BusOut LED(LED1, LED2, LED3, LED4);

bool direction = true, state = false;


// Interrupt Function for starting and stopping
void isr_start_stop(){
    state = !state;
}

// Interrupt Function for changing directions
void isr_key_down(){
    direction = false;      // false means going backwards 8>4>2>1
}

// Interrupt Function for changing directions
void isr_key_up(){
    direction = true;       // true means normal forward direction 1>2>4>8
}


int main() {
    key_center.rise(&isr_start_stop);
    key_down.rise(&isr_key_down);
    key_up.rise(&isr_key_up);
    LED = 0;
    // Bnous-------------------------------------------------
    float poti_value = 0.0;     // Wert für poti.read
    // ------------------------------------------------------

  while(1) {

      poti_value = Poti.read();

      if (state == true){
          if (direction == true){
            if (LED == 0 || LED == 8) LED = 1;
            else LED = LED<<1;
            wait_us((1000000 * poti_value));       // 1 Sekunde * poti_value. Bei 0.5 = halbe Sekunde
          }
          else if (direction == false){
              if (LED == 0 || LED == 1) LED = 8;
              else LED = LED>>1;
              wait_us((1000000*poti_value));
          }
      }
  }
}
