CC := avr-gcc
CFLAGS := -Os -DF_CPU=8000000UL -mmcu=atmega168

HAL_LIBRARY_DIR := ./
HAL_LIBRARY_NAME := HAL
HAL_LIBRARY_OBJ_DIR := $(HAL_LIBRARY_DIR)src/
HAL_LIBRARY_INC_DIR := $(HAL_LIBRARY_DIR)inc/
HAL_LIBRARY_SRC := $(wildcard $(HAL_LIBRARY_OBJ_DIR)*.c)
HAL_LIBRARY_OBJ := $(HAL_LIBRARY_SRC:.c=.o)
HAL_LIBRARY_AR := ar -rcs

# default rule to build .a library
all: $(HAL_LIBRARY_NAME).a

$(HAL_LIBRARY_NAME).a: $(HAL_LIBRARY_OBJ)
	$(HAL_LIBRARY_AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I$(HAL_LIBRARY_INC_DIR) -c $< -o $@

clean:
	rm -f $(HAL_LIBRARY_NAME).a $(HAL_LIBRARY_OBJ)