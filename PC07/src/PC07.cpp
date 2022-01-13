/*
# Name: Kevin Olvera
# Email: kolvera@nd.edu
# File Name: PC07.cpp
# Date Created: 11/10/2021
# File Contents: This file contains is the main driver for PC07
#################################*/

#include <iostream>
#include <fstream>
#include <vector>
#include "../include/PC07funcs.h"

int main(int argc, char** argv) {

    if(argc != 2) {
        std::cout << "Invalid number of args" << std:: endl;
        return 1;
    }

    std::ifstream file(argv[1]);

    if(!file) {
        std::cout <<argv[1] << " does not exist" << std::endl;
        return 1;
    }

    std::vector<std::string> vect;

    read_in(file, vect);
    testPermutations(vect);
    file.close();
    
    return 0;

}