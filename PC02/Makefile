# Name: Kevin Olvera
# Email: kolvera@nd.edu
# File Name: Makefile
# Date Created: Tues Sept 16, 2021
# File Contents: This is the Makefile for compilation of Programming Challenge 02

# gcc is for the compiler for C
PP := gcc

OBJ := objects
EXE := exe
SRC := src

# FLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm


PC02_objs := $(OBJ)/rotations.o $(OBJ)/main.o

initialize:
	mkdir $(OBJ) $(EXE)


$(OBJ)/main.o: $(SRC)/main.c 
	$(PP) $(FLAGS) -c $(SRC)/main.c -o $(OBJ)/main.o

$(OBJ)/rotations.o: $(SRC)/rotations.c 
	$(PP) $(FLAGS) -c $(SRC)/rotations.c -o $(OBJ)/rotations.o

PC02: $(PC02_objs)
	$(PP) $(FLAGS) -o $(EXE)/PC02 $(PC02_objs)

# Make Clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
