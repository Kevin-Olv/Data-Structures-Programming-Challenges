/**********************************
 * Name: Kevin Olvera
 * Email: kolvera@nd.edu
 * File Name: BDC_Test.cpp
 * Date Created: 10/27/2021
 * File Contents: This file contains the driver fo PC06
 **********************************/

#include <iostream>
#include <fstream>
#include "../include/BDC.h"

int main(int argc, char*argv[]) {
    if(argc != 2) {
        std::cout << "Incorrect number of inputs" << std::endl;
        return -1;
    }

    std::ifstream fileIn(argv[1]);

    if(!fileIn) {
        std::cout << argv[1] << " does not exist" << std::endl;
        return -1;
    }

    BDC bdc;
    std::cout << "Initial value in main: " << bdc << std::endl;

    bool clk;
    bool updown;
    while(fileIn >> clk >> updown) {
        bdc.count(clk, updown);
        std::cout << bdc << std::endl;
    }

    std::cout << "Final Value in main: " << bdc << std::endl;
    fileIn.close();
    return 0;
}