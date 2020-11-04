#include "parent.h"

int main() {
	srand((unsigned int)time(NULL));
	int check = 0, size = 0;
	int arr1[100] = { 0 }, arr21[20] = { 0 }, arr22[101] = { 0 };
	FILE* infile = fopen("data.dat", "r");
	while (check != EOF) {
		check = fscanf(infile, "%d", &arr1[size]);
		if (check != EOF)
			size++;
	}

	printf("1.\nInitial: ");
	for (int j = 0; j < size; j++)
		printf("%d ", arr1[j]);

	printf("\nFinal: ");

	for (int j = 0; j < size / 2; j++) {
		int temp = arr1[j];
		arr1[j] = arr1[size - j - 1];
		arr1[size - j - 1] = temp;
	}

	for (int j = 0; j < size; j++)
		printf("%d ", arr1[j]);

	for (int j = 0; j < 20; j++) {
		arr21[j] = rand() % 100 + 1;
		arr22[arr21[j]]++;
	}

	printf("\n2.\n");

	for (int j = 1; j < 101; j++)
		printf("%d: %d ", j, arr22[j]);

	putchar('\n');

	char word[10] = { 'b', 'o', 'o', 'k', 'k', 'e', 'e', 'p', 'e', 'r' }, guess[10] = { '*', '*', '*', '*', '*', '*', '*', '*', '*', '*' }, c = '\0';
	int playing = 1, mistakes = 5, same = 1, gate = 1;
	size = 10;

	printf("\n3. Guess all the letters correctly before you make 5 mistakes!\n");
	while (playing) {
		same = 1, gate = 1;
		for (int j = 0; j < size; j++)
			printf("%c ", guess[j]);

		printf("\nMistakes remaining: %d\nEnter a letter\n", mistakes);
		scanf("%c", &c);
		for (int j = 0; j < size; j++) {
			if (word[j] == c) {
				guess[j] = c;
				gate = 0;
			}
		}
		if (gate)
			mistakes--;

		for (int j = 0; j < size; j++) {
			if (word[j] != guess[j]) {
				same = 0;
				break;
			}
		}
		if (mistakes == 0) {
			playing = 0;
			printf("The word was ");
			for (int j = 0; j < size; j++)
				printf("%c", word[j]);

			putchar('\n');
		}
		else if (same) {
			playing = 0;
			printf("You guessed the word ");
			for (int j = 0; j < size; j++)
				printf("%c", word[j]);

			printf("!\n");
		}
		scanf("%c", &c);
	}

	return 0;
}