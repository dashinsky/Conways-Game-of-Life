#include <stdio.h>
#include <stdlib.h>

#include "../include/life.h"

#define BOARD_WIDTH  70
#define BOARD_HEIGHT 30

int main( const int argc, const char* argv[] ) 
{
	// Check the input format
	if ( argc != 4 ) fprintf(stdout, "Incorrect Number of Inputs\n");

	else {

		// Initializing the board
		char board[BOARD_HEIGHT][BOARD_WIDTH];
	
		// Setting up the initial configuration of the board
		read_file( board, argv[1] );

		// Getting the number of generations
		int num_plays, play;
		num_plays = get_num_plays( argv[2] );

		for (play=1; play<=num_plays; ++play) {
			
			// Clearing the screen
			fprintf (stdout, "\033[H\033[J");

			// Printing the current board & playing one generation
			fprintf(stdout, "Generation %d\n", play);
			play_generation( board );
			print_board( board );
		}
	
	// Prints the final board to the file
	print_to_file( board, argv[3] );

	}

	return 0;
}
