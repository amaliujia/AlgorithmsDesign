# Makefile for Deferred-split R-tree (DR) executable

# Directories...
BINDIR		= ../bin
LIBDIR		= ../lib
INCDIR1		= ../libsrc/include 
INCDIR2		= ../include 

# Aliases...
LIB		= dr
MAIN		= DRmain

# Link Flags...
LDLIBS		= -l$(LIB) -lm
LDFLAGS		= -L$(LIBDIR)

# Compile Flags...
CFLAGS		= -g -I$(INCDIR1)  -I$(INCDIR2)
CC		= gcc

# Targets...
all:		$(MAIN)
		mv $? $(BINDIR)

clean:
		\rm -f *.o *~
		\rm -rf *.dSYM

spotless: clean
