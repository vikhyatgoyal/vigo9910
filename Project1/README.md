#### This file is to be used for ECEN5013 "Embedded Software Essential" cours"e in University of Colorado, Boulder 
#### The make file is used as a build system with three platform support.
#### The supported platforms are : Linux HOST machine, Beagle Bone Board with linux OS, Freedom FRDM zKL25 board.
#### Author : Vikhyat GOyal & Rishi Soni
#### Date   : 09/17/2016

#### dependencies: 1) The source.mk file should be kept at teh same directory as the makefile.
####		   2) All the .c source files should be kept in the SRC foulder.
####		   3) All the .h source files should be kept in the HDR foulder.

#### executable output:
#### 		   1) The output executable generated is of the name "project"

#### notes:	
####		   1) The Build commands requires the user to input the architecture "ARCH" for which the execuatble needs to be generated.
####		   2) The makefile take HOST architecture as default if teh ARCH value is not specified.
		   

**Adding new .c source files to the build system**

**steps**
1) Place the new .c files in the SRC folder.
2) edit source.mk and modify SOURCE to include the new .c file in the list of source files.

	*format:*
	SOURCE = oldfile1.c oldfile2.c newfile1.c newfile2.c

	*example:*
	 SOURCE = main.c data.c memory.c Project_1.c Project_2.c
3) Save the source.mk file

**Adding new .h header files to the build system**

**steps**
1) Place the new .h files in the HDR folder.
2) edit source.mk and modify HEADER to include the new .h file in the list of source files.

	*format:*
	HEADER = oldfile1.h oldfile2.h newfile1.h newfile2.h

	*example:*
	 HEADER = main.h data.h memory.h Project_1.h Project_2.h
3) Save the source.mk file

**changing or adding the folder path for adding source files from a new location to the build system**

**steps**
1) edit source.mk and modify VPATH to include the new file location.

	*format:*
	 VPATH = olddirectory:/newdirectory:/newdirectory2

	*example:*
	 VPATH = SRC:/PROJSRC
2) Save the source.mk file

**changing or adding the folder path for adding header files from a new location to the build system**

**steps**
1) edit source.mk and modify VPATH to include the new file location.

	*format:*
	 HDRPATH = olddirectory:/newdirectory:/newdirectory2

	*example:*
	 HDRPATH = SRC:/PROJSRC
2) Save the source.mk file

#### The following is a list of all the supported make options provided by this make file.

**Syntax for using makefile options**

**clean**
1) This command delets all the generated files from the directory. It deletes executable output, map files, assembly files, object files,dependency files and the prerocessed files
2) call the target directly with the command "clean"

	*format:*
	 make clean	

**build**
1) This command generates the executable along with the display for size of the generated file on terminal.
2) The build output generated teh .dep files along with the executable file.
2) call the target directly with the command "build" and add the ARCH value to specify the platform for which the output should be generated.
   The values supported by the ARCH variable are as follows:
	HOST - use this for buidling the system for linux machine. It uses gcc compiler.
	BBB  - use this for buidling the system for beagle bone board. It uses arm-linux-gnueabihf-gcc compiler. 
	FRDM - use this for buidling the system for freedom  board. It uses arm-linux-none-gcc compiler.

	*format:*
	 make build ARCH=XXX

	*example:*
	 make build ARCH=HOST

**compile-all**
1) This command generates object files for all the source .c files available in the SOURCE folder but does not link them.
2) call the target directly with command "compile-all"

	*format:*
	 make compile-all

**build-lib**
1) This command generated a liberary file with archived memory.o and data.o files.
2) The archive file is generated in the same path as the makefile.

	*format:*
	 make build-lib

**upload**
1) This command copies the generated executable file into the BBB bin directory.
2) The BBB should be connected with the host machine and the conntection setup with BBB ip 192.168.7.2 and host ip as 192.168.7.1

	*format:*
	 make upload

**%.0**
1) This generates the object file for the .c file specified by the user.The object file is not linked and is creted at teh same directory as the makefile
2) The cammand can be called directly with the .o file to be generated.

	*format:*
	 make example.o

	*example:*
	 make memory.o

**Preprocess**
1) This generates the preprocedded output for all the source files.
2) The cammand can be called directly with make cammand.

	*format:*
	 make Preprocess

**%.i**
1) This generates the preprocedded output for all a specific source file.
2) The cammand can be called with the name of the file to be generated.

	*format:*
	 make example.i

	*example:*
	 make memory.i

**asm-file**
1) This generates the assembly file for all the source files as specified in SOURCE.
2) The cammand can be called directly with make.

	*format:*
	 make asm-file

**%.s**
1) This generates the assembly file output for all a specific source file.
2) The cammand can be called with the name of the file to be generated.

	*format:*
	 make example.s

	*example:*
	 make memory.s

**OBJDUMP**
1) This command dumps all the object files to the terminal.

	*format:*
	 make OBJDUMP

**Using the object dump GNU binutil**
1) The OBJECTDUMP cammand when upended with the object file to be dumped prints the specific object file on teh terminal.
2) Use the make command with OSCMD as OBJECTDUMP

	*format:*
	 make OSCMD=OBJECTDUMP example.o

	*example:*
	 make OSCMD=OBJECTDUMP memory.o

**Using the ar (archive) GNU binutil**
1) The AR cammand given with user cammand USCMD creates a archive with the object files specified in DUMPOBJ.
2) Use the make command with OSCMD as ARV

	*format:*
	 make build OSCMD=ARV

	*example:*
	 make build OSCMD=ARV

#### Executing the build output file

**executing the output**
1) The output file is always named "project"
2) call the execution by using dot-backslash command.

	*format:*
	 ./project



