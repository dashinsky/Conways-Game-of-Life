# gcc is for the compiler for C
PP := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c11 $(FLAGS)

# Folder Variables
SRC := src
INC := include
OBJ := objects
EXE := exe

# Folders for objects and executables
initialize:
	mkdir $(OBJ) $(EXE)

# Create the Life object
$(OBJ)/life.o: $(SRC)/life.c
		$(PP) $(CFLAGS) -c $(SRC)/life.c -o $@

# Create the PC02 object
$(OBJ)/PC02.o: $(SRC)/PC02.c
		$(PP) $(CFLAGS) -c $(SRC)/PC02.c -o $@

# Life and PC02 objects
PC02_objs := $(OBJ)/PC02.o $(OBJ)/life.o

# Singly Linked List Executable and Run
PC02: $(PC02_objs)
	$(PP) $(CFLAGS) -o $(EXE)/PC02 $(PC02_objs)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
