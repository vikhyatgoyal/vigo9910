#********************************************************************************************************************
# Description:
#  This is the makefile for cross compiling on the three targets listed below:					
#  1) Linux based host machine.
#  2) BeagleBone Black Board
#  3) Freadom board FRDM KL25z.
# Author: Vikhyat Goyal
# Date: 09/15/2016
#********************************************************************************************************************

include source.mk
CC = gcc
#C99 standard supported.
CFLAGS	= -Wall -std=c99 -g -O0 -I $(HDRPATH) -Wl,-Map=$(OUT).map

COPY = scp
#Path for source dumping in case of BBB
BBBIP = root@192.168.7.2:/home/debian/bin/release
#Generated object file liberary
LIB = libproject1.a

#The final executable output file name.
OUT = project

#The macro OBJECT contains all the .o files which are the dependencies for generating the executable file.
# All the .c files are convered to .o file by the 
OBJECT:= ${SOURCE:.c=.o}

# Make all the preprocessed files.
PREPRO:= ${SOURCE:.c=.i}

# Make all the assembly files.
ASMFILE:= ${SOURCE:.c=.s}

# Make all the assembly files.
DEPEND:= ${SOURCE:.c=.dep}

ifeq ($(ARCH),BBB)
	#Compiler for Beagle bone board with linux OS
	CC=arm-linux-gnueabihf-gcc
else ifeq ($(ARCH), HOST)
	#Host machine compiler
	cc = gcc	
	ARFLAG =	
else ifeq ($(ARCH),FRDM)
	#Freedom board compiler, No OS.
	CC=arm-none-eabi-gcc
	#flags required for compilation with no file system support for a OS board
        CROSS = --specs=rdimon.specs
	ARFLAG = -mthumb -mcpu=cortex-m0plus
else
	#Requirement: Build for HOST in case no platform is specified by user.
	CC = gcc
endif


#Throw a warning for undefined platforms
.DEFAULT : $(SOURCE)
	@echo "No platform specified.Building for HOST platform"
	@echo "please use BBB for beaglebone, HOST for host machine and FRDM for freedom board"
	$(CC) $(CFLAGS) -o $(OUT) $^

#Target for generating all preprocessed output files.
.PHONY : Preprocess
Preprocess:$(SOURCE)
	make $(PREPRO)

#Suffix rule for generating dependency output file for a given source file.
%.dep: %.c
	$(CC) -I $(HDRPATH) -MM $< -o $@

#Suffix rule for generating preprocessed output file for a given source file.
%.i : %.c 
	$(CC) -I $(HDRPATH) -E $< -o $@

#Target for generating all assembly files.
.PHONY : asm-file
asm-file:
	make $(ASMFILE)

#Suffix rule for generating assembly output file for a given source file.
%.S :  %.c
	$(CC) $(CFLAGS) -I $(HDRPATH) -S $< -o $@

ifeq ($(USCMD),OBJECTDUMP)
#Suffix rule for generating object output file for a given source file.
%.o : %.c
	$(CC) $(CFLAGS) -I $(HDRPATH) -c $<
	objdump -s $@	
else
#Suffix rule for generating object output file for a given source file.
%.o : %.c
	$(CC) $(CFLAGS) -I $(HDRPATH) -c $<
endif

#Target for generating object files for all the source files specified in SOURCE.
.PHONY : compile-all
compile-all: $(SOURCE)
	$(CC) $(CFLAGS) -c $^

ifeq ($(USCMD),ARV)
#Target for generating executable file and the .dep files.
.PHONY : build
build: $(SOURCE)
	$(CC) $(CROSS) $(CFLAGS) -o  $(OUT)  $^
	make $(DEPEND)
	#Display the size of output executable
	size -B $(OUT)
	ar -r $(LIB)  $(DUMPOBJ)
else
#Target for generating executable file and the .dep files.
.PHONY : build
build: $(SOURCE)
	$(CC) $(CROSS) $(CFLAGS) -o -v  $(OUT)  $^
	make $(DEPEND)
	#Display the size of output executable
	size -B $(OUT)
endif


#Target for archiving all the object files into a liberary.
.PHONY : build-lib
build-lib : 
	make $(OBJECT)
	ar -r $(LIB)  $(DUMPOBJ)

#Target for dumping all the object files onto the terminal.
.PHONY : OBJDUMP
OBJDUMP:$(SOURCE)
	#make clean makes sure that all the object files are created again and dumped.
	make clean
	#Generate object files
	$(CC) $(CFLAGS) -c $^
	#Dump the object files
	objdump -s $(OBJECT)	

#Target for dumping the executable file onto the BBB board.
.PHONY : upload
upload:
	ssh root@192.168.7.2 "rm -r /home/debian/bin/release"	
	ssh root@192.168.7.2 "mkdir /home/debian/bin/release"
	$(COPY) $(OUT) $(BBBIP)
	

#Target for deleting all the generated files.
.PHONY : clean
clean :
	-rm -f $(OUT) $(OBJECT) $(PREPRO) $(ASMFILE) $(DEPEND) $(LIB) $(OUT).map
