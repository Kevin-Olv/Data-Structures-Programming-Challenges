/**********************************
 * Name: Kevin Olvera
 * Email: kolvera@nd.edu
 * File Name: BDC.h
 * Date Created: 10/28/2021
 * File Contents: This file contains the header definitions for PC06
 **********************************/
#ifndef BDC_H
#define BDC_H
#include "../include/JKFF.h"
#include <iostream>
#include <fstream>

struct AND {
    bool A;
    bool B;

    bool calc_and(bool Ain, bool Bin);

    bool get_and() const;
};

struct OR {
    bool A;
    bool B;

    bool calc_or(bool Ain, bool Bin);

    bool get_or() const;   
};

struct NOT {
    bool In;

    bool calc_not(bool Ain);

    bool get_NotQ() const;   
};

class BDC {
    private:
        JKFF ff1;
        JKFF ff2;
        JKFF ff3;
        JKFF ff4;
        unsigned int get_value() const;
    public:
        BDC();
        void count(bool clk, bool up_down);
        friend std::ostream& operator<<(std::ostream& output, const BDC& bdc);
};
#endif