#include "display.h"




void display(Game game) {
    int tile_state;

    printf("\n\nOPPONENT'S BOARD: \n\n");

    // display opponent board for player
    printf("   Y");
    for(int i=1; i<= SIZE; i++) {
        printf(" %d  ", i);
    }
    printf("\n");
    printf(" X +");
    for(int i=1; i<= SIZE; i++) {
        printf("---+");
    }
    printf("\n");
    for (int i=0; i<SIZE; i++) {
        if (i+1 <10 ) {
            printf(" %d |",i+1);
        } else {
            printf(" %d|",i+1);
        }
        for (int j=0; j<SIZE; j++) {
            tile_state = game.board_player2.int_board[i][j];
            switch (tile_state) {
                case WATER:
                    printf("   |");
                    break;
                case WATER_SHOT:
                    printf(" x |");
                    break;
                case BOAT:
                    printf(" E |");
                    break;
                case WRECK:
                    printf(" W |");
                    break;
                default:
                    printf("   |");
                    break;
            }
        }
        printf("\n");
        printf("   +");
        for(int j=1; j<= SIZE; j++) {
            printf("---+");
        }
        switch (i) {
            case 0:
                printf("       x : WATER SHOT");
                break;
            case 1:
                printf("       W : WRECK");
                break;
            default:
                break;
        }

        printf("\n");
    }

    printf("\n\nYOUR BOARD: \n\n");

    // display player view
    printf("   Y");
    for(int i=1; i<= SIZE; i++) {
        printf(" %d  ", i);
    }
    printf("\n");
    printf(" X +");
    for(int i=1; i<= SIZE; i++) {
        printf("---+");
    }
    printf("\n");
    for (int i=0; i<SIZE; i++) {
        if (i+1 <10 ) {
            printf(" %d |",i+1);
        } else {
            printf(" %d|",i+1);
        }
        for (int j=0; j<SIZE; j++) {
            tile_state = game.board_player1.int_board[i][j];
            switch (tile_state) {
                case WATER:
                    printf("   |");
                    break;
                case WATER_SHOT:
                    printf(" x |");
                    break;
                case BOAT:
                    printf(" B |");
                    break;
                case WRECK:
                    printf(" W |");
                    break;
                default:
                    printf("   |");
                    break;
            }
        }
        printf("\n");
        printf("   +");
        for(int j=1; j<= SIZE; j++) {
            printf("---+");
        }

        // display tiles meaning at specific lines.
        switch (i) {
            case 0:
                printf("       x : WATER SHOT");
                break;
            case 1:
                printf("       B : BOAT");
                break;
            case 2:
                printf("       W : WRECK");
                break;
            default:
                break;
        }

        printf("\n");
    }
}