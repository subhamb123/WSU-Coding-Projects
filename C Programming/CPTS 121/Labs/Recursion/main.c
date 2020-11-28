#include "parent.h"

int main() {
	/*srand(time(NULL));
	char maze[8][8] = { {'\0'} };
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			int x = rand() % 2;
			if (i == 0 && j == 1)
				continue;
				
			if (x)
				maze[i][j] = 'X';
		}
	}
	printf("Problem 1\n  0 1 2 3 4 5 6 7\n");
	for (int i = 0; i < 8; i++) {
		printf("%d ", i);
		for (int j = 0; j < 8; j++) 
			printf("%c ", maze[i][j]);
		
		putchar('\n');
	}

	pathFinder(maze);*/

	printf("Problem 1\n");

	int i = 0, j = 0;
	char maze[MAZE_ROWS][MAZE_COLS];
	char* mazeMap[MAZE_ROWS] = {"  X   X            X",
								"X X X X XXXXXXXXXX X",
								"X XXX X XXX    X X X",
								"X XX        XX X   X",
								"     X XXXX XXXXXXXX",
								" XXX X  XXX        X",
								" X X XXXX X XXXXXX X",
								"   X      X     XX  " };

	for (i = 0; i < MAZE_ROWS; i++) {
		for (j = 0; j < MAZE_COLS; j++) {
			if (mazeMap[i][j] == 'X')
				maze[i][j] = WALL;
			else
				maze[i][j] = ' ';
		}
	}

	drawMaze(maze);
	getchar();
	printf("%s\n\n", findPath(maze, 0, 0) ? "Path exist!" : "Path does not exist");

	printf("Problem 2\n");
	int num = 91732;
	printf("Sum of digits of %d is %d.\n", num, sumDigits(num));
	putchar('\n');

	printf("Problem 3\n");
	char str[] = "CS is cool";
	reverse(str, str, t);
	printf("%s\n", str);
	putchar('\n');

	printf("Problem 4\n");
	toh(4, 1, 2, 3);
	return 0;
}