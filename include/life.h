#ifndef LIFE_H
#define LIFE_H

#define BOARD_WIDTH  70
#define BOARD_HEIGHT 30

int width_add (int width_index, int width_offset);	// Add to a width index, wrapping around like a cylinder
int height_add (int height_index, int x_offset);	// Add to a height index, wrapping around like a cylinder
int adjacent_to (char board[][BOARD_WIDTH], int x_index, int y_index);	// Returns the number of adjacent live characters
int get_num_plays ( const char *num_plays );	// Takes in argv[2] in main and returns the signed number of generations
void play_generation (char board[][BOARD_WIDTH]);	// Plays one generation
void print_board (char board[][BOARD_WIDTH]);	//	Prints the board
void read_file (char board[][BOARD_WIDTH], const char *name);	// Reads in from the file
void print_to_file (char board[][BOARD_WIDTH], const char *name );	// Prints the final board to the file

#endif
