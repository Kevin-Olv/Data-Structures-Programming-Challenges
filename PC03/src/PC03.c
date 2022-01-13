/**********************************
 * Name: Kevin Olvera
 * Email: kolvera@nd.edu
 * File Name: PC03.c
 * Date Created: Tues Sep 22, 2021
 * File Contents: This file contains the main driver function 
 *                for Programming Challenge 03
 *************************************/

#include "../include/sllist.h"

int main(int argc, char* argv[]) {

    sllist* list = malloc(sizeof(sllist));

    int i;
    for(i = 1; i < argc; i++) {
        insert(list, atoi(argv[i]));
    }

    printf("Initial List:\n");
    print_list(list->head_node);

    flip(list);

    printf("Reversed List:\n");
    print_list(list->head_node);

    destructor(list->head_node);
    free(list);

    return 0;

}