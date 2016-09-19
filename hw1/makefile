#********************************************************************************************************************
# Description:
#  This is the makefile for cross compiling on the three targets listed below:					
#  1) Linux based host machine.
#  2) BeagleBone Black Board
#  3) Freadom board FRDM KL25z.
# Author: Vikhyat Goyal
#********************************************************************************************************************

include source.mk
CC = gcc
CFLAGS	= -Wall -g -O0 -Wl,-Map=$(OUT).map

COPY = scp
BBBIP = root@192.168.7.2
REMOTE_PATH = /home/debian/bin/vikhyat

#The macro is defined to specify the final executable output file name.
OUT	= project

#Macro for all the header files which are the prerequites for compilation.
#HEADER = hw1.h

#The macro OBJECT contains all the .o files which are the dependencies for generating teh executable file.
# All the .c files are convered to .o file by the 
OBJECT	= ${SOURCE:.c=.o}

ifeq ($(ARCH),BBB)
	CC=arm-linux-gnueabihf-gcc $(build)
else ifeq ($(ARCH), HOST)
	cc = gcc 
else ifeq ($(ARCH),FRDM)
	CC=arm-none-eabi-gcc
else
	CC = gcc
endif

#Remove the default sufix rules.
.SUFFIXES :
#making our own suffix rules.
# $< makes sure that the rule runs for all the changed files only.
.SUFFIXES: .o .c
.c.o :
	$(COMPILER) $(CFLAGS) -c $<

#Throw a warning for undefined platforms
DEFAULT : $(SOURCE)
	@echo "No platform specified.Building for HOST platform"
	@echo "please use BBB for beaglebone, HOST for host machine and FRDM for freedom board"
	$(CC) $(CFLAGS) -o $(OUT) $^

#Target for generating all preprocessed output files.
Preprocess:
	$(CC) -E $<

%.i : 
	$(CC) -E $<

#Target for generating all asm files.
asm-file:$(SOURCE)
	$(CC) -S $^

%.S :
	$(CC) -S $<

%.o :
	$(CC) -c $<

compile-all: $(SOURCE)
	$(CC) -c $^

build: $(SOURCE)
	$(CC) -o $(OUT) $(CFLAGS) $^
	size -A $(OUT)
OBJECT : $(HEADER)
upload:
	$(COPY) project $(BBBIP)/$(REMOTE_PATH)
	

#Target clean for deleting all the generated files.
clean :
	-rm -f $(OUT) $(OBJECT) $(OUT).map 
