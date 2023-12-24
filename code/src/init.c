#include "init.h"




Boat create_boat(int length, int x, int y, int orientation) {
    Boat boat;
    boat.x = x;
    boat.y = y;
    boat.length = length;
    boat.orientation = orientation;
    return boat;
}




int boat_conflict(Boat boat, Boat* tab_boats,int number_boats) {
    int x1 = boat.x;
    int y1 = boat.y;
    int length1 = boat.length;
    int orientation1 = boat.orientation;

    int x2;
    int y2;
    int length2;
    int orientation2;

    for (int i=0; i< number_boats; i++) {
        x2 = tab_boats[i].x;
        y2 = tab_boats[i].y;
        length2 = tab_boats[i].length;
        orientation2 = tab_boats[i].orientation;

        if (orientation1==0) {
            for (int i=0; i<length1; i++) {
                if (orientation2==0) {
                    for (int j=0; j<length2; j++) {
                        if (x1 == x2 && y1+i == y2+j) {
                            return(1);
                        }
                    }
                } else {
                    for (int j=0; j<length2; j++) {
                        if (x1 == x2+j && y1+i == y2) {
                            return(1);
                        }
                    }  
                }
            }
        } else {
            for (int i=0; i<length1; i++) {
                if (orientation2==0) {
                    for (int j=0; j<length2; j++) {
                        if (x1+i == x2 && y1 == y2+j) {
                            return(1);
                        }
                    }
                } else {
                    for (int j=0; j<length2; j++) {
                        if (x1+i == x2+j && y1 == y2) {
                            return(1);
                        }
                    }  
                }
            }
        }
    }
    
    return 0;             
} 




Boat* init_boats(int player) {
    int n_boats = number_boats(player);
      

    Boat* tab_boats;
    tab_boats = malloc(sizeof(Boat)*n_boats);
    if (tab_boats == NULL) {
        printf("allocation failed");
        exit(-1);
    }

    int length;
    int orientation;
    int x;
    int y;

    int number_boats_in_tab = 0;        /**< current number of boats in tab_boats*/

    for (int i =0; i< MAX_LENGTH; i++) {
        if (player ==1) {
            for (int j=0; j< P1_BOATS_COMPOSITION[i]; j++) {
                Boat boat;
                length = i+1;
                do {
                    orientation = rand()%2;
                    if (orientation ==0) {
                        x = rand()%SIZE;
                        y = rand()%(SIZE-length+1);
                    } else {
                        x = rand()%(SIZE-length+1);
                        y = rand()%SIZE;
                    }
                    boat = create_boat(length, x, y, orientation);
                } while (boat_conflict(boat, tab_boats, number_boats_in_tab) != 0);
                tab_boats[number_boats_in_tab] = boat;      
                number_boats_in_tab++;
            }
        } else {
            for (int j=0; j< P2_BOATS_COMPOSITION[i]; j++) {
                Boat boat;
                length = i+1;
                do {
                    orientation = rand()%2;
                    if (orientation ==0) {
                        x = rand()%SIZE;
                        y = rand()%(SIZE-length+1);
                    } else {
                        x = rand()%(SIZE-length+1);
                        y = rand()%SIZE;
                    }
                    boat = create_boat(length, x, y, orientation);
                } while (boat_conflict(boat, tab_boats, number_boats_in_tab) != 0);
                tab_boats[number_boats_in_tab] = boat;        
                number_boats_in_tab++;
            }
        }
    }
    

    return(tab_boats);
}




Board init_board(Boat* tab_boats, int player) {
    Board board;

    board.int_taille_board = SIZE;

    //** Allocation of memory.*/

    int** array;
    array = malloc(sizeof(int*)*SIZE);
    if (array==NULL) {
        printf("allocation failed");
        exit(-1);
    }
    for (int i=0; i<SIZE; i++) {
        array[i] = malloc(sizeof(int)*SIZE);
        if (array[i]==NULL) {
            for (int j=0; j<i; j++) {
                free(array[j]);
            }
            free(array);
            printf("allocation failed");
            exit(-1);
        }
        for (int j=0; j<SIZE; j++) {
            array[i][j] = WATER;            /**< filling board with WATER tiles*/
        }
    }
    
    /** Adding BOAT tiles to the board by searching where board's owner boats are.*/
    
    int int_number_boats = number_boats(player);

    for (int k=0; k<int_number_boats; k++) {
        if (tab_boats[k].orientation == 0) {
            for (int j=0; j< tab_boats[k].length; j++) {
                array[tab_boats[k].x][tab_boats[k].y+j] = BOAT;
            }
        } else {
            for (int i=0; i< tab_boats[k].length; i++) {
                array[tab_boats[k].x+i][tab_boats[k].y] = BOAT;
            }
        }
    }
    



    board.int_board = array;  

    return(board);
}




Game init_game() {
    Game game;
    Board board1;
    Board board2;
    Boat* boats1;
    Boat* boats2;

    boats1 = init_boats(1);
    boats2 = init_boats(2);

    board1 = init_board(boats1,1);
    board2 = init_board(boats2,2);


    game.boats_player1 = boats1;
    game.boats_player2 = boats2;

    game.board_player1 = board1;
    game.board_player2 = board2;

    //free(boats1);
    //free(boats2);
    return game;
}