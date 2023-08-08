HAL_LIBRARY_DIR := ../../
HAL_LIBRARY_NAME := HAL
HAL_LIBRARY_INC_DIR := $(HAL_LIBRARY_DIR)inc
MCU=atmega168  
F_CPU=8000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS=-std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I$(HAL_LIBRARY_INC_DIR) -I./inc
TARGET=main
SRCDIR := src
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c, $(SRCDIR)/%.o, $(SOURCES))
DEPS := $(patsubst $(SRCDIR)/%.c, $(SRCDIR)/%.d, $(SOURCES))

.PHONY: all flash clean

.SECONDARY: ${TARGET}.bin ${TARGET}.hex 

all: ${TARGET}.hex

-include $(DEPS) 

$(HAL_LIBRARY_DIR)$(HAL_LIBRARY_NAME).a:
	$(MAKE) -C $(HAL_LIBRARY_DIR)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(HAL_LIBRARY_DIR)$(HAL_LIBRARY_NAME).a
	$(CC) -c -MMD ${CFLAGS} $< -o $@

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(HAL_LIBRARY_DIR)$(HAL_LIBRARY_NAME).a
	${CC} -c -MMD ${CFLAGS} $< -o $@
	
${TARGET}.bin: $(OBJECTS) $(HAL_LIBRARY_DIR)$(HAL_LIBRARY_NAME).a
	${CC} ${CFLAGS} -o $@ $^

${TARGET}.hex: ${TARGET}.bin 
	${OBJCOPY} -j .text -j .data -O ihex $< $@

flash: ${TARGET}.hex
	avrdude -p ${MCU} -c usbasp -U flash:w:$<:i -F -P usb -B 4

clean:
	rm -f *.bin *.hex $(SRCDIR)/*.o $(SRCDIR)/*.d

flash_and_clean: all flash clean