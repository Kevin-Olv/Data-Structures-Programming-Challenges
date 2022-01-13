/**********************************
 * Name: Kevin Olvera
 * Email: kolvera@nd.edu
 * File Name: sudoku.c
 * Date Created: Tues Sep 7, 2021
 * File Contents: This file contains the function definitions 
 *                for Programming Challenge 01
 **********************************/

#include "sudoku.h"

//Allocate memory for puzzle
void malloc_puzzle(int** sudoku) {

    long unsigned int i;

    for(i = 0; i<COLS; ++i) {

        sudoku[i] = (int*)malloc(COLS * sizeof(int));
    }
}

//Print the entire puzzle when called
void print_puzzle(int** sudoku) {

    long unsigned int row_iter;
    long unsigned int col_iter;

    for(row_iter = 0; row_iter < ROWS; ++row_iter) {

        for(col_iter = 0; col_iter < COLS; ++col_iter) {
        
            printf("%d ", sudoku[row_iter][col_iter]);
    
        }
        printf("\n");
    }
}

//free memory
void free_puzzle(int** sudoku) {

    long unsigned int i;

    for(i = 0; i<COLS; ++i) {
        
        free(sudoku[i]);
    }

}

// Read in sudoku puzzle from file inputted
void read_puzzle(int** sudoku, FILE* inputfile) {

    long unsigned int row_in = 0;
    long unsigned int col_in = 0;

    while(inputfile != NULL) {
        
        int temp;
        fscanf(inputfile, "%d\n", &temp);

        sudoku[row_in][col_in] = temp;

        if(col_in < COLS - 1)
            col_in++;

        else {
            row_in++;
            col_in = 0;
        }

        if(inputfile->_IO_read_ptr == inputfile->_IO_read_end)
            break;
    }
}

//Check if puzzle is correct
unsigned int check_puzzle(int** sudoku) {

    long unsigned int row_iter;
    long unsigned int col_iter;

    for(row_iter = 0; row_iter < ROWS; ++row_iter) {

        for(col_iter = 0; col_iter < COLS; ++col_iter) {

                if(sudoku[row_iter][col_iter] == 0)
                    return 0;
        }
    }    
    return 1;
}

//Insert the users values and check if it works
void insert_and_check_puzzle(int** sudoku) {

    int val;
    long unsigned int row;
    long unsigned int col;

    printf("Enter the value, row, and column:  ");
    scanf("%d %lu %lu", &val, &row, &col);

    //Check inputs for out of bounds errors
    if(val < 1 || val > 9) {
        fprintf(stderr, "The value must be between 1 and 9, you entered %d\n", val);
        return;
    }

    if(row > 8) {
        fprintf(stderr, "The row must be between 1 and 9, you entered %lu\n", row);
        return;
    }

    if(col > 8) {
        fprintf(stderr, "The column must be between 1 and 9, you entered %lu\n", col);
        return;        
    }
    // Check to see if that number is already in that row/column
    int i;
    for(i = 0; i < ROWS; ++i) {
            if(sudoku[i][col] == val){
                printf("There is already a %d at (%d, %lu)\n", val, i, col);
                return;
            }
    }

    for(i = 0; i < COLS; ++i) {
            if(sudoku[row][i] == val){
                printf("There is already a %d at (%lu, %d)\n", val, row, i);
                return;
            }
    }   

    int boxR;
    int boxC;
    if(row <= 2 && col <= 2)
    {
        boxR = 1;
        boxC = 1;
    }
    else if(row <= 2 && col >= 3 && col <= 5)
    {
        boxR = 1;
        boxC = 4;
    }
    else if(row <= 2 && col >= 6 && col <= 8)
    {
        boxR = 1;
        boxC = 7;
    }
    else if(row>= 3 && row <= 5 && col <= 2)
    {
        boxR = 4;
        boxC = 1;
    }
    else if(row >= 3 && row <= 5 && col >= 3 && col <=5)
    {
        boxR = 4;
        boxC = 4;
    }
    else if(row >= 3 && row <= 5 && col >= 6 && col <=8)
    {
        boxR = 4;
        boxC = 7;
    }
    else if(row >= 6 && row <= 8 && col <= 2)
    {
        boxR = 7;
        boxC = 1;
    }
    else if(row >= 6 && row <= 8 && col >= 3 && col <= 5)
    {
        boxR = 7;
        boxC = 4;
    }
    else if(row >= 6 && row <= 8 && col >= 6 && col <= 8)
    {
        boxR = 7;
        boxC = 7;
    }

    // int k;
    for(i = boxR-1; i < boxR+2; ++boxR) {
       for(i = boxC-1; i < boxC+2; ++boxC) {
           if(sudoku[row][i] == val)
                return;
        }    
    }


    sudoku[row][col] = val;
    return;

}
