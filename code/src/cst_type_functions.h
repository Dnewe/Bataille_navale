/**
* @file cst_type_functions.c
* file containing the inistialisation of constants, types and useful general functions.
*/



#ifndef _FUNCTIONS_
#define _FUNCTIONS_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/** constant representing the size of one side of the board*/
#define SIZE 10													

/** constant representing the max length of a boat. Wich is also the size of the boats composition lists*/
#define MAX_LENGTH 5	

/** constant representing the boat composition of the player (1). With P1_BOATS_COMPOSITION[i] : number of boats of i+1 size*/
#define P1_BOATS_COMPOSITION (int[MAX_LENGTH]){ 0, 1, 2, 2, 1}	

/** constant representing the boat composition of the computer (2). With P2_BOATS_COMPOSITION[i] : number of boats of i+1 size*/
#define P2_BOATS_COMPOSITION (int[MAX_LENGTH]){ 0, 1, 2, 2, 1}	



/**
 * enumeration of different tiles states
*/
typedef enum {
	WATER,
	WATER_SHOT,
	BOAT,
	WRECK,
} State_of_tile;



/** 
 * A structure to store one boat's information
 */
typedef struct {
	int length;			/**< boat's length*/
	int x;				/**< line coordinates of reference point*/
	int y;              /**< column coordinates of reference point*/
	int orientation;    /**< boat's orientation (0: horizontal; 1: vertical)*/
} Boat;

/** 
 * A structure to store one board's information
 */
typedef struct {
    int** int_board;		/**< 2D array that represents the board (int)*/
    int int_taille_board;	/**< array size (one side)*/

} Board;

/** 
 * A structure to have all Game variables in one place
 */
typedef struct {
    Board board_player1;	/**< human's board*/
    Board board_player2;	/**< computer's board*/
    Boat* boats_player1;	/**< human's list of boats*/
    Boat* boats_player2;	/**< computer's list of boats*/
} Game;


/**
 * fonction used to get the number of boats for a chosen player.
 * @param player player we want to know the number of boats (1: human ; 2: computer)
*/
int number_boats(int player);


/**
 * procedure to make sure the last scanf result has been emptied.
*/
void emptyBuffer(void);


/**
 * procedure used to free allocated memory. 
 * Used when the game is ended.
 * @param game variable that contains all the variables that need to be freed
*/
void free_game(Game game);

#endif