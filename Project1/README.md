#### This file is to be used for ECEN5013 "Embedded Software Essential" course in University of Colorado, Boulder 
#### The make file is used as a build system with three platform support.
#### The supported platforms are : Linux HOST machine, Beagle Bone Board with linux OS, Freedom FRDM KL25z board.
#### Author : Vikhyat Goyal & Rishi Soni
#### Date   : 09/18/2016

#### Dependencies: 1) The source.mk file should be kept at the same directory as the makefile.
####		   2) All the .c source files should be kept in the SRC folder.
####		   3) All the .h source files should be kept in the HDR folder.

#### Executable output:

#### 		   1) The output executable generated is of the name "project"

#### Notes:	
####		   1) The Build commands requires the user to input the architecture "ARCH" for which the execuatble needs to be 			      generated.
####		   2) The makefile take HOST architecture as default if the ARCH value is not specified.
		   

**Adding new .c source files to the build system**

**Steps**

1) Place the new .c files in the SRC folder.
2) Edit source.mk and modify SOURCE to include the new .c file in the list of source files.

**Format:**
	_SOURCE = oldfile1.c oldfile2.c newfile1.c newfile2.c_

**Example:**
	_SOURCE = main.c data.c memory.c Project_1.c Project_2.c_
	
3) Save the source.mk file

**Adding new .c source files to be archived in .lib**

**Steps**

1) Edit source.mk and modify DUMPSRC to include the new .c file in the list of source files.

**Format:**
	_DUMPSRC = oldfile1.c oldfile2.c newfile1.c newfile2.c_

**Example:**
	_DUMPSRC = data.c memory.c Project_1.c Project_2.c_
	 
2) Save the source.mk file

**Adding new .h header files to the build system**

**Steps**

1) Place the new .h files in the HDR folder.
2) edit source.mk and modify HEADER to include the new .h file in the list of source files.

**Format:**
	_HEADER = oldfile1.h oldfile2.h newfile1.h newfile2.h_

**Example:**
	 _HEADER = main.h data.h memory.h Project_1.h Project_2.h_
	 
3) Save the source.mk file

**Changing or adding the folder path for adding source files from a new location to the build system**

**Steps**

1) Edit source.mk and modify VPATH to include the new file location.

**Format:**
	_VPATH = olddirectory:/newdirectory:/newdirectory2_

**Example:**
	 _VPATH = SRC:/PROJSRC_
	 
2) Save the source.mk file

**Changing or adding the folder path for adding header files from a new location to the build system**

**Steps**

1) Edit source.mk and modify VPATH to include the new file location.

**Format:**
	 _HDRPATH = olddirectory:/newdirectory:/newdirectory2_

**Example:**
	 _HDRPATH = SRC:/PROJSRC_
	 
2) Save the source.mk file

#### The following is a list of all the supported make options provided by this make file.

**Syntax for using makefile options**

**__clean__**

1) This command deletes all the generated files from the directory. It deletes the executable outputs, map files, assembly files, object files,dependency files and the prerocessed files.
2) Call the target directly with the command "clean"

**Format:**
	_make clean_

**__build__**

1) This command generates the executable and displays the size of the generated file on the terminal.
2) The build output generates the .dep files along with the executable file.
2) Call the target directly with the command "build" and add the ARCH value to specify the platform for which the output should be generated.
   The values supported by the ARCH variable are as follows:
   
	HOST - use this for building the system for the host Linux machine. It uses the host gcc compiler.
	BBB  - use this for building the system for the BeagleBone Black. It uses the arm-linux-gnueabihf-gcc toolchain. 
	FRDM - use this for buidling the system for the Freescale Freedom KL25Z board. It uses the arm-linux-none-gcc toolchain.

**Format:**
	 _make build ARCH=XXX_

**Example:**
	_make build ARCH=HOST_

**compile-all**

1) This command generates the object files for all the source .c files available in the SOURCE folder but does not link them.
2) Call the target directly with command "compile-all"

**Format:**
	 _make compile-all_

**build-lib**

1) This command generates a library file with archived the 'memory.o' and 'data.o' files.
2) The archive file is generated in the same path as the makefile.

**Format:**
	 _make build-lib_

**upload**

1) This command copies the generated executable file into the BBB bin directory.
2) The BBB should be connected with the host machine and the connection setup with BBB is on the following IP address: 192.168.7.2, with host IP as 192.168.7.1

**Format:**
	 _make upload_

**%.o**

1) This generates the object file for the .c file specified by the user.The object file is not linked and is creted in the same directory as the makefile
2) This command can be called directly along with the .o file to be generated.

**Format:**
	 _make example.o_

**Example:**
	_make memory.o_

**Preprocess**

1) This generates the preprocessed output for all the source files.
2) This command can be called directly with the _make_ command.

**Format:**
	_make Preprocess_

**%.i**

1) This generates the preprocessed output for a specific source file.
2) This command can be called with the name of the file to be generated.

**Format:**
	_make example.i_

**Example:**
	 _make memory.i_

**asm-file**

1) This generates the assembly file for all the source files as specified in the SOURCE variable.
2) This command can be called directly with _make_.

**Format:**
	 _make asm-file_

**%.s**

1) This generates the assembly file output for all a specific source file.
2) This command can be called with the name of the file to be generated.

**Format:**
	_make example.s_

**Example:**
	 _make memory.s_

**OBJDUMP**

1) This command dumps all the object files to the terminal.

**Format:**
	 _make OBJDUMP_

**Using the object dump from the GNU binutil package**
1) The OBJECTDUMP command when upended with the object file to be dumped, prints the specific object file on the terminal.
2) Use the make command with OSCMD as OBJECTDUMP

**Format:**
	 _make OSCMD=OBJECTDUMP example.o_

**Example:*
	 _make OSCMD=OBJECTDUMP memory.o_

**Using ar (archive) from the GNU binutil package**

1) The AR cammand given with the user command USCMD creates a archive with the object files specified in DUMPOBJ.
2) Use the make command with OSCMD as ARV

**Format:**
	 _make build OSCMD=ARV_

**Example:**
	_make build OSCMD=ARV_
	 
**Using compile time switch PROJECT1**

1) The PROJECT 1 compilation should be swiched OFF using the PROJECT1 command.
2) The value OFF should be assigned to disable compilation.
3) By default the compilation is always ON for project1.

**Format:**
	_make build PROJECT1=OFF_
	 
**Using compile time switch TESTMODE**

1) The testing for data files is enabled only when TESTMODE is set as ON
2) By default the compilation is OFF

**Format:**
	 _make build TESTMODE=ON_


#### Executing the build output file

**Executing the output**

1) The output file is always named "project"
2) Call the execution by using dot-backslash command.

**Format:**
	_./project_
