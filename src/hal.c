#include "hal.h"

void hal_pin_direction(HALPin pin, PinDirection direction) {
    if (direction == OUTPUT) {
        *(pin.port - 1) |= (1 << pin.pin); // DDRx is one address below PORTx
    } else {
        *(pin.port - 1) &= ~(1 << pin.pin);
        if(pin.pullup == PULLUP_ENABLE){
          *(pin.port - 2) |= (1 << pin.pin);
        }
    }
}

void hal_pin_write(HALPin pin, PinLevel level) {
    if (level == HIGH) {
        *(pin.port) |= (1 << pin.pin);
    } else {
        *(pin.port) &= ~(1 << pin.pin);
    }
}

PinLevel hal_pin_read(HALPin pin) {
    return (*(pin.port - 2) & (1 << pin.pin)) ? HIGH : LOW; // PINx is two addresses below PORTx
}