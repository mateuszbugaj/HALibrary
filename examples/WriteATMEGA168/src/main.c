#include <avr/io.h>
#include <avr/power.h>
#include <avr/delay.h>
#include "hal.h"

/*
+--------+
|  A168  |
|        |
|    PB0 +---> LED ---> GND 
|        |
+--------+
*/

int main(void) {
  clock_prescale_set(clock_div_1);

  HALPin led = {&PORTB, 0};
  hal_pin_direction(led, OUTPUT);
  while (1) {
    hal_pin_write(led, HIGH); 
    _delay_ms(500);
    hal_pin_write(led, LOW); 
    _delay_ms(500);
  }

}