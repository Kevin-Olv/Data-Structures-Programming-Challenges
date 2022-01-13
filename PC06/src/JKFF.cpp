/**********************************
 * Name: Kevin Olvera
 * Email: kolvera@nd.edu
 * File Name: JKFF.cpp
 * Date Created: 10/27/2021
 * File Contents: This file contains the functions for PC06
 **********************************/

#include "../include/JKFF.h"

JKFF::JKFF(): Q(false), NotQ(true) {}

void JKFF::updateVals(bool CLK, bool J_in, bool K_in) {
    if(!CLK) {
        return;
    }
    else if(J_in && !K_in) {
        Q = 1;
        NotQ = 0;
    }
    else if(!J_in && K_in) {
        Q = 0;
        NotQ = 1;
    }
    else if(J_in && K_in) {
        bool temp = Q;
        Q = NotQ;
        NotQ = temp;
    }
    return;
}

bool JKFF::get_Q() const{
    return Q;
}

bool JKFF::get_NotQ(){
    return NotQ;
}