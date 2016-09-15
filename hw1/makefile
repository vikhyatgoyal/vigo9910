CC=gcc
ARMCC = arm-linux-gnueabi-gcc
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

all : $(EXE)

$(EXE) : $(OBJS)
	$(LD) -o $@ $(OBJS)

$(OBJS) : hw1.h

clean :
	-$(RM) -f $(EXE) $(OBJS)
