#include "connectn.h"

/*
    Calls play_connectN which starts the game.

    This game is like Connect-4 except the size of the board and
    the number of pieces in a row needed to win are user parameters.
    Pieces land on top of pieces already played in that column and
    each player is trying to get n pieces in a row either vertically, 
    horizontally, or diagonally. The game ends if either player gets 
    n pieces in a row or the board becomes full
*/

int main(int argc, char* argv[]) {
    
    /**
        Calls connectN function.

        @param argc: number of arguments when executing program
        @param argv: each argument stored in array as strings
        @return 0: returns zero if the program finishes successfully
    */
    
    play_connectN(argc, argv);
    return 0;
}

// -fsanitize=address