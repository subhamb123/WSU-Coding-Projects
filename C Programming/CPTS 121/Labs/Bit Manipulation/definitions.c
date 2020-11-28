#include "parent.h"

void power2(int number, int pow) {
	number = number << pow;
	printf("\nProblem 2\nInteger: %d\n", number);
	printf("Bits: ");
	for (unsigned int i = 1 << 31, j = 1; i > 0; i = i / 2, j++) {
		(number & i) ? printf("1") : printf("0");
		if (j == 8) {
			putchar(' ');
			j = 0;
		}
	}

	putchar('\n');
}

void packCharacters(char c1, char c2, char c3, char c4) {
	for (unsigned int i = 1 << 7, j = 1; i > 0; i = i / 2, j++) {
		(c1 & i) ? printf("1") : printf("0");
		if (j == 8) {
			putchar(' ');
			j = 0;
		}
	}

	putchar('\n');

	for (unsigned int i = 1 << 7, j = 1; i > 0; i = i / 2, j++) {
		(c2 & i) ? printf("1") : printf("0");
		if (j == 8) {
			putchar(' ');
			j = 0;
		}
	}

	putchar('\n');

	for (unsigned int i = 1 << 7, j = 1; i > 0; i = i / 2, j++) {
		(c3 & i) ? printf("1") : printf("0");
		if (j == 8) {
			putchar(' ');
			j = 0;
		}
	}

	putchar('\n');

	for (unsigned int i = 1 << 7, j = 1; i > 0; i = i / 2, j++) {
		(c4 & i) ? printf("1") : printf("0");
		if (j == 8) {
			putchar(' ');
			j = 0;
		}
	}

	putchar('\n');

	unsigned int x = c1;
	x = x << 8;
	x = x | c2;

	x = x << 8;
	x = x | c3;

	x = x << 8;
	x = x | c4;

	for (unsigned int i = 1 << 31, j = 1; i > 0; i = i / 2, j++) {
		(x & i) ? printf("1") : printf("0");
		if (j == 8) {
			putchar(' ');
			j = 0;
		}
	}

	putchar('\n');
}