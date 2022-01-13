/**********************************
 * Name: Kevin Olvera
 * Email: kolvera@nd.edu
 * File Name: sllist.h
 * Date Created: Sept 22, 2021
 * File Contents: This file contains the function declarations  
 *                for Programming Challenge 03
 **********************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct sll_node{

	int data;
	struct sll_node* next_node;	
	
}sll_node;

typedef struct sllist{

	// Make the private sll_node member called head_node
	struct sll_node* head_node;
	
}sllist;

void insert( sllist* the_list, int);
void print_list(sll_node* head_node);
void flip(sllist* list);
void destructor( sll_node* curr_ptr );