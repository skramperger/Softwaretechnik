// Task: Joystick that goes up and down, lets you switch between LED1 to LED3 on an ARM board 
// Pressing the joystick middle down, enables the rgb light depending on the LED Busout value and the poti acts as a dimmer


#include "mbed.h"

AnalogIn poti(p19);

PwmOut light_r(p23);
PwmOut light_g(p24);
PwmOut light_b(p25);

DigitalIn key_up(p15), key_down(p12), key_center(p14);

BusOut select(LED1, LED2, LED3);
// LED1 = 0 0 1
// LED2 = 0 1 0
// LED3 = 1 0 0

int main() {

    select = 1;
    int old_key_down = 0, old_key_up = 0, old_key_center = 0;

    float poti_value = 0.0;     // ranges from 0.0 to 1.0
    light_r.write(1.0);         // turns off red rgb light (active low)
    light_g.write(1.0);         // turns off green rgb light (active low)
    light_b.write(1.0);         // turns off blue rgb light (active low)

  while(1) {
    // key up press
    if (old_key_up == 0 && key_up == 1) {
      if (select == 4) select = 1;
      else select = select << 1;
      wait_us(10000);
    }


    // key down press
    if (old_key_down == 0 && key_down == 1) {
      if (select == 1) select = 4;
      else select = select >> 1;
      wait_us(10000);
    }

    // reset key values
    old_key_up = key_up;
    old_key_down = key_down;

    poti_value = poti.read();

    if (old_key_center == 0 && key_center == 1){
        if (select == 1){
            light_r.write(1-poti_value);
            light_g.write(1);
            light_b.write(1);
        }

        if (select == 2){
            light_g.write(1-poti_value);
            light_r.write(1);
            light_b.write(1);
        }
        
        if (select == 4){
            light_b.write(1-poti_value);
            light_r.write(1);
            light_g.write(1);
        }

    }
    old_key_center = key_center;
    wait_us(10000);


    }
  }

