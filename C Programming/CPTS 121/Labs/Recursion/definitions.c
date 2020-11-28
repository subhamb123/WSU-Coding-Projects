#include "parent.h"

/*void pathFinder(char maze[8][8]) {
	if (maze[7][7] == 'X')
		printf("No path can be found.\n");

	else {

	}
}*/

int findPath(char maze[][MAZE_COLS], int row, int col) {
	if (row < 0 || row >= MAZE_ROWS || col < 0 || col >= MAZE_COLS)
		return FALSE;
	if (maze[row][col] == (char)WALL)
		return FALSE;
	if (maze[row][col] == '*')
		return FALSE;
	if (row == TARGET_ROW && col == TARGET_COL) {
		maze[row][col] = '*';
		system("cls");
		drawMaze(maze);
		return TRUE;
	}

	maze[row][col] = '*';

	system("cls");
	drawMaze(maze);
	Sleep(300);

	// NORTH
	if (findPath(maze, row - 1, col)) {
		printf("NORTH (%d, %d)\n", row - 1, col);
		return TRUE;
	}

	// WEST
	if (findPath(maze, row, col - 1)) {
		printf("WEST (%d, %d)\n", row, col - 1);
		return TRUE;
	}

	// EAST
	if (findPath(maze, row, col + 1)) {
		printf("EAST (%d, %d)\n", row, col + 1);
		return TRUE;
	}

	// SOUTH
	if (findPath(maze, row + 1, col)) {
		printf("SOUTH (%d, %d)\n", row + 1, col);
		return TRUE;
	}

	maze[row][col] = ' ';
	system("cls");
	drawMaze(maze);
	Sleep(300);

	return FALSE;
}


void drawMaze(char maze[][MAZE_COLS]) {
	int i = 0, j = 0;

	for (i = 0; i < MAZE_COLS + 2; i++) {
		printf("%c", BORDER);
	}

	printf("\n");

	for (i = 0; i < MAZE_ROWS; i++) {
		printf("%c", BORDER);
		for (j = 0; j < MAZE_COLS; j++)
			printf("%c", maze[i][j]);
		printf("%c\n", BORDER);
	}

	for (i = 0; i < MAZE_COLS + 2; i++) {
		printf("%c", BORDER);
	}
	printf("\n");
}

int sumDigits(int n) {
	if (n == 0)
		return 0;
	return (n % 10 + sumDigits(n / 10));
}

void reverse(char* str, char* temp, int len){
	if (*str && len >= t/2 + 1){
		reverse(str + 1, temp, len-1);
		char s = *str;
		*str = temp[len - 1];
		temp[len-1] = s;
	}
}

/*char* str_rev_rec(char* str, int n) {
	if (n > 1) {
		char temp = *str;
		*str = *(str + n - 1);
		*(str + n - 1) = temp;
		str_rev_rec(str + 1, n - 2);
	}

	return str;
}*/

void toh(int n, int A, int B, int C) {
	if (n > 0) {
		toh(n - 1, A, C, B);
		printf("Move topmost disk on tower %d to tower %d\n", A, C);
		toh(n - 1, B, A, C);
	}
}