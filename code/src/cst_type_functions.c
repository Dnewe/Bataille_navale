#include "cst_type_functions.h"




int number_boats(int player) {
    int number_boats = 0;
    for (int i =0; i< MAX_LENGTH; i++) {
        if (player ==1) {
            number_boats += P1_BOATS_COMPOSITION[i];
        } else {
            number_boats += P2_BOATS_COMPOSITION[i];
        }
    }
    return number_boats;
}




void emptyBuffer(void)
{
  int c;
  while((c=getchar()) != EOF && c != '\n');
 
}




void free_game(Game game) {
    for (int i=0; i<SIZE; i++) {
        free(game.board_player1.int_board[i]);
        free(game.board_player2.int_board[i]);
    }
    free(game.board_player1.int_board);
    free(game.board_player2.int_board);
    free(game.boats_player1);
    free(game.boats_player2);

    printf("memory cleared\n");
}

