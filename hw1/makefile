
CFLAGS	= -g
LD	= $(CC)
LDFLAGS	=

RM	= rm
ECHO	= echo

EXE	= mainx
SRCS	= main.c hw1.c
OBJS	= ${SRCS:.c=.o}

VPATH	= ./hw1

.SUFFIXES:
.SUFFIXES: .o .c

.c.o :
	@$(ECHO) "===== .c -> .o rule"
	$(CC) $(CFLAGS) -c $<

# do this for undefined target
.DEFAULT :
	@$(MAKE) help

help :
	@$(ECHO) "please call 'make xxx' where xxx=linuxHost|BBB|FR25z"
	

all : $(EXE)


linuxHost :
	$(MAKE) $(MFLAGS) CC=gcc LD=gcc	   			all

BBB :
	$(MAKE) $(MFLAGS) CC=arm-linux-gnueabi-gcc LD=segldr	all

FR25z :
	$(MAKE) $(MFLAGS) CC=xlc LD=ld				all

$(EXE) : $(OBJS)
	$(LD) -o $@ $(OBJS)

$(OBJS) : hw1.h

clean :
	-$(RM) -f $(EXE) $(OBJS)
