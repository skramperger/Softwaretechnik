#include "mbed.h"

DigitalOut trigger(p21);
InterruptIn echo(p22);

float time_measurement = 0.0;
Timer measure;

void isr_rise(){
    measure.reset();
    measure.start();
}

void isr_fall(){
    measure.stop();
    time_measurement = measure.read_us();
}

int main() {

    echo.rise(&isr_rise);
    echo.fall(&isr_fall);

  while(1) {

      trigger.write(1);
      wait_us(10);
      trigger.write(0);
      
      if (time_measurement > 0.0){
          printf("Distanz: %.2f cm\n", time_measurement/58.0);
          time_measurement = 0.0;
      }      

      wait_ms(1000);
  }
}
