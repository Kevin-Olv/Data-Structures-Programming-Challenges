# Name: Kevin Olvera
# Email: kolvera@nd.edu
# File Name: Makefile
# Date Created: Tues Sept 7, 2021
# File Contents: This is the Makefile for compilation of Programming Challenge 01

# gcc is for the compiler for C
PP := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm

PC01.o: PC01.c 
	$(PP) $(FLAGS) -c PC01.c 

sudoku.o: sudoku.c 
	$(PP) $(FLAGS) -c sudoku.c 

PC01_objs:= PC01.o sudoku.o 

PC01: $(PC01_objs)
	$(PP) $(FLAGS) -o PC01 $(PC01_objs)

# Make Clean
clean:
	rm -rf *.o PC01

