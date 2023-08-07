#include <avr/io.h>
#include <avr/power.h>
#include <avr/delay.h>
#include "hal.h"

int main(void) {
  clock_prescale_set(clock_div_1);

  HALPin led = {&PORTB, 0}; // PB0 
  gpio_pin_direction(led, OUTPUT);
  while (1) {
    gpio_pin_write(led, HIGH); 
    _delay_ms(500);
    gpio_pin_write(led, LOW); 
    _delay_ms(500);
  }

}