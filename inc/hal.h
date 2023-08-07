#ifndef HAL_H
#define HAL_H

#include <avr/io.h>

typedef enum {
    INPUT = 0,
    OUTPUT = 1
} PinDirection;

typedef enum {
    LOW = 0,
    HIGH = 1
} PinLevel;

typedef struct {
    volatile uint8_t* port;
    uint8_t pin;
} HALPin;

void hal_pin_direction(HALPin pin, PinDirection direction);
void hal_pin_write(HALPin pin, PinLevel level);
PinLevel hal_pin_read(HALPin pin);

#endif