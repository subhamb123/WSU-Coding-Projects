#ifndef parent

#define _CRT_SECURE_NO_WARNINGS
#define t 10
#define MAZE_ROWS 8
#define MAZE_COLS 20
#define BORDER 219
#define WALL   219
#define TARGET_ROW 7
#define TARGET_COL 19
#define FALSE 0
#define TRUE  1

#include <stdio.h>
#include <Windows.h>
//#include <stdlib.h>
//#include <time.h>

//void pathFinder(char maze[8][8]);
int findPath(char maze[][MAZE_COLS], int row, int col);
void drawMaze(char maze[][MAZE_COLS]);
int sumDigits(int n);
void reverse(char* str, char* temp, int len);
//char* str_rev_rec(char* str, int n);
void toh(int n, int A, int B, int C);

#endif