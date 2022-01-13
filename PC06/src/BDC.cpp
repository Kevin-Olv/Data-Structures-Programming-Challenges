/**********************************
 * Name: Kevin Olvera
 * Email: kolvera@nd.edu
 * File Name: BDC.cpp
 * Date Created: 10/27/2021
 * File Contents: This file contains the functions for PC06
 **********************************/

#include "../include/BDC.h"
#include "../include/JKFF.h"
#include <iostream>
#include <fstream>

bool AND::calc_and(bool Ain, bool Bin){
    A = Ain;
    B = Bin;
    return A & B;
}

bool AND::get_and() const {
    return A & B;
}

bool OR::calc_or(bool Ain, bool Bin){
    A = Ain;
    B = Bin;
    return A | B;   
}

bool OR::get_or() const {
    return A | B;
}

bool NOT::calc_not(bool Ain){
    In = Ain;
    return !In;
}

bool NOT::get_NotQ() const {
    return !In;
}

void BDC::count(bool clk, bool updown) {
    ff1.updateVals(clk, true, true);

    NOT n1;
    n1.calc_not(updown);

    AND and_0;
    and_0.calc_and(n1.get_NotQ(), ff1.get_NotQ());

    AND and_1;
    and_1.calc_and(updown, ff1.get_Q());

    OR or_0;
    or_0.calc_or(and_0.get_and(), and_1.get_and());

    ff2.updateVals(clk, or_0.get_or(), or_0.get_or());

    AND and_2;
    and_2.calc_and(and_0.get_and(), ff2.get_NotQ());

    AND and_3;
    and_3.calc_and(and_1.get_and(), ff2.get_Q());

    OR or_1;
    or_1.calc_or(and_2.get_and(), and_3.get_and());

    ff3.updateVals(clk, or_1.get_or(), or_1.get_or());

    AND and_4;
    and_4.calc_and(and_2.get_and(), ff3.get_NotQ());

    AND and_5;
    and_5.calc_and(and_3.get_and(), ff3.get_Q());

    OR or_2;
    or_2.calc_or(and_4.get_and(), and_5.get_and());

    ff4.updateVals(clk, or_2.get_or(), or_2.get_or());
}

BDC::BDC() : ff1(), ff2(), ff3(), ff4() {}

unsigned int BDC::get_value() const {
    return 8*ff4.get_Q() + 4*ff3.get_Q() + 2*ff2.get_Q() + ff1.get_Q();
}

std::ostream& operator<<(std::ostream& output, const BDC& bdc) {
    output << bdc.ff4.get_Q() << " " << bdc.ff3.get_Q() << " " << bdc.ff2.get_Q() << " " << bdc.ff1.get_Q() << " " << bdc.get_value();
    return output;
}