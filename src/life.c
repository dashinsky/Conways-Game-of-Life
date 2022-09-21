#include <stdio.h>
#include <stdlib.h>

#include "../include/life.h"

#define BOARD_WIDTH  70
#define BOARD_HEIGHT 30

int get_num_plays( const char *num_plays ) 
{
	return atoi(num_plays);
}

void read_file ( char board[][BOARD_WIDTH], const char *name)
{
	FILE *fptr = fopen(name, "r");
	char temp;
	int row = 0;
	int col = 0;

	while ( 1 ) {

		fscanf(fptr, "%c", &temp);

		if (temp == 10) {
			row++;
			col=0;
		}

		else {
			board[row][col]=temp;
			col++;
		}

		if (feof(fptr)) break;
	}

	fclose(fptr);
}


void play_generation ( char board[][BOARD_WIDTH] )
{
	// Array that will be used to check the neighbors for each cell
	// char temp_board[][BOARD_WIDTH] = board;
	char temp_board[BOARD_HEIGHT][BOARD_WIDTH];
	int x, y, alive;

	for (x=0; x<BOARD_HEIGHT; x++) {
		for (y=0; y<BOARD_WIDTH; y++) {
			temp_board[x][y] = board[x][y];
		}
	}

	for (x=0; x<BOARD_HEIGHT; x++) {
		for (y=0; y<BOARD_WIDTH; y++) {
			alive = adjacent_to(temp_board, x, y);

			// Check the Birth condition
			if ( temp_board[x][y] == '.' && alive == 3 ) board[x][y] = 'X';

			// Check the Loneliness & Overpopulation conditions
			else if ( temp_board[x][y] == 'X' &&  (alive < 2 || alive > 3)) board[x][y] = '.';

		}
	}
}


void print_board ( char board[][BOARD_WIDTH] ) 
{
	int x, y;	// To iterate through the board

	for (x=0; x<BOARD_HEIGHT; x++) {
		for (y=0; y<BOARD_WIDTH; y++) {
			fprintf(stdout, "%c", board[x][y]);
		}
		fprintf(stdout, "\n");
	}
}


int width_add ( int width_index, int width_offset )
{
	int y_index = width_index + width_offset;

	if ( y_index >= BOARD_WIDTH ) y_index-=BOARD_WIDTH;
	else if ( y_index < 0 ) y_index+=BOARD_WIDTH;

	return y_index;
}


int height_add ( int height_index, int x_offset )
{
	int x_index = height_index + x_offset;

	if ( x_index >= BOARD_HEIGHT ) x_index-=BOARD_HEIGHT;
	else if ( x_index < 0 ) x_index+=BOARD_HEIGHT;

	return x_index;
}


int adjacent_to ( char board[][BOARD_WIDTH], int x_index, int y_index )
{
	int alive = 0;		// To count the number of alive neighbors

	// Calling height_add & width_add to ensure the looping around like a cylinder

	if ( board[height_add(x_index, -1)][width_add(y_index, -1)] == 'X' ) alive++;		// 1
	if ( board[height_add(x_index, -1)][y_index] == 'X' ) alive++;						// 2
	if ( board[height_add(x_index, -1)][width_add(y_index, 1)] == 'X' ) alive++;		// 3
	if ( board[x_index][width_add(y_index, -1)] == 'X' ) alive++;						// 4
	if ( board[x_index][width_add(y_index, 1)] == 'X' ) alive++;						// 5
	if ( board[height_add(x_index, 1)][width_add(y_index, -1)] == 'X' ) alive++;		// 6
	if ( board[height_add(x_index, 1)][y_index] == 'X' ) alive++;						// 7
	if ( board[height_add(x_index, 1)][width_add(y_index, 1)] == 'X' ) alive++;			// 8

	return alive;
}

void print_to_file (char board[][BOARD_WIDTH], const char *name )
{
	FILE *fp = fopen(name, "w");

	int x,y;

	for (x=0; x<BOARD_HEIGHT; x++) {
		for (y=0; y<BOARD_WIDTH; y++) {
			fprintf(fp, "%c", board[x][y]);
		}
		fprintf(fp, "\n");
	}

	fclose(fp);
}
