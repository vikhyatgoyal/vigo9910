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
CFLAGS	= -Wall -g -O0 -I $(HDRPATH) -Wl,-Map=$(OUT).map

COPY = scp
BBBIP = root@192.168.7.2:/home/debian/bin/vikhyat

#The macro is defined to specify the final executable output file name.
OUT	= project

#The macro OBJECT contains all the .o files which are the dependencies for generating teh executable file.
# All the .c files are convered to .o file by the 
OBJECT	= ${SOURCE:.c=.o}
# Make all the preprocessed files.
PREPRO	= ${SOURCE:.c=.i}
# Make all the assembly files.
ASMFILE	= ${SOURCE:.c=.s}
# Make all the object dump files.
OBJDMP	= ${SOURCE:.c=.dep}

ifeq ($(ARCH),BBB)
	CC=arm-linux-gnueabihf-gcc $(build)
else ifeq ($(ARCH), HOST)
	cc = gcc 
else ifeq ($(ARCH),FRDM)
	CC=arm-none-eabi-gcc
        CROSS = 
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
	$(CC) $(PREPRO)

%.i : 
	$(CC) -E $<

#Target for generating all asm files.
asm-file:
	$(CC) $(ASMFILE)

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
	$(COPY) $(OUT) $(BBBIP)
	

#Target clean for deleting all the generated files.
clean :
	-rm -f $(OUT) $(OBJECT) $(OUT).map 
