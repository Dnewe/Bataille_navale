#include "game.h"




int playerTurn (Game game, int int_lastPlay1,int int_lastPlay2) {
    int int_x;
    int int_y;
    int int_retour;
    int tile_state;
    
    printf("\n");
    switch (int_lastPlay1) {
        case 2:
            printf(" -> you HIT and SUNK an enemy boat!");
            break;
        case 1:
            printf(" -> you HIT an enemy boat!\n");
            break;
        case 0:
            printf(" -> you missed.\n");
            break;
        default:
            printf("\n");
            break;
    }

    printf("\n");
    switch (int_lastPlay2) {
        case 2:
            printf(" -> opponent HIT and SUNK one of your boats!\n");
            break;
        case 1:
            printf(" -> opponent HIT one of your boats!\n");
            break;
        case 0:
            printf(" -> opponent missed.\n");
            break;
        default:
            printf("\n");
            break;
    }


    printf("\nYour turn, SHOOT AT \n");
    do {
        printf(" X= ");
        int_retour = 0;
        int_retour = scanf("%d", &int_x);
        emptyBuffer();
    } while (int_retour !=1 || int_x <1 || int_x >SIZE);

    
    do {
        printf(" Y= ");
        int_retour = 0;
        int_retour = scanf("%d", &int_y);
        emptyBuffer();
    } while (int_retour !=1 || int_y <1 || int_y >SIZE);

    tile_state = game.board_player2.int_board[int_x-1][int_y-1];
    switch (tile_state) {
        case WATER:
            game.board_player2.int_board[int_x-1][int_y-1] = WATER_SHOT;
            return 0;
            break;
        case WATER_SHOT:
            return 0;
            break;
        case BOAT:
            game.board_player2.int_board[int_x-1][int_y-1] = WRECK;
            return 1;
            break;
        case WRECK:
            return 0;
            break;
        default:
            break;
    }
    

    return 1;
}




int ComputerTurn (Game game) {
    int int_x;
    int int_y;
    int tile_state;

    

    int_x = rand()%SIZE;
    int_y = rand()%SIZE;

    tile_state = game.board_player1.int_board[int_x][int_y];
    switch (tile_state) {
        case WATER:
            game.board_player1.int_board[int_x][int_y] = WATER_SHOT;
            return 0;
            break;
        case WATER_SHOT:
            return -1;
            break;
        case BOAT:
            game.board_player1.int_board[int_x][int_y] = WRECK;
            return 1;
            break;
        case WRECK:
            return -1;
            break;
        default:
            break;
    }

    return 1;
}




int boat_state(Game game, Boat boat, int player) {
    int int_deadTiles = 0;
    if (boat.orientation == 0) {
        if (player ==1) {
            for (int i=0; i< boat.length; i++) {
                if (game.board_player1.int_board[boat.x][boat.y+i] == WRECK) {
                    int_deadTiles ++;
                }
            }
        } else {
            for (int i=0; i< boat.length; i++) {
                if (game.board_player2.int_board[boat.x][boat.y+i] == WRECK) {
                    int_deadTiles ++;
                }
            }
        }
    } else {
        if (player ==1) {
            for (int i=0; i< boat.length; i++) {
                if (game.board_player1.int_board[boat.x+i][boat.y] == WRECK) {
                    int_deadTiles ++;
                }
            }
        } else {
            for (int i=0; i< boat.length; i++) {
                if (game.board_player2.int_board[boat.x+i][boat.y] == WRECK) {
                    int_deadTiles ++;
                }
            }
        }   
    }

    if (int_deadTiles == boat.length) {
        return 0;
    }

    return 1;
} 




void match() {

    Game game = init_game();

    // Player turn
    int int_lastPlay1 =-1;              //  si touché ou non avant + si tué
    int int_lastPlay2 =-1;              //  si touché ou non avant + si tué

    int number_boats1 = number_boats(1);
    int number_boats2 = number_boats(2);

    int int_remaining_boats1 = number_boats1;
    int int_remaining_boats2 = number_boats2;

    int int_temp;

    int int_winner = 0;


    for (int k=0; k<SIZE*SIZE; k++) {
        printf("\n\n\n\n\n\n");
        printf("turn : %d\n",k+1);
        display(game);
        int_lastPlay1= playerTurn(game, int_lastPlay1, int_lastPlay2);
        
        if (int_lastPlay1 == 1) {
            int_temp = int_remaining_boats2;
            int_remaining_boats2 = number_boats2;
            for (int i =0; i<number_boats2; i++) {
                int_remaining_boats2 -= (1-boat_state(game, game.boats_player2[i], 2));
            }

            if (int_remaining_boats2 ==0) {
                int_winner = 1;
                break;
            }

            if (int_temp != int_remaining_boats2) {
                int_lastPlay1 = 2;
            }
        }


        sleep(1);

        printf("\n\n\n\n\n\n");
        printf("turn : %d\n",k+1);
        display(game);
        do {
            int_lastPlay2 = ComputerTurn(game);
        } while (int_lastPlay2 == -1);

        // display result of shot

        printf("\n");
        switch (int_lastPlay1) {
            case 2:
                printf(" -> you HIT and SUNK an enemy boat!");
                break;
            case 1:
                printf(" -> you HIT an enemy boat!\n");
                break;
            case 0:
                printf(" -> you missed.\n");
                break;
            default:
                printf("\n");
                break;
        }

        printf("\n\n\n\n");


        if (int_lastPlay2 == 1) {
            int_temp = int_remaining_boats1;
            int_remaining_boats1 = number_boats1;
            for (int i =0; i<number_boats1; i++) {
                int_remaining_boats1 -= (1-boat_state(game, game.boats_player1[i], 1));
            }

            if (int_remaining_boats1 ==0) {
                int_winner = 2;
                break;
            }

            if (int_temp != int_remaining_boats1) {
                int_lastPlay2 = 2;
            }
        }
        
        sleep(1);
    }
    display(game);
    if (int_winner == 1) {
        printf("\n -> you HIT and SUNK last enemy's boat!\n\n\n");
        printf("\n    [YOU WON]\n");
    } else {
        printf("\n");
        switch (int_lastPlay1) {
            case 2:
                printf(" -> you HIT and SUNK an enemy boat!");
                break;
            case 1:
                printf(" -> you HIT an enemy boat!\n");
                break;
            case 0:
                printf(" -> you missed.\n");
                break;
            default:
                printf("\n");
                break;
    }
        printf("\n -> opponent HIT and SUNK your last boat!\n");
        printf("\n    [OPPONENT WON]\n");
    }
    printf("\n\n\n");
    sleep(2);


    printf("game ended\n");
    free_game(game);
}