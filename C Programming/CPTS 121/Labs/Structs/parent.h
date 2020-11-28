#ifndef parent

#define _CRT_SECURE_NO_WARNINGS
#define max_size 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

typedef struct cell{
    int occupied; 
    char symbol;
} Cell;

typedef struct game_info{
    int wins;
    int losses;
    int total_games_played;
} Game_info;

void print_board(int size, Cell board[max_size + 1][max_size + 1]);
void init_board(int size, Cell board[max_size + 1][max_size + 1]);

#endif