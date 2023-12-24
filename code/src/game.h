/** 
 * @file game.c
 * file that contains every functions used to simulate the match,
 * from the sequencing of player and computer turn to detecting whevener a player wins and who it is.
*/

#include "init.h"
#include "display.h"


/**
 * function that simulates the human player's turn.
 * Prints the result of their last hit and the result of computer's last hit.
 * Asks the human player to enter coordinates of where they want to shoot, (while checking validity of these coordinates)
 * Changes the tile's state, at the chosen coordinates, to the outcome of the shoot
 * 
 * @param game game variable with all the informations about the boards.
 * @param int_lastPlay1 result of the human player's last play (0: missed ; 1: hit ; 2: hit and sunk)
 * @param int_lastPlay2 result of the computer player's last play (0: missed ; 1: hit ; 2: hit and sunk)
 * @return return the result of the human player's play (0: missed ; 1: hit ; 2: hit and sunk).
*/
int playerTurn (Game game, int int_lastPlay1,int int_lastPlay2);


/**
 * function that simulates the computer player's turn.
 * Gets random coordinates (relative to the size).
 * Changes the tile's state, at the chosen coordinates, to the outcome of the shoot (-1: tile already shot ; 0: missed ; 1: hit ; 2: hit and sunk)
 * 
 * @param game game variable with all the informations about the boards.
 * @return return the result of the computer player's play (-1: tile already shot ; 0: missed ; 1: hit ; 2: hit and sunk).
*/
int ComputerTurn (Game game);


/**
 * function that test the state, dead or alive, of a boat. 
 * By comparing its reference coordinates and following tiles depending of orientation with concerned board.
 * @param game game variable with all the informations about the boards.
 * @param boat boat to test state
 * @param player player (1: human ; 2: computer)
 * @return returns if alive or  ot (1: alive ; 0: dead)
*/
int boat_state(Game game, Boat boat, int player);


/**
 * procedure that simulates the match itself, sequencing the human's an computer's turns.
 * While testing if someone won.
 * function done when winner found (or maximum shot reached)
*/
void match();