#ifndef CONNECTN_H
    #define CONNECTN_H
    #include "board.h"
    void play_connectN(int arg_num, char** args);
    Board setup_game(int arg_num, char** args, int *num_rows, int *num_cols, int *num_to_win);
    void play_game(Board board, int num_rows, int num_cols, char *winner, int num_to_win, char turn);
    void announce_results(char winner);
    void check_args(int arg_num, char** args);
    void player_turn(Board board, int num_rows, int num_cols, char turn, int *chosen_row, int *chosen_col);
    void switch_turns(char *turn);

#endif