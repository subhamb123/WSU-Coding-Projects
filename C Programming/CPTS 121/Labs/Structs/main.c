#include "parent.h"

int main() {
	srand((unsigned int)time(NULL));
	int random = 0;
	char article[][10] = { "the", "a", "one", "some", "any" }, noun[][10] = { "boy", "girl", "dog", "town", "car" }, verb[][10] = { "drove", "jumped", "ran", "walked", "skipped" }, preposition[][10] = { "to", "from", "over", "under", "on" }, sentence[100] = "", temp[2] = "";
	printf("Problem 1\n");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 100; j++)
			sentence[j] = '\0';
		random = rand() % 5;
		temp[1] = '\0';
		temp[0] = toupper(article[random][0]);
		strcat(sentence, temp);
		for (int j = 1; article[random][j] != '\0'; j++) {
			temp[0] = article[random][j];
			strcat(sentence, temp);
		}
		strcat(sentence, " ");
		random = rand() % 5;
		strcat(sentence, noun[random]);
		strcat(sentence, " ");
		random = rand() % 5;
		strcat(sentence, verb[random]);
		strcat(sentence, " ");
		random = rand() % 5;
		strcat(sentence, preposition[random]);
		strcat(sentence, " ");
		random = rand() % 5;
		strcat(sentence, article[random]);
		strcat(sentence, " ");
		random = rand() % 5;
		strcat(sentence, noun[random]);
		strcat(sentence, "!");
		printf("%s\n", sentence);
	}

	printf("\nProblem 2 (AKA The notorious mini programming assignment)\n\n");

	/*Cell** cell = (Cell**)malloc(size * sizeof(Cell*));
	for (int i = 0; i < size; i++)
		cell[i] = (Cell*)malloc(size * sizeof(Cell));*/

	Cell board[max_size + 1][max_size + 1];
	Game_info p1 = { 0, 0, 0 }, p2 = { 0, 0, 0 };
	char ans = '\0';

	int size = max_size + 1, row = 0, column = 0, playing = 1, same = 1, x = 1, first = 1;
	
	int n = rand() % 2;

	while (playing) {
		if (first) {
			while (size > max_size || size <= 0) {
				printf("How many rows/columns do you want for tic tac toe? (Must be less than %d)\n", max_size + 1);
				scanf("%d", &size);
			}
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					board[i][j].occupied = 0;
					board[i][j].symbol = '\0';
				}
			}
		}

		x = 1, first = 0;

		print_board(size, board);

		if (n) {
			while (board[row][column].occupied != 0 || n == 1) {
				printf("Player X, enter a row and column.\n");
				scanf("%d%d", &row, &column);
				n = 0;
			}
			
			board[row][column].occupied = 1;
			board[row][column].symbol = 'X';
		}

		else {
			while (board[row][column].occupied != 0 || n == 0) {
				printf("Player O, enter a row and column.\n");
				scanf("%d%d", &row, &column);
				n = 1;
			}

			board[row][column].occupied = 1;
			board[row][column].symbol = 'O';
		}

		for (int i = 0; i < size; i++) {
			same = 1;
			for (int j = 0; j < size - 1; j++) {
				if (board[i][j].symbol != board[i][j + 1].symbol) {
					same = 0;
					break;
				}
			}

			if (same && board[i][0].symbol == 'X') {
				p1.wins++;
				p1.total_games_played++;
				p2.losses++;
				p2.total_games_played++;
				x = 0;
				break;
			}
			else if (same && board[i][0].symbol == 'O') {
				p2.wins++;
				p2.total_games_played++;
				p1.losses++;
				p1.total_games_played++;
				x = 0;
				break;
			}
		}

		if (x) {
			for (int i = 0; i < size; i++) {
				same = 1;
				for (int j = 0; j < size - 1; j++) {
					if (board[j][i].symbol != board[j+1][i].symbol) {
						same = 0;
						break;
					}
				}

				if (same && board[0][i].symbol == 'X') {
					p1.wins++;
					p1.total_games_played++;
					p2.losses++;
					p2.total_games_played++;
					x = 0;
					break;
				}
				else if (same && board[0][i].symbol == 'O') {
					p2.wins++;
					p2.total_games_played++;
					p1.losses++;
					p1.total_games_played++;
					x = 0;
					break;
				}
			}
		}
		
		if (x) {
			for (int i = 0, j = 0; i < size - 1 && j < size - 1; i++, j++) {
				same = 1;
				if (board[i][j].symbol != board[i + 1][j + 1].symbol) {
					same = 0;
					break;
				}
			}
			if (same && board[0][0].symbol == 'X') {
				p1.wins++;
				p1.total_games_played++;
				p2.losses++;
				p2.total_games_played++;
				x = 0;
			}
			else if (same && board[0][0].symbol == 'O') {
				p2.wins++;
				p2.total_games_played++;
				p1.losses++;
				p1.total_games_played++;
				x = 0;
			}
		}

		if (x) {
			for (int i = size - 1, j = 0; i >= 0 && j < size - 1; i--, j++) {
				same = 1;
				if (board[i][j].symbol != board[i - 1][j + 1].symbol) {
					same = 0;
					break;
				}
			}
			if (same && board[size - 1][0].symbol == 'X') {
				p1.wins++;
				p1.total_games_played++;
				p2.losses++;
				p2.total_games_played++;
				x = 0;
			}
			else if (same && board[size - 1][0].symbol == 'O') {
				p2.wins++;
				p2.total_games_played++;
				p1.losses++;
				p1.total_games_played++;
				x = 0;
			}
		}

		if (x) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (board[i][j].symbol != '\0')
						x = 0;
					else {
						x = 1;
						break;
					}
				}
				if (x == 1)
					break;
			}
			if (x == 0) {
				printf("Draw!\n");
				p1.total_games_played++;
				p2.total_games_played++;
			}
		}

		if (x == 0) {
			print_board(size, board);
			printf("Player X Wins: %d\n", p1.wins);
			printf("Player X Losses: %d\n", p1.losses);
			printf("Player X Games: %d\n", p1.total_games_played);
			printf("Player O Wins: %d\n", p2.wins);
			printf("Player O Losses: %d\n", p2.losses);
			printf("Player O Games: %d\n", p2.total_games_played);

			scanf("%c", &ans);

			printf("Want to play again? (y/n)\n");
			scanf("%c", &ans);
			if (ans == 'n')
				playing = 0;
			else {
				first = 1;
				size = max_size + 1;
			}
		}
	}
	

	return 0;
}