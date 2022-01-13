/**********************************
 * Name: Kevin Olvera
 * Email: kolvera@nd.edu
 * File Name: PC01.c
 * Date Created: Tues Sep 7, 2021
 * File Contents: Contains the main driver function
 *                for Programming Challenge 01
 **********************************/

#include "sudoku.h"

int main( const int argc, const char* argv[] ){
	
	//Check if 2 arguments were entered. If not, return error
	if(argc != 2) {
		fprintf(stderr, "Error - Needs two arguments\n");
		exit(EXIT_FAILURE);
	}
	//Check if file can be opened. If not, return error
	if(argv[1] == NULL) {
		fprintf(stdout,"File cannot be opened\n");
		exit(EXIT_FAILURE);
	}

	FILE *in_file = fopen(argv[1], "r");				//Open file

	int** sudoku = (int **)malloc(ROWS * sizeof(int*));	//Allocate memory for sudo

	malloc_puzzle(sudoku); 				//allocate int array pointer
	read_puzzle(sudoku, in_file);		//read through the puzzle

	int menu_choice;

	//Present user with game menu
	while(check_puzzle(sudoku) == 0) {
		printf("Choose one:\n1: Print the current puzzle\n2: Try to update a value\n4: Terminate the program\n");
		scanf("%d", &menu_choice);

		switch(menu_choice) {	//Gives user options to play sudoku
			case 1:
				print_puzzle(sudoku);
				break;
			case 2:
				insert_and_check_puzzle(sudoku);
				break;
			case 4:
				fclose(in_file);
				free_puzzle(sudoku);
				free(sudoku);
				printf("Goodbye\n");
				return 1;
				break;
			default:
				printf("That is not an option\n");
		}
	}

	printf("Great job! You successfuly completed the sudoku\n");
	print_puzzle(sudoku);

	fclose(in_file);

	free_puzzle(sudoku);
	free(sudoku);

	return 0;
}