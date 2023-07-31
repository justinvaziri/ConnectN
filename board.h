#ifndef BOARD_H
    #define BOARD_H
        #include <stdbool.h>
        typedef char** Board;
        Board make_board(int num_rows, int num_cols);
        void fill_board(Board board, int num_rows, int num_cols);
        int drop_piece(Board board, int num_rows, int column, char turn);
        void print_board(Board board, int num_rows, int num_cols);
        bool is_full_board(Board board, int num_cols);
        void delete_board(Board *board, int num_rows);
    
    #endif