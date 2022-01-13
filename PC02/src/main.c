/**********************************
 * Name: Kevin Olvera
 * Email: kolvera@nd.edu
 * File Name: main.c
 * Date Created: Tues Sep 16, 2021
 * File Contents: This file contains the main driver function 
 *                for Programming Challenge 02
 **********************************/

#include "../include/rotations.h"

int main(){

    int len;
    int rot;
    char dir;

    char YN ='y';
    int scan_count;

    //int* arr = (int*) malloc(sizeof(int) * (long unsigned int) len);

    while(YN =='y') {
        printf("Enter size, number of rotations, and direction: ");
        scanf("%d %d %c", &len, &rot, &dir);

        if (len < 1 || rot < 0 || (dir != 'L' && dir != 'R')) {
            fprintf(stderr, "Invalid Input: Please enter a valid value\n");
            continue;
        }

        int* arr = (int*) malloc(sizeof(int) * (long unsigned int) len);

        printf("Enter the %d values: ", len);

        scan_count = 0;
        while(scan_count < len) {
            scan_count += scanf(" %d", &arr[scan_count]);
        }

        printf("\nBefore Rotation\n");
        orig_arr(arr, len);

        printf("\nAfter Rotation\n");
        rot_arr(arr, dir, len, rot);

        free(arr);

        do {
            printf("Would you like to continue? (y/n): ");
            scanf(" %c", &YN);
        } while(YN != 'y' && YN != 'n');
    }

    return 0;
}