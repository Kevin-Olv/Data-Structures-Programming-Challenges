/**********************************
 * Name: Kevin Olvera
 * Email: kolvera@nd.edu
 * File Name: sllist.c
 * Date Created: Tues Sep 22, 2021
 * File Contents: This file contains the function definitions 
 *                for Programming Challenge 03
 * 
 * Citations: Most of the code was co-developed as a class
 * in lectures 10 and 11
 **********************************/

#include "../include/sllist.h"

#include <stdio.h>
#include <stdlib.h>

// Step 6 - Create the constructor method for sllist 
void insert( sllist* the_list, int the_value ){
	
	// Create a sll_node pointer called insert_node
	sll_node* insert_node = (sll_node*)malloc( sizeof(sll_node) );
	
	// Set the insert_node's data to the_value and next_node to NULL 
	insert_node->data = the_value;
	insert_node->next_node = NULL;
	
	// Dr. Morrison's Golden Rule of Pointers 
	// Check if the list is empty
	if( the_list->head_node == NULL ){
		
		// Set the head node equal to insert_node 
		the_list->head_node = insert_node;
		
		// And return
		return;
	}
	
	// Otherwise, create a curr_ptr equal to the head_node 
	sll_node* curr_ptr = the_list->head_node;
	
	// Iterate until the next_node is NULL
	while( curr_ptr->next_node != NULL ){
		
		curr_ptr = curr_ptr->next_node;
	}
	
	// Set curr_ptr's next_node equal to insert_node
	curr_ptr->next_node = insert_node;
	
}

// Step 13 - Push Front 
void push_front( sllist* the_list, int the_value ){
	
	// 13 - 1 We can copy everything up through the empty head node from Insert 
	
	// Create a sll_node pointer called insert_node
	sll_node* insert_node = (sll_node*)malloc( sizeof(sll_node) );
	
	// Set the insert_node's data to the_value and next_node to NULL 
	insert_node->data = the_value;
	insert_node->next_node = NULL;
	
	// Dr. Morrison's Golden Rule of Pointers 
	// Check if the list is empty
	if( the_list->head_node == NULL ){
		
		// Set the head node equal to insert_node 
		the_list->head_node = insert_node;
		
		// And return
		return;
	}
	
	// 13-2 Now we just need to use a reference pointer and put them in front
	sll_node* reference = the_list->head_node;
	
	// Set the head_node to the new node 
	the_list->head_node = insert_node;
	
	// Set the new head_node's next to the reference 
	the_list->head_node->next_node = reference;
	
}

// Step 8 - Print the Singly Linked List 
void print_list( sll_node* head_node ){
	
	// We can just copy and paste from sllist_part2.c
	
	// Just change node_0 to head_node

	sll_node* curr_ptr = head_node;
	while( curr_ptr != NULL ){
		
		// Step 17 - Only print the value
		fprintf( stdout, "%d %p\n ", curr_ptr->data, curr_ptr );		

		// Iterate through the next node
		curr_ptr = curr_ptr->next_node;

	}
	fprintf( stdout, "\n" );

}	


// Step 10 - Free all the elements 
void destructor( sll_node* curr_ptr ){
	
	// Dr. Morrison's Golden Rule of Pointers 
	if( curr_ptr == NULL )
		return;
	

	// Recursively call destructor on the next node  
	destructor( curr_ptr->next_node );
		
	// Free the current pointer 
	free( curr_ptr );
	
}


// Step 15 - Pop Front 
void pop_front( sllist* the_list ){
	
	// Check if the list is not empty
	if( the_list->head_node == NULL )
		return;
	
	// Otherwise, move the node and free
	// Set a reference pointer to head_node
	sll_node* reference = the_list->head_node;
	
	// Set the head_node to head_node's next_node;
	the_list->head_node = the_list->head_node->next_node;
	
	// Free the reference 
	free( reference );
	
}
void flip(sllist* list) {
    sll_node* curr = list->head_node;
    sll_node* prev = NULL;
    sll_node* next = list->head_node;

    while(curr != NULL) {
        next = curr->next_node;

        curr->next_node = prev;

        prev = curr;

        curr = next;
    }

    list->head_node = prev;
}

