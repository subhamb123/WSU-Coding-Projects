#include "parent.h"

void print_board(int size, Cell board[max_size + 1][max_size + 1]) {
	int x = 1;
	putchar(' ');
	for (int i = 0; i < size; i++) {
		if (size > 10) {
			if (i >= 10)
				printf("  %d", i);
			else
				printf("   %d", i);
		}
		else
			printf("  %d ", i);

	}
	putchar('\n');
	for (int i = 0; i < size; i++) {
		x = 1;
		putchar(' ');
		for (int j = 0; j < size; j++) {
			if (size > 10 && x) {
				printf(" ----");
				x = 0;
			}
			else
				printf("----");
		}
		putchar('-');
		putchar('\n');
		if(i < 10 && size > 10)
			printf(" %d", i);
		else
			printf("%d", i);
		for (int j = 0; j < size; j++)
			printf("| %c ", board[i][j].symbol);
		printf("|\n");
	}
	putchar(' ');
	x = 1;
	for (int i = 0; i < size; i++) {
		if (size > 10 && x) {
			printf(" ----");
			x = 0;
		}
		else
			printf("----");
	}
	putchar('-');
	putchar('\n');
}

//void init_board(int size, Cell **board) {
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			board[i][j].occupied = 0;
//			board[i][j].symbol = '\0';
//		}
//	}
//}