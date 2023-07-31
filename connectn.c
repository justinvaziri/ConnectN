#include "connectn.h"
#include "input_validation.h"
#include "win.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>

void play_connectN(int arg_num, char** args) {
    
    /**
        Starts and finishes the ConnectN game, setting up, taking user input, 
        announcing the final results, and deleting the board.
        
        @param arg_num: the number of arguments executed in the terminal
        @param args: the arguments from the terminal stored in an array as strings
    */
    
    char turn = 'X'; 
    char winner;
    int num_rows; int num_cols; int num_to_win;
    
    Board board = setup_game(arg_num, args, &num_rows, &num_cols, &num_to_win);
    play_game(board, num_rows, num_cols, &winner, num_to_win, turn);
    announce_results(winner);
    delete_board(&board, num_rows);
}

Board setup_game(int arg_num, char** args, int *num_rows, int *num_cols, int *num_to_win) {
    
    /**
        Sets up the game, including making a board, checking if the arguements are valid, filling the board, and printing it.
        
        @param arg_num = number of arguements user input
        @param args: array of the arguements the user input
        @param num_rows: pointer that sets the variable it's pointing to to the number of rows the user wants
        @param num_cols: pointer that sets the variable it's pointing to to the number of columns the user wants
        @param num_to_win: pointer that sets the variable it's pointing to to the number of pieces in a row needed to win
        @return: the board with all the specified dimentions
    */
    
    Board board;
    
    check_args(arg_num, args);
    
    // Initialize each variable
    *num_rows = atoi(args[1]);
    *num_cols = atoi(args[2]);
    *num_to_win = atoi(args[3]);

    board = make_board(*num_rows, *num_cols);
    fill_board(board, *num_rows, *num_cols);
    print_board(board, *num_rows, *num_cols);

    return board;
}

void play_game(Board board, int num_rows, int num_cols, char *winner, int num_to_win, char turn) {
    
    /**
        After everything has been set up, this function starts the game: asks
        for input, drops the pieces, prints the board, and checks every turn
        if someone has won.

        @param board: a two dimensional character array that holds all the pieces
        @param num_rows: the number of rows on the board
        @param num_cols: the number of columns on the board
        @param winner: a pointer to the character of the player that wins
        @param num_to_win: the number of pieces needed to win
        @param turn: the character of the player's piece (can be 'X' or 'O')
    */
    
    int chosen_row;
    int chosen_col;
    
    do {
        player_turn(board, num_rows, num_cols, turn, &chosen_row, &chosen_col);
        print_board(board, num_rows, num_cols);
        if(check_win(board, num_rows, num_cols, chosen_row, chosen_col, num_to_win, turn)) {
            *winner = turn;
            return;
        }
        else {
            switch_turns(&turn);
        }
    } while(!is_full_board(board, num_cols));

    *winner = 't';
}

void player_turn(Board board, int num_rows, int num_cols, char turn, int *chosen_row, int *chosen_col) {
    
    /**
        Asks player to pick a column to drop a piece into, and keeps asking until a valid one is given, then drops the piece into
        the board
        
        @param board: board being used to play connectn
        @param num_rows: number of rows of board
        @param num_cols: number of columns of board
        @param turn: piece of the current player
        @param chosen_row: row that the piece would fall into
        @param chosen_col: columm that the player chooses to place the piece into
    */
    
    char prompt[100];

    sprintf(prompt, "Enter a column between 0 and %d to play in: ", num_cols - 1);
    do {
        // Checks if it is a valid int
        *chosen_col = getValidInt(prompt);
        
        // Checks if in bounds and if column is full
    } while(!inbetween(*chosen_col, 0, num_cols - 1) || (board[0][*chosen_col] != '*'));

    *chosen_row = drop_piece(board, num_rows, *chosen_col, turn);
}

void announce_results(char winner) {
    
    /**
        Announces who won the game once someone has won
        
        @param winner: the piece of the winner
    */
    
    if(winner == 'X') {
        printf("Player 1 Won!");
    }
    else if(winner == 'O') {
        printf("Player 2 Won!");
    }
    else {
        printf("Tie game!");
    }

}

void check_args(int arg_num, char** args) {
    
    /**
        Checks the arguements to see if they are valid
        
        @param arg_num: number of arguements passed
        @param args: list of the arguements passed
    */

    // there must be four arguments, including executable
    if(arg_num < 4) {
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }
    else if(arg_num > 4) {
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }

    for(int i = 1; i < 4; i++) {
        if(atoi(args[i]) <= 0) {
            printf("Invalid integers");
            printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
            exit(0);
        }
    }
}

void switch_turns(char *turn) {
    
    /**
        Switches the turn from the current player to the other player
        
        @param turn: the piece (X or O) of the player
    */
    
    if(*turn == 'X') {
        *turn = 'O';
    }
    else {
        *turn = 'X';
    }
}