CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -g

#Directories where the compiler can find things
INCLUDES    = -Iinclude
LIBDIRS     = 
LIBS        = 

# add directory names here if you want to separate files by directories
BINDIR = bin/
SRCDIR = src/

#Put the names of your source code file in the lines below.  

SOURCE = $(SRCDIR)stack.c $(SRCDIR)testFile.c

OBJS    = stack.o testFile.o

PROGNAME = $(BINDIR)runTests

default : testLink

testLink: testCompile
	$(CC) $(LIBDIRS) $(LDFLAGS) -o $(PROGNAME) $(OBJS) $(LIBS)

testCompile: 
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES)

clean:
	@ rm *stack.o testFile.o
