#include "board.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

Board make_board(int num_rows, int num_cols){
    
    /**
        Creates a board with num_rows rows and num_cols columns, and returns it
    
        @param num_rows: number of rows the board will be
        @param num_cols: number of cols the board will be
        @return: returns board of specified columns and rows
    */
    
    Board board = (Board)calloc(num_rows, sizeof(char*));
    for(int i = 0; i < num_rows; i++) {
        board[i] = (char*)calloc(num_cols, sizeof(char));
    }
    return board;
}

void fill_board(Board board, int num_rows, int num_cols) {
    
    /**
        fills the board with astericks
    
        @param board: the board we are using for the game
        @param num_rows: the number of rows of the board
        @param num_cols: the number of columns of the board
    */
    
    for(int r = 0; r < num_rows; r++) {
        for(int c = 0; c < num_cols; c++) {
            board[r][c] = '*';
        }
    }
}

int drop_piece(Board board, int num_rows, int column, char turn) {
    
    /**
        Function that drops the piece during a users turn. Based on the given column, it finds the first 
        instance of a piece in that column,then places the piece above it. If there is no piece currently 
        in that column, the piece is placed at the bottom.

        @param board: board being used to play connectn
        @param num_rows: number of rows of the board
        @param column: the column the user chose to place the piece in
        @param turn: the piece (X or O) of the current player
        @return: returns the row that the piece was placed into
    */
    
    for(int r = 0; r < num_rows; r++) {
        if(board[r][column] != '*') {
            board[r - 1][column] = turn;
            return r - 1;
        }
    }

    // No pieces in column so put piece at bottom
    board[num_rows - 1][column] = turn;
    return num_rows - 1;
}

void print_board(Board board, int num_rows, int num_cols) {
    
    /**
        Prints the board, with the columns and rowson the outside, and the actual board on the inside
    
        @param board: board being used to play connectn
        @param um_rows: the number of rows of the board
        @param num_cols: the number of columns of the board

        2 * * * *
        1 * * * *
        0 * * * *
          0 1 2 3
    */
    
    // Print row numbers and asterisks
    for(int r = 0; r < num_rows; r++){
        printf(" %d ", num_rows - 1 - r);
        for(int c = 0; c < num_cols; ++c){
            printf(" %c ", board[r][c]);
        }
        printf("\n");
    }
    
    // Print col numbers
    printf("   ");
    for(int i = 0; i < num_cols; i++) {
        printf(" %d ", i);
    }

    printf("\n");

}

bool is_full_board(Board board, int num_cols) {
    
    /**
        Checks to see if the board if full
        
        @param board: board being used to play connectn
        @param num_cols: number of columns of the board
        @return: returns true if the board if full and false if it is not
    */
    
    for(int c = 0; c < num_cols; c++) {
        if(board[0][c] == '*') {
            return false;
        }
    }
    
    return true;
}

void delete_board(Board *board, int num_rows) {
    
    /**
        Deletes the board after a winner is declared, or a tie occurs
        
        @param board: board being used to play connectn
        @param num_rows: number of rows of the board
    */

    for(int i = 0; i < num_rows; i++) {
        free((*board)[i]);
    }
    free(*board);
    *board = NULL;
}