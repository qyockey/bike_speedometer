MCU 	:= atmega32u4
F_CPU 	:= 16000000
PROG 	:= speedometer
TERM 	:= wezterm
PORT 	:= /dev/ttyACM0

CC 		:= avr-gcc
CPPFLAGS	:= -I./inc
CFLAGS		:= -mmcu=$(MCU) -DF_CPU=$(F_CPU)UL -Os -Wall -Wextra -Wpedantic
LDFLAGS		:= -mmcu=$(MCU)
AVRDUDE_FLAGS	:= -v -c avr109 -p $(MCU) -P $(PORT) -b 57600 -D
AVRSIZE_FLAGS	:= --mcu=$(MCU) --format=avr

SRC_DIR := ./src
INC_DIR := ./inc
OUT_DIR := ./out

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
HDR_FILES := $(wildcard $(INC_DIR)/*.h)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OUT_DIR)/%.o, $(SRC_FILES))
ELF_FILE := $(OUT_DIR)/$(PROG).elf
HEX_FILE := $(OUT_DIR)/$(PROG).hex

.PHONY: all
all: $(HEX_FILE)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c $(HDR_FILES) | $(OUT_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(OUT_DIR):
	mkdir -p $@

$(ELF_FILE): $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $@ $^
	avr-size $(AVRSIZE_FLAGS) $@

$(HEX_FILE): $(ELF_FILE)
	avr-objcopy -O ihex -R .eeprom $< $@

.PHONY: upload
upload: $(HEX_FILE)
	avrdude $(AVRDUDE_FLAGS) -U flash:w:$<

.PHONY: clean
clean:
	rm -rf $(OUT_DIR)

