/** 
 * @file main.c
 * main function executed on start.
*/

#include <time.h>
#include <stdlib.h>

#include "src/game.h"


int main(int argc, char** argv) {
    srand(time(NULL));      /**< to make sure the random seed is not the same on each call*/

    match();

    return 0;
}