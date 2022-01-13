/*
# Name: Kevin Olvera
# Email: kolvera@nd.edu
# File Name: PC07funcs.cpp
# Date Created: 11/10/2021
# File Contents: This file contains the functions for PC07
#################################*/

#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>
#include "../include/PC07funcs.h"

void read_in(std::ifstream& file, std::vector<std::string>& vect) {
    std::string in;
    while(file >> in) {
        vect.push_back(in);
    }
}

bool is_permutation(std::string& s){
    std::unordered_map<char, int> unordMap;
    int odds = 0;

    char lower;
    for(char c : s) {
        lower = (char) std::tolower(c);
        if(unordMap.find(lower) == unordMap.end()) {
            unordMap[lower] = 1;
            odds += 1;
        }
        else {
            unordMap[lower] += 1;

            if (unordMap[lower] % 2 == 0) {
                odds -= 1;
            }
            else {
                odds += 1;
            }
        }
    }

    if (odds == 1 || odds == 0)
        return true;

    return false;
}

void testPermutations(std::vector<std::string>& vect) {
    bool t;
    std::ofstream file("output.txt");
    std::string outString;

    for(std::string s : vect) {
        t = is_permutation(s);
        if (t)
            outString = "\"" + s + "\"" + " is a palindrome permutation";
        else
            outString = "\"" + s + "\"" + " is not a palindrome permutation";
        
        write_out(file, outString);
    }
    file.close();
}

void write_out(std::ofstream& file, std::string& s) {
    file << s << std::endl;
}