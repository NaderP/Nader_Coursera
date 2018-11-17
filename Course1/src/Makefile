#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

#COMMON FLAGS#
CFLAGS = -g -O0 -Wall -Werror -std=c99
TARGET = c1m2
LDFLAGS = -Wl,-Map=$(TARGET).map


# Platform Overrides

#MSP432 platform
ifeq ($(PLATFORM),MSP432)

LINKER_FILE = ../msp432p401r.lds 
CPU = cortex-m4 
ARCH = thumb
ARCH_FLAGS = -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
SPECS = nosys.specs

# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
LDFLAGS = -T $(LINKER_FILE) 
CFLAGS  += -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) $(ARCH_FLAGS)
CPPFLAGS = -DMSP432 $(INCLUDES)
OBJDUMP := arm-none-eabi-objdump
SIZE := arm-none-eabi-size

else

#HOST platform

LINKER_FILE :=
CPU :=
ARCH :=
SPECS :=
CPPFLAGS = -DHOST $(INCLUDES)
OBJDUMP = objdump
SIZE = size

endif


OBJS = $(SOURCES:.c=.o)
OBJD = $(SOURCES:.c=.d)
OBJi = $(SOURCES:.c=.i)
OBJA = $(SOURCES:.c=.asm)
%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@ $(CPPFLAGS) 
%.d : %.c
	$(CC) -M  $< -MF  $@ $(CPPFLAGS)  
%.asm: %.c
	$(CC)  -S $< $(CPPFLAGS) $(CFLAGS) -o $@
%.i : %.c
	$(CC) $(CPPFLAGS) -E $< -o $@

.PHONY: build
build: $(TARGET).out $(OBJD) objdump size 

objdump: $(TARGET).out
	$(OBJDUMP) -S $(TARGET).out > $(TARGET).asm

$(TARGET).out: $(OBJS)
	$(CC) $(CPPFLAGS)  $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@ 
.PHONY: size
size: $(TARGET).out
	$(SIZE) -Ad $(TARGET).out
.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: clean
clean:
	rm -f $(TARGET).out $(TARGET).map *.o *.i *.d *.asm
