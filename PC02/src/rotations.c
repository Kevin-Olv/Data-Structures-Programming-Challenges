/**********************************
 * Name: Kevin Olvera
 * Email: kolvera@nd.edu
 * File Name: rotations.c
 * Date Created: Tues Sep 16, 2021
 * File Contents: This file contains the function definitions 
 *                for Programming Challenge 02
 **********************************/

#include "../include/rotations.h"

void orig_arr(int* arr, int len) {
    int iter;
    for(iter = 0; iter < len; iter++) {
        printf("%d at %p\n", arr[iter], &arr[iter]);
    }
}

void rot_arr(int* arr, char dir, int len, int rot) {

    rot %= len;

    int i, j;
    for(i = 0; i < len; i++) {
        if(dir == 'R')  {
            j = i - rot;
            if(j < 0) j += len;
        } 
        else {
            j= i + rot;
            if(j > len-1) j -= (len);
        }

        printf("%d at %p\n", arr[j], arr+j);
    }
}