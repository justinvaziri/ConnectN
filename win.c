#include "board.h"
#include "input_validation.h"
#include "win.h"

bool check_win(Board board, int num_rows, int num_cols, int chosen_row, int chosen_col, int num_to_win, char curr_piece) {
    
    /**
        Checks to see if someone has won
        
        @param board: board being used to play connectn
        @param num_rows: number of rows of the board
        @param num_cols: number of columns of the board
        @param chosen_row: row that the piece was placed in
        @param chosen_col: column that the piece was placed in
        @param num_to_win: number of pieces in a row needed to win
        @param curr_piece: piece of the player who just dropped a piece
        @return: returns true if a player won and false if they didn't
    */
    
    // curr_piece is another name for turn
    return (check_diagonal(board, num_rows, num_cols, chosen_row, chosen_col, num_to_win, curr_piece) || 
            check_row(board, num_cols, chosen_row, num_to_win, curr_piece) || 
            check_column(board, num_rows, chosen_col, num_to_win, curr_piece));
}

bool check_row(Board board, int num_cols, int chosen_row, int num_to_win, char curr_piece) {
    
    /**
        Checks to see if there is a horrizonal win on the row which a piece was just placed on
        
        @param board: board being used to play connectn on
        @param num_cols: number of columns of board
        @param chosen_row: row of the piece just placed
        @param num_to_win: number of pieces in a row needed to win
        @param curr_piece: piece that was just dropped(either X or O)
        @return: true if someone won horrizontally, and false if not
    */
    int counter = 0;
    for(int cols = 0; cols < num_cols; ++cols){
        if(board[chosen_row][cols] == curr_piece){
            counter++;
        }
        else{
            counter = 0;
        }
        if(counter == num_to_win){
            return true;
        }
    }
    return false;
}

bool check_column(Board board, int num_rows, int chosen_col, int num_to_win, char curr_piece) {
    
    /**
        Checks to see if there is a vertical win on the column which a piece was just placed on
        
        @param board: board being used to play connectn on
        @param num_rows: number of rows of board
        @param chosen_col: collumn of the piece just placed
        @param num_to_win: number of pieces in a row needed to win
        @param curr_piece: piece that was just dropped(either X or O)
        @return: true if someone won vertically, and false if not
    */
    
    int counter = 0;
    for(int rows = 0; rows < num_rows; ++rows){
        if(board[rows][chosen_col] == curr_piece){
            counter++;
        }
        else{
            counter = 0;
        }
        if(counter == num_to_win){
            return true;
        }
    }
    return false;
}

bool check_diagonal(Board board, int num_rows, int num_cols, int chosen_row, int chosen_col, int num_to_win, char turn) {
    
    /**
        Checks to see if there is a diagonal win on the row which a piece was just placed on
        
        @param board: board being used to play connectn on
        @param num_cols: number of columns of board
        @param num_rows: number of rows of board
        @param chosen_row: row of the piece just placed
        @param chosen_col: column of the piece just placed
        @param num_to_win: number of pieces in a row needed to win
        @param turn: piece that was just dropped(either X or O)
        @return: true if someone won diagonally, and false if not
    */
    
    return(check_left_diagonal(board, num_rows, num_cols, chosen_row, chosen_col, num_to_win, turn) ||
           check_right_diagonal(board, num_rows, num_cols, chosen_row, chosen_col, num_to_win, turn));
}

bool check_left_diagonal(Board board, int num_rows, int num_cols, int chosen_row, int chosen_col, int num_to_win, char turn) {
    
    /**
        Checks the left diagonal that the placed piece is in; it checks up and to
        the left and down and to the right, counting the number of chosen pieces in a row

        @param board: a two dimensional character array that holds all the pieces
        @param num_rows: the number of rows on the board
        @param num_cols: the number of columns on the board
        @param chosen_row: the row that the dropped piece is in
        @param chosen_col: the column that the dropped piece is in
        @param num_to_win: the number of pieces needed to win
        @param turn: the character of the player's piece (can be 'X' or 'O')
        @return: true or false, whether or not there is a num_to_win amount of pieces in
                 row in the left diagonal of the placed piece
    */
    
    int ctr = 0;
    int r = chosen_row; int c = chosen_col;
    
    // Goes up and to the left
    while((inbetween(r, 0, num_rows - 1) && inbetween(c, 0, num_cols - 1)) && (board[r][c] == turn)) {
        
        ctr++;
        if(ctr == num_to_win) {
            return true;
        }
        r--; c--;
    }
    
    // Go back to starting position
    r = chosen_row; c = chosen_col;
    ctr--;
    
    // Goes down and to the right
    while((inbetween(r, 0, num_rows - 1) && inbetween(c, 0, num_cols - 1)) && (board[r][c] == turn)) {
        
        ctr++;
        if(ctr == num_to_win) {
            return true;
        }
        r++; c++;
    }
    
    return false;
}

bool check_right_diagonal(Board board, int num_rows, int num_cols, int chosen_row, int chosen_col, int num_to_win, char turn) {
    
    /**
        Checks the right diagonal that the placed piece is in; it checks up and to
        the right and down and to the left, counting the number of chosen pieces in a row

        @param board: a two dimensional character array that holds all the pieces
        @param num_rows: the number of rows on the board
        @param num_cols: the number of columns on the board
        @param chosen_row: the row that the dropped piece is in
        @param chosen_col: the column that the dropped piece is in
        @param num_to_win: the number of pieces needed to win
        @param turn: the character of the player's piece (can be 'X' or 'O')
        @return: true or false, whether or not there is a num_to_win amount of pieces in
                 row in the right diagonal of the placed piece
    */
    
    int counter = 0;
    int r = chosen_row; int c = chosen_col;
    while((inbetween(r, 0, num_rows - 1) && inbetween(c, 0, num_cols - 1)) && (board[r][c] == turn)){
        counter++;        
        if(counter == num_to_win){
            return true;
        }
        r--; c++;
        
    } 
    r = chosen_row; c = chosen_col;
    counter--;
    while((inbetween(r, 0, num_rows - 1) && inbetween(c, 0, num_cols - 1)) && (board[r][c] == turn)){
        counter++;
        if(counter == num_to_win){
            return true;
        }
        r++; c--;
        
    } 
    return false;

}