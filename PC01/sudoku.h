/**********************************
 * Name: Kevin Olvera
 * Email: kolvera@nd.edu
 * File Name: sudoku.h
 * Date Created: Sept 9
 * File Contents: This file contains the function declarations  
 *                for Programming Challenge 01
 **********************************/

#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLS 9

void malloc_puzzle(int**);
void free_puzzle(int**);
void read_puzzle(int**, FILE*);
void print_puzzle(int**);
unsigned int check_puzzle(int**);
void insert_and_check_puzzle(int**);

#endif
