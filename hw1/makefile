#********************************************************************************************************************
# Description:
#  This is the makefile for cross compiling on the three targets listed below:					
#  1) Linux based host machine.
#  2) BeagleBone Black Board
#  3) Freadom board FRDM KL25z.
# Author: Vikhyat Goyal
#********************************************************************************************************************


# Defining all the flags which we which to be included in teh compile process.
# -wall flag enables displaying of all the warnings.
CFLAGS	= -Wall

#COMPILER is a macro created to specify the type of compiler used depending on the platform.
COMPILER= $(CC)

#The macro is defined to specify the final executable output file name.
OUT	= main

#The macro SOURCE contains all teh .c files which we are interested in compiling.
SOURCE	= main.c hw1.c

#Macro for all the header files which are the prerequites for compilation.
HEADER = hw1.h

#The macro OBJECT contains all the .o files which are the dependencies for generating teh executable file.
# All the .c files are convered to .o file by the 
OBJECT	= ${SOURCE:.c=.o}

#Specify the directories to be checked.
VPATH	= ./hw1

#Remove the default sufix rules.
.SUFFIXES :
#making our own suffix rules.
# $< makes sure that the rule runs for all the changed files ony.
.SUFFIXES: .o .c
.c.o :
	$(COMPILER) $(CFLAGS) -c $<

#Throw a warning for undefined platforms
.DEFAULT :
	@$(MAKE) warning

warning :
	@echo "please call 'make xxx' where xxx=linuxHost|BBB|FR25z"
	
#Target for host machine with linux. This uses gcc compiler.
linuxHost :
	$(MAKE) $(MFLAGS) CC=gcc $(OUT)

#Target for Beagle bone board. this uses ARM-LINUX compiler.
BBB :
	$(MAKE) $(MFLAGS) CC=arm-linux-gnueabihf-gcc	$(OUT)
#Target for FRDM KL25z board. this uses ARM-none compiler. 
FRDMKL25z :
	$(MAKE) $(MFLAGS) CC=arm-none-eabi-gcc $(OUT)

#Target for rules to generate the executable file. The prerequisites are object files.
$(OUT) : $(OBJECT)
	$(COMPILER) -o $@ $(OBJECT)
#Target for object file generation. Prerequsites are the header files
$(OBJECT) : $(HEADER)

#Target clean for deleting all the generated files.
clean :
	-rm -f $(OUT) $(OBJECT)
