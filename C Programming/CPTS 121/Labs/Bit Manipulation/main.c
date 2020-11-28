#include "parent.h"

int main() {
	printf("Problem 1\n");
	unsigned int n = 25;
	for (unsigned int i = 1 << 31, j = 1; i > 0; i = i / 2, j++) {
		(n & i) ? printf("1") : printf("0");
		if (j == 8) {
			putchar(' ');
			j = 0;
		}
	}

	putchar('\n');

	n = n >> 4;

	for (unsigned int i = 1 << 31, j = 1; i > 0; i = i / 2, j++) {
		(n & i) ? printf("1") : printf("0");
		if (j == 8) {
			putchar(' ');
			j = 0;
		}
	}

	putchar('\n');

	power2(5, 3);

	char c1 = '\0', c2 = '\0', c3 = '\0', c4 = '\0';
	printf("\nProblem 3\nEnter 4 characters\n");
	scanf("%c%c%c%c", &c1, &c2, &c3, &c4);
	packCharacters(c1, c2, c3, c4);
	return 0;
}