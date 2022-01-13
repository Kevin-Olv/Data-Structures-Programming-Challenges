/**********************************
 * Name: Kevin Olvera
 * Email: kolvera@nd.edu
 * File Name: JKFF.h
 * Date Created: 10/28/2021
 * File Contents: This file contains the header definitions for PC06
 **********************************/

#ifndef JKFF_H
#define JKFF_H

class JKFF{
    private:
        bool Q;
        bool NotQ;
    public:
        JKFF();
        void updateVals(bool CLK, bool J_in, bool K_in);
        bool get_Q() const;
        bool get_NotQ();
};
#endif