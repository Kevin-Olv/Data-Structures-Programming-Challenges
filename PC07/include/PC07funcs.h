/*
# Name: Kevin Olvera
# Email: kolvera@nd.edu
# File Name: PC07funcs.h
# Date Created: 11/10/2021
# File Contents: This file contains the function headers for PC07
#################################*/

void read_in(std::ifstream& file, std::vector<std::string>& vect);
bool is_permutation(std::string& s);
void testPermutations(std::vector<std::string>& vect);
void write_out(std::ofstream& file, std::string& s);