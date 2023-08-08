#include <avr/io.h>
#include <avr/power.h>
#include <avr/delay.h>
#include "hal.h"

/*
+--------+
|  A168  |
|        |
|    PB0 +---> LED ---> GND 
|    PB1 +<--- BUTTON <--- GND
|        |
+--------+
*/

int main(void) {
  clock_prescale_set(clock_div_1);

  HALPin led = {&PORTB, 0}; // PB0 
  hal_pin_direction(led, OUTPUT);

  HALPin button = {&PORTB, 1, PULLUP_ENABLE};
  hal_pin_direction(button, INPUT);

  while (1) {
    if(hal_pin_read(button) == LOW){
      hal_pin_write(led, HIGH); 
    } else {
      hal_pin_write(led, LOW); 
    }
  }

}