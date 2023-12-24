/** 
 * @file init.c
 * file that contains every functions needed to initalize the game.
 * (may need general functions from cst_type_functions.c)
*/

#ifndef _INIT_
#define _INIT_

#include "cst_type_functions.h"


/**
 * function used to create a type boat from its parameters: length, reference position (x,y) (top left of the boat) and orientation
 * @param length length of the boat
 * @param x reference position of the first line where the tiles of the boat are located
 * @param y reference position of the first column where the tiles of the boat are located
 * @param orientation orientation of the boat (0: horizontal ; 1: vertical)
 * @return the variable of type boat created
*/
Boat create_boat(int length, int x, int y, int orientation);


/**
 * function used to find if there are any conflicts of position between one given boat and the rest of them
 * @param boat boat to compare with
 * @param tab_boats tab of boats to compare the given boat with
 * @param number_boats number of boats
 * @return returns 1 if there is/are conflict(s), returns 0 if not.
*/
int boat_conflict(Boat boat, Boat* tab_boats,int number_boats);


/**
 * function that creates the list of boats
 * @param player 1: human player ; 2: computer
 * @return the array containing all the boats of the player (human or computer)
*/
Boat* init_boats(int player);


/**
 * function used to initialize a board type variable by allocating the necessary memory.
 * The board is filled with WATER tiles.
 * Then the BOATS tiles of the board's owner are added to the concerned tiles (where board owner's boat are located).
 * @param tab_boats tab of board's owner boats to add them to the board
 * @param player 1: human player ; 2: computer
 * @return returns the Board type variable created
*/
Board init_board(Boat* tab_boats, int player);


/**
 * function used to initialize a game type variable, by creating 2 boards for each players, 2 boats lists for each players and fill them. 
 * And finally put them in the type Game variable.
 * @return returns the type Game generated
*/
Game init_game();

#endif