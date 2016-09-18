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
CFLAGS	= -Wall -std=c99 -g -O0 -I $(HDRPATH) -Wl,-Map=$(OUT).map

COPY = scp
BBBIP = root@192.168.7.2:/home/debian/bin/vikhyat

LIB = libproject1.a

#The macro is defined to specify the final executable output file name.
OUT = project

#The macro OBJECT contains all the .o files which are the dependencies for generating teh executable file.
# All the .c files are convered to .o file by the 
.PHONY = OBJECT
OBJECT	= ${SOURCE:.c=.o}

# Make all the preprocessed files.
.PHONY = PREPRO
PREPRO	= ${SOURCE:.c=.i}

# Make all the assembly files.
.PHONY = ASMFILE
ASMFILE	= ${SOURCE:.c=.s}

# Make all dependency files

ifeq ($(ARCH),BBB)
	CC=arm-linux-gnueabihf-gcc $(build)
else ifeq ($(ARCH), HOST)
	cc = gcc 
else ifeq ($(ARCH),FRDM)
	CC=arm-none-eabi-gcc
        CROSS = --specs=rdimon.specs
else
	CC = gcc
endif

#Remove the default sufix rules.
.SUFFIXES :
#making our own suffix rules.
# $< makes sure that the rule runs for all the changed files only.
.SUFFIXES: .o .c
.c.o : $(SOURCE)
	$(CC) $(CFLAGS) -c $^

#Throw a warning for undefined platforms
.DEFAULT : $(SOURCE)
	@echo "No platform specified.Building for HOST platform"
	@echo "please use BBB for beaglebone, HOST for host machine and FRDM for freedom board"
	$(CC) $(CFLAGS) -o $(OUT) $^

#Target for generating all preprocessed output files.
.PHONY : Preprocess
Preprocess:
	make $(PREPRO)

%.i : 
	$(CC) -E $<

#Target for generating all asm files.
.PHONY : asm-file
asm-file:
	make $(ASMFILE)

%.S :
	$(CC) -S $<

%.o :
	$(CC) -c $<

.PHONY : compile-all
compile-all: $(SOURCE)
	$(CC) $(CFLAGS) -c $^

.PHONY : build
build: $(SOURCE)
	$(CC) $(CROSS) $(CFLAGS) -o  $(OUT)  $^
	size -B $(OUT)

.PHONY : build-lib
build-lib : 
	ar -r $(LIB)  $(OBJECT)

.PHONY : OBJECT
OBJECT : $(HEADER)

.PHONY : upload
upload:
	$(COPY) $(OUT) $(BBBIP)
	

#Target clean for deleting all the generated files.
.PHONY : clean
clean :
	-rm -f $(OUT) $(OBJECT)  $(LIB) $(OUT).map 
