/**********************************
 * Name: Kevin Olvera
 * Email: kolvera@nd.edu
 * File Name: JK_Test.cpp
 * Date Created: 10/27/2021
 * File Contents: This file contains the driver fo PC06
 **********************************/

#include "../include/JKFF.h"
#include <iostream>
#include <cstdlib>
#include <fstream>



int main(const int argc, const char* argv[]) {
    if(argc != 2) {
        std::cout << "Incorrect number of inputs" << std::endl;
        exit(-1);
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cout << argv[1] << " does not exist" << std::endl;
        exit(-1);
    }
    
    JKFF flipflop;
    bool CLK, J_in, K_in;
    while(file >> CLK >> J_in >> K_in) {
        flipflop.updateVals(CLK, J_in, K_in);
        std::cout << flipflop.get_Q() << " " << flipflop.get_NotQ() << std::endl;
    }

    file.close();

    return 0;
}