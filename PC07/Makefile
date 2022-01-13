###############################
# Name: Kevin Olvera
# Email: kolvera@nd.edu
# File Name: Makefile
# Date Created: 11/10/2021
# File Contents: This file is the Makefile for PC07
#################################

# g++ is for the GCC compiler for C++
PP := g++

# FLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

#Folder Variables
SRC := src
INC := include
OBJ := objects
EXE := exe

initialize:
	mkdir $(OBJ) $(EXE)

$(OBJ)/PC07.o: $(SRC)/PC07.cpp 
	$(PP) $(CXXFLAGS) -o $@ -c $(SRC)/PC07.cpp

$(OBJ)/PC07funcs.o: $(SRC)/PC07funcs.cpp 
	$(PP) $(CXXFLAGS) -o $@ -c $(SRC)/PC07funcs.cpp

PC07_objs := $(OBJ)/PC07funcs.o $(OBJ)/PC07.o

PC07: $(PC07_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/PC07 $(PC07_objs)

clean:
	rm $(OBJ)/* $(EXE)/*