#ifndef WIN_H
    #define WIN_H
    #include "board.h"
    bool check_win(Board board, int num_rows, int num_cols, int chosen_row, int chosen_col, int num_to_win, char curr_piece);
    bool check_row(Board board, int num_cols, int chosen_row, int num_to_win, char curr_piece);
    bool check_column(Board board, int num_rows, int chosen_col, int num_to_win, char curr_piece);
    bool check_diagonal(Board board, int num_rows, int num_cols, int chosen_row, int chosen_col, int num_to_win, char turn);
    bool check_left_diagonal(Board board, int num_rows, int num_cols, int chosen_row, int chosen_col, int num_to_win, char turn);
    bool check_right_diagonal(Board board, int num_rows, int num_cols, int chosen_row, int chosen_col, int num_to_win, char turn);

#endif