###############################
# Name: Kevin Olvera
# Email: kolvera@nd.edu
# File Name: Makefile
# Date Created: 10/27/2021
# File Contents: This file is the Makefile for PC06
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

#Initialize folders for the objects
initialize:
	mkdir $(OBJ) $(EXE)

#JKFF Object
$(OBJ)/JKFF.o: $(SRC)/JKFF.cpp 
	$(PP) $(CXXFLAGS) -c $(SRC)/JKFF.cpp -o $@

#JK_Test Object
$(OBJ)/JK_Test.o: $(SRC)/JK_Test.cpp 
	$(PP) $(CXXFLAGS) -c $(SRC)/JK_Test.cpp -o $@

#Objects
JK_objs := $(OBJ)/JKFF.o $(OBJ)/JK_Test.o

#Singly Linked List
JK_Test: $(JK_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/JK_Test $(JK_objs)

#BDC Object
$(OBJ)/BDC.o: $(SRC)/BDC.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/BDC.cpp -o $@

#Create BDC_Test
$(OBJ)/BDC_Test.o: $(SRC)/BDC_Test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/BDC_Test.cpp -o $@

#BDC Objects
BDC_objs := $(OBJ)/BDC.o $(OBJ)/BDC_Test.o $(OBJ)/JKFF.o

#Exe and Run
BDC_Test: $(BDC_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BDC_Test $(BDC_objs)

# Make Clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*