# Name: Kevin Olvera
# Email: kolvera@nd.edu
# File Name: Makefile
# Date Created: Tues Sept 22, 2021
# File Contents: This is the Makefile for compilation of Programming Challenge 03

# gcc is for the compiler for C
PP := gcc

OBJ := objects
EXE := exe
SRC := src

# FLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm


PC03_objs := $(OBJ)/sllist.o $(OBJ)/PC03.o

initialize:
	mkdir $(OBJ) $(EXE)


$(OBJ)/PC03.o: $(SRC)/PC03.c 
	$(PP) $(FLAGS) -c $(SRC)/PC03.c -o $(OBJ)/PC03.o

$(OBJ)/sllist.o: $(SRC)/sllist.c 
	$(PP) $(FLAGS) -c $(SRC)/sllist.c -o $(OBJ)/sllist.o

PC03: $(PC03_objs)
	$(PP) $(FLAGS) -o $(EXE)/PC03 $(PC03_objs)

# Make Clean
clean:
	rm -rf $(OBJ)/ $(EXE)/