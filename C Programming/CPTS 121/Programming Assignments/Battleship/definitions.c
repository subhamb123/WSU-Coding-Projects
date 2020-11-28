/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 121; Lab Section 21                                       *
* Programming Assignment: PA 6 - Basic Game of Battleship               *
* Date: 11/1/2020                                                       *
* Description: This program emulates the game of Battleship.            *
************************************************************************/

#include "parent.h"

/****************************************************************
	* Function: welcome_screen()                                *
	* Date Created: 11/4/2020                                   *
	* Date Last Modified: 11/4/2020                             *
	* Description: Welcomes the user to the game                *
	* Input parameters: None                                    *
	* Returns: User's option as an int                          *
	* Preconditions: None                                       *
	* Postconditions: User's option has been returned.          *
	*************************************************************/
int welcome_screen() {
	int option = 0;
	char c = '\0';
	printf("***** Welcome to Battleship! *****\nRules of the Game :\n1. This is a two player game.\n2. You play against the computer to see who sinks all the ships first.\n3. You can either manually or automatically place your five different sized ships.\n4. A player is randomly picked to start first and players take turns targetting.\n5. You enter coordinates of where you want to hit.\n6. The computer chooses random coordinates to hit.\n7. Once your ships or the computer's ships have all been destroyed, the game ends.\n8. Whoever sunk all the ships first wins.\n9. A log and statistics are displayed in battleship.log.\n10. And most importantly, HAVE FUN!!!\n\nHit enter to start the game!\n");
	scanf("%c", &c);
	system("cls");
	while (option != 1 && option != 2) {
		printf("Please select from the following menu:\n1. Enter positions of ships manually.\n2. Allow the program to randomly select positions of ships.\n\n");
		scanf("%d", &option);
	}
	return option;
}

/****************************************************************
	* Function: init_board()                                    *
	* Date Created: 11/4/2020                                   *
	* Date Last Modified: 11/4/2020                             *
	* Description: Initializes the provided board with '~'      *
	* Input parameters: board as a 2d char array                *
	* Returns: Nothing                                          *
	* Preconditions: board as a 2d char array                   *
	* Postconditions: the provided board has been initialized   *
	*************************************************************/
void init_board(char board[rows][columns]) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) 
			board[i][j] = '~';
	}
}

/****************************************************************
	* Function: print_board()                                   *
	* Date Created: 11/4/2020                                   *
	* Date Last Modified: 11/4/2020                             *
	* Description: prints the board depending on the user       *
	* Input parameters: board as a const 2d char array and int x*
	* Returns: Nothing                                          *
	* Preconditions: board as a const 2d char array and int x   *
	* Postconditions: The board has been printed                *
	*************************************************************/
void print_board(const char board[rows][columns], int x) {
	//Prints computer board
	if (x) {
		printf("    0   1   2   3   4   5   6   7   8   9\n");
		for (int i = 0; i < rows; i++) {
			printf("%d ", i);
			for (int j = 0; j < columns; j++) {
				//Prints actual value of array with this condition as this is for cells without a ship cell
				if(board[i][j] == '~' || board[i][j] == '*' || board[i][j] == 'm')
					printf("| %c ", board[i][j]);
				//Prints '~' so user can't see where the ships are
				else
					printf("| %c ", '~');
			}
			printf("|\n");
		}
	}
	//Prints player board
	else {
		printf("    0   1   2   3   4   5   6   7   8   9\n");
		for (int i = 0; i < rows; i++) {
			printf("%d ", i);
			for (int j = 0; j < columns; j++)
				printf("| %c ", board[i][j]);
			printf("|\n");
		}
	}
}

/****************************************************************
	* Function: manually_place_ships_on_board()                 *
	* Date Created: 11/4/2020                                   *
	* Date Last Modified: 11/4/2020                             *
	* Description: this allows the user to place the ships      *
	* Input parameters: pBoard as a 2d char array               *
	* Returns: Nothing                                          *
	* Preconditions: pBoard as a 2d char array                  *
	* Postconditions: the ships have been placed manually.      *
	*************************************************************/
void manually_place_ships_on_board(char pBoard[rows][columns]) {
	int coordinates[10] = { 0 }, temp1[5] = { 0 }, temp2[5] = { 0 }, next = 0;
	while (1) {
		next = 1;
		print_board(pBoard, 0);
		printf("Please enter the five cells to place the Carrier across in the form of (row column):\n");
		scanf("%d%d%d%d%d%d%d%d%d%d", &coordinates[0], &coordinates[1], &coordinates[2], &coordinates[3], &coordinates[4], &coordinates[5], &coordinates[6], &coordinates[7], &coordinates[8], &coordinates[9]);

		//Checks if coordinates are out-of-bounds
		if (coordinates[0] > 9 || coordinates[1] > 9 || coordinates[2] > 9 || coordinates[3] > 9 || coordinates[4] > 9 || coordinates[5] > 9 || coordinates[6] > 9 || coordinates[7] > 9 || coordinates[8] > 9 || coordinates[9] > 9 || coordinates[0] < 0 || coordinates[1] < 0 || coordinates[2] < 0 || coordinates[3] < 0 || coordinates[4] < 0 || coordinates[5] < 0 || coordinates[6] < 0 || coordinates[7] < 0 || coordinates[8] < 0 || coordinates[9] < 0)
			next = 0;

		//Checks if coordinates overlap for the same ship
		if (next) {
			for (int i = 0; i < 7; i++) {
				for (int j = i + 2; j < 9; j += 2) {
					if (coordinates[i] == coordinates[j] && coordinates[i + 1] == coordinates[j + 1]) {
						next = 0;
						break;
					}
				}
				if (next == 0)
					break;
			}
		}

		//Checks if coordinates are continuous for the same ship & if the ship is diagonal
		if (next) {
			for (int i = 0, j = 0; i < 10; i += 2, j++) {
				temp1[j] = coordinates[i];
				temp2[j] = coordinates[i + 1];
			}
			selection_sort(temp1, 5);
			selection_sort(temp2, 5);
			if (((temp1[0] + 4 != temp1[1] + 3 || temp1[1] + 3 != temp1[2] + 2 || temp1[2] + 2 != temp1[3] + 1 || temp1[3] + 1 != temp1[4]) && (temp2[0] + 4 != temp2[1] + 3 || temp2[1] + 3 != temp2[2] + 2 || temp2[2] + 2 != temp2[3] + 1 || temp2[3] + 1 != temp2[4])) || ((temp1[0] + 4 == temp1[1] + 3 || temp1[1] + 3 == temp1[2] + 2 || temp1[2] + 2 == temp1[3] + 1 || temp1[3] + 1 == temp1[4]) && (temp2[0] + 4 == temp2[1] + 3 || temp2[1] + 3 == temp2[2] + 2 || temp2[2] + 2 == temp2[3] + 1 || temp2[3] + 1 == temp2[4])))
				next = 0;
		}
		
		if (next)
			break;
	}

	pBoard[coordinates[0]][coordinates[1]] = 'c', pBoard[coordinates[2]][coordinates[3]] = 'c', pBoard[coordinates[4]][coordinates[5]] = 'c', pBoard[coordinates[6]][coordinates[7]] = 'c', pBoard[coordinates[8]][coordinates[9]] = 'c';

	while (1) {
		next = 1;
		print_board(pBoard, 0);
		printf("Please enter the four cells to place the Battleship across in the form of (row column):\n");
		scanf("%d%d%d%d%d%d%d%d", &coordinates[0], &coordinates[1], &coordinates[2], &coordinates[3], &coordinates[4], &coordinates[5], &coordinates[6], &coordinates[7]);
		if (coordinates[0] > 9 || coordinates[1] > 9 || coordinates[2] > 9 || coordinates[3] > 9 || coordinates[4] > 9 || coordinates[5] > 9 || coordinates[6] > 9 || coordinates[7] > 9 || coordinates[0] < 0 || coordinates[1] < 0 || coordinates[2] < 0 || coordinates[3] < 0 || coordinates[4] < 0 || coordinates[5] < 0 || coordinates[6] < 0 || coordinates[7] < 0)
			next = 0;

		if (next) {
			for (int i = 0; i < 5; i++) {
				for (int j = i + 2; j < 7; j += 2) {
					if (coordinates[i] == coordinates[j] && coordinates[i + 1] == coordinates[j + 1]) {
						next = 0;
						break;
					}
				}
				if (next == 0)
					break;
			}
		}

		if (next) {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					//Checks if cell is already occupied
					if (pBoard[i][j] != '~' && ((i == coordinates[0] && j == coordinates[1]) || (i == coordinates[2] && j == coordinates[3]) || (i == coordinates[4] && j == coordinates[5]) || (i == coordinates[6] && j == coordinates[7]))) {
						next = 0;
						break;
					}
				}
				if (next == 0)
					break;
			}
		}

		if (next) {
			for (int i = 0, j = 0; i < 8; i += 2, j++) {
				temp1[j] = coordinates[i];
				temp2[j] = coordinates[i + 1];
			}
			selection_sort(temp1, 4);
			selection_sort(temp2, 4);
			if ((temp1[0] + 3 != temp1[1] + 2 || temp1[1] + 2 != temp1[2] + 1 || temp1[2] + 1 != temp1[3]) && (temp2[0] + 3 != temp2[1] + 2 || temp2[1] + 2 != temp2[2] + 1 || temp2[2] + 1 != temp2[3]) || (temp1[0] + 3 == temp1[1] + 2 || temp1[1] + 2 == temp1[2] + 1 || temp1[2] + 1 == temp1[3]) && (temp2[0] + 3 == temp2[1] + 2 || temp2[1] + 2 == temp2[2] + 1 || temp2[2] + 1 == temp2[3]))
				next = 0;
		}

		if (next)
			break;
	}

	pBoard[coordinates[0]][coordinates[1]] = 'b', pBoard[coordinates[2]][coordinates[3]] = 'b', pBoard[coordinates[4]][coordinates[5]] = 'b', pBoard[coordinates[6]][coordinates[7]] = 'b';

	while (1) {
		next = 1;
		print_board(pBoard, 0);
		printf("Please enter the three cells to place the Cruiser across in the form of (row column):\n");
		scanf("%d%d%d%d%d%d", &coordinates[0], &coordinates[1], &coordinates[2], &coordinates[3], &coordinates[4], &coordinates[5]);
		if (coordinates[0] > 9 || coordinates[1] > 9 || coordinates[2] > 9 || coordinates[3] > 9 || coordinates[4] > 9 || coordinates[5] > 9 || coordinates[0] < 0 || coordinates[1] < 0 || coordinates[2] < 0 || coordinates[3] < 0 || coordinates[4] < 0 || coordinates[5] < 0)
			next = 0;

		if (next) {
			for (int i = 0; i < 3; i++) {
				for (int j = i + 2; j < 5; j += 2) {
					if (coordinates[i] == coordinates[j] && coordinates[i + 1] == coordinates[j + 1]) {
						next = 0;
						break;
					}
				}
				if (next == 0)
					break;
			}
		}

		if (next) {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					if (pBoard[i][j] != '~' && ((i == coordinates[0] && j == coordinates[1]) || (i == coordinates[2] && j == coordinates[3]) || (i == coordinates[4] && j == coordinates[5]))) {
						next = 0;
						break;
					}
				}
				if (next == 0)
					break;
			}
		}

		if (next) {
			for (int i = 0, j = 0; i < 6; i += 2, j++) {
				temp1[j] = coordinates[i];
				temp2[j] = coordinates[i + 1];
			}
			selection_sort(temp1, 3);
			selection_sort(temp2, 3);
			if ((temp1[0] + 2 != temp1[1] + 1 || temp1[1] + 1 != temp1[2]) && (temp2[0] + 2 != temp2[1] + 1 || temp2[1] + 1 != temp2[2]) || (temp1[0] + 2 == temp1[1] + 1 || temp1[1] + 1 == temp1[2]) && (temp2[0] + 2 == temp2[1] + 1 || temp2[1] + 1 == temp2[2]))
				next = 0;
		}

		if (next)
			break;
	}

	pBoard[coordinates[0]][coordinates[1]] = 'r', pBoard[coordinates[2]][coordinates[3]] = 'r', pBoard[coordinates[4]][coordinates[5]] = 'r';

	while (1) {
		next = 1;
		print_board(pBoard, 0);
		printf("Please enter the three cells to place the Submarine across in the form of (row column):\n");
		scanf("%d%d%d%d%d%d", &coordinates[0], &coordinates[1], &coordinates[2], &coordinates[3], &coordinates[4], &coordinates[5]);
		if (coordinates[0] > 9 || coordinates[1] > 9 || coordinates[2] > 9 || coordinates[3] > 9 || coordinates[4] > 9 || coordinates[5] > 9 || coordinates[0] < 0 || coordinates[1] < 0 || coordinates[2] < 0 || coordinates[3] < 0 || coordinates[4] < 0 || coordinates[5] < 0)
			next = 0;

		if (next) {
			for (int i = 0; i < 3; i++) {
				for (int j = i + 2; j < 5; j += 2) {
					if (coordinates[i] == coordinates[j] && coordinates[i + 1] == coordinates[j + 1]) {
						next = 0;
						break;
					}
				}
				if (next == 0)
					break;
			}
		}

		if (next) {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					if (pBoard[i][j] != '~' && ((i == coordinates[0] && j == coordinates[1]) || (i == coordinates[2] && j == coordinates[3]) || (i == coordinates[4] && j == coordinates[5]))) {
						next = 0;
						break;
					}
				}
				if (next == 0)
					break;
			}
		}

		if (next) {
			for (int i = 0, j = 0; i < 6; i += 2, j++) {
				temp1[j] = coordinates[i];
				temp2[j] = coordinates[i + 1];
			}
			selection_sort(temp1, 3);
			selection_sort(temp2, 3);
			if ((temp1[0] + 2 != temp1[1] + 1 || temp1[1] + 1 != temp1[2]) && (temp2[0] + 2 != temp2[1] + 1 || temp2[1] + 1 != temp2[2]) || (temp1[0] + 2 == temp1[1] + 1 || temp1[1] + 1 == temp1[2]) && (temp2[0] + 2 == temp2[1] + 1 || temp2[1] + 1 == temp2[2]))
				next = 0;
		}

		if (next)
			break;
	}

	pBoard[coordinates[0]][coordinates[1]] = 's', pBoard[coordinates[2]][coordinates[3]] = 's', pBoard[coordinates[4]][coordinates[5]] = 's';

	while (1) {
		next = 1;
		print_board(pBoard, 0);
		printf("Please enter the two cells to place the Destroyer across in the form of (row column):\n");
		scanf("%d%d%d%d", &coordinates[0], &coordinates[1], &coordinates[2], &coordinates[3]);
		if (coordinates[0] > 9 || coordinates[1] > 9 || coordinates[2] > 9 || coordinates[3] > 9 || coordinates[0] < 0 || coordinates[1] < 0 || coordinates[2] < 0 || coordinates[3] < 0)
			next = 0;

		if (next) {
			for (int i = 0; i < 1; i++) {
				for (int j = i + 2; j < 3; j += 2) {
					if (coordinates[i] == coordinates[j] && coordinates[i + 1] == coordinates[j + 1]) {
						next = 0;
						break;
					}
				}
				if (next == 0)
					break;
			}
		}

		if (next) {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					if (pBoard[i][j] != '~' && ((i == coordinates[0] && j == coordinates[1]) || (i == coordinates[2] && j == coordinates[3]))) {
						next = 0;
						break;
					}
				}
				if (next == 0)
					break;
			}
		}

		if (next) {
			for (int i = 0, j = 0; i < 4; i += 2, j++) {
				temp1[j] = coordinates[i];
				temp2[j] = coordinates[i + 1];
			}
			selection_sort(temp1, 2);
			selection_sort(temp2, 2);
			if ((temp1[0] + 1 != temp1[1]) && (temp2[0] + 1 != temp2[1]) || (temp1[0] + 1 == temp1[1]) && (temp2[0] + 1 == temp2[1]))
				next = 0;
		}

		if (next)
			break;
	}

	pBoard[coordinates[0]][coordinates[1]] = 'd', pBoard[coordinates[2]][coordinates[3]] = 'd';
}

/****************************************************************
	* Function: randomly_place_ships_on_board()                 *
	* Date Created: 11/4/2020                                   *
	* Date Last Modified: 11/4/2020                             *
	* Description: this randomly places ships on the board      *
	* Input parameters: board as a 2d char array                *
	* Returns: Nothing                                          *
	* Preconditions: board as a 2d char array                   *
	* Postconditions: the ships have been placed randomly.      *
	*************************************************************/
void randomly_place_ships_on_board(char board[rows][columns]) {
	int n1 = rand() % 10, n2 = rand() % 10, direction = 0, next = 0;
	board[n1][n2] = 'c'; //This will be the starting cell
	while (1) {
		direction = rand() % 4; //Randomizes which direction the rest of the cells will be placed in a straight line from starting cell

		//Executes if right direction is picked and all four cells to right of starting cell is within bounds
		if (direction == 0 && n2 + 4 < columns) {
			board[n1][n2 + 1] = 'c', board[n1][n2 + 2] = 'c', board[n1][n2 + 3] = 'c', board[n1][n2 + 4] = 'c';
			break;
		}
		//Executes if left direction is picked and all four cells to left of starting cell is within bounds
		else if (direction == 1 && n2 - 4 >= 0) {
			board[n1][n2 - 1] = 'c', board[n1][n2 - 2] = 'c', board[n1][n2 - 3] = 'c', board[n1][n2 - 4] = 'c';
			break;
		}
		//Executes if up direction is picked and all four cells to up of starting cell is within bounds
		else if (direction == 2 && n1 + 4 < rows) {
			board[n1 + 1][n2] = 'c', board[n1 + 2][n2] = 'c', board[n1 + 3][n2] = 'c', board[n1 + 4][n2] = 'c';
			break;
		}
		//Executes if down direction is picked and all four cells to down of starting cell is within bounds
		else if (direction == 3 && n1 - 4 >= 0) {
			board[n1 - 1][n2] = 'c', board[n1 - 2][n2] = 'c', board[n1 - 3][n2] = 'c', board[n1 - 4][n2] = 'c';
			break;
		}
	}

	while (1) {
		n1 = rand() % 10, n2 = rand() % 10, next = 1;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				//Checks if cell is already occupied
				if (board[i][j] != '~' && (i == n1 && j == n2)) {
					next = 0;
					break;
				}
			}
			if (next == 0)
				break;
		}
		if (next)
			break;
	}

	board[n1][n2] = 'b';

	while (1) {
		direction = rand() % 4;

		//Executes if conditions are met as seen above and if each of the three cells aren't occupied.
		if (direction == 0 && n2 + 3 < columns && board[n1][n2 + 1] == '~' && board[n1][n2 + 2] == '~' && board[n1][n2 + 3] == '~') {
			board[n1][n2 + 1] = 'b', board[n1][n2 + 2] = 'b', board[n1][n2 + 3] = 'b';
			break;
		}
		else if (direction == 1 && n2 - 3 >= 0 && board[n1][n2 - 1] == '~' && board[n1][n2 - 2] == '~' && board[n1][n2 - 3] == '~') {
			board[n1][n2 - 1] = 'b', board[n1][n2 - 2] = 'b', board[n1][n2 - 3] = 'b';
			break;
		}
		else if (direction == 2 && n1 + 3 < rows && board[n1 + 1][n2] == '~' && board[n1 + 2][n2] == '~' && board[n1 + 3][n2] == '~') {
			board[n1 + 1][n2] = 'b', board[n1 + 2][n2] = 'b', board[n1 + 3][n2] = 'b';
			break;
		}
		else if (direction == 3 && n1 - 3 >= 0 && board[n1 - 1][n2] == '~' && board[n1 - 2][n2] == '~' && board[n1 - 3][n2] == '~') {
			board[n1 - 1][n2] = 'b', board[n1 - 2][n2] = 'b', board[n1 - 3][n2] = 'b';
			break;
		}
	}

	while (1) {
		n1 = rand() % 10, n2 = rand() % 10, next = 1;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (board[i][j] != '~' && (i == n1 && j == n2)) {
					next = 0;
					break;
				}
			}
			if (next == 0)
				break;
		}
		if (next)
			break;
	}

	board[n1][n2] = 'r';

	while (1) {
		direction = rand() % 4;
		if (direction == 0 && n2 + 2 < columns && board[n1][n2 + 1] == '~' && board[n1][n2 + 2] == '~') {
			board[n1][n2 + 1] = 'r', board[n1][n2 + 2] = 'r';
			break;
		}
		else if (direction == 1 && n2 - 2 >= 0 && board[n1][n2 - 1] == '~' && board[n1][n2 - 2] == '~') {
			board[n1][n2 - 1] = 'r', board[n1][n2 - 2] = 'r';
			break;
		}
		else if (direction == 2 && n1 + 2 < rows && board[n1 + 1][n2] == '~' && board[n1 + 2][n2] == '~') {
			board[n1 + 1][n2] = 'r', board[n1 + 2][n2] = 'r';
			break;
		}
		else if (direction == 3 && n1 - 2 >= 0 && board[n1 - 1][n2] == '~' && board[n1 - 2][n2] == '~') {
			board[n1 - 1][n2] = 'r', board[n1 - 2][n2] = 'r';
			break;
		}
	}

	while (1) {
		n1 = rand() % 10, n2 = rand() % 10, next = 1;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (board[i][j] != '~' && (i == n1 && j == n2)) {
					next = 0;
					break;
				}
			}
			if (next == 0)
				break;
		}
		if (next)
			break;
	}

	board[n1][n2] = 's';

	while (1) {
		direction = rand() % 4;
		if (direction == 0 && n2 + 2 < columns && board[n1][n2 + 1] == '~' && board[n1][n2 + 2] == '~') {
			board[n1][n2 + 1] = 's', board[n1][n2 + 2] = 's';
			break;
		}
		else if (direction == 1 && n2 - 2 >= 0 && board[n1][n2 - 1] == '~' && board[n1][n2 - 2] == '~') {
			board[n1][n2 - 1] = 's', board[n1][n2 - 2] = 's';
			break;
		}
		else if (direction == 2 && n1 + 2 < rows && board[n1 + 1][n2] == '~' && board[n1 + 2][n2] == '~') {
			board[n1 + 1][n2] = 's', board[n1 + 2][n2] = 's';
			break;
		}
		else if (direction == 3 && n1 - 2 >= 0 && board[n1 - 1][n2] == '~' && board[n1 - 2][n2] == '~') {
			board[n1 - 1][n2] = 's', board[n1 - 2][n2] = 's';
			break;
		}
	}

	while (1) {
		n1 = rand() % 10, n2 = rand() % 10, next = 1;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (board[i][j] != '~' && (i == n1 && j == n2)) {
					next = 0;
					break;
				}
			}
			if (next == 0)
				break;
		}
		if (next)
			break;
	}

	board[n1][n2] = 'd';

	while (1) {
		direction = rand() % 4;
		if (direction == 0 && n2 + 1 < columns && board[n1][n2 + 1] == '~') {
			board[n1][n2 + 1] = 'd';
			break;
		}
		else if (direction == 1 && n2 - 1 >= 0 && board[n1][n2 - 1] == '~') {
			board[n1][n2 - 1] = 'd';
			break;
		}
		else if (direction == 2 && n1 + 1 < rows && board[n1 + 1][n2] == '~') {
			board[n1 + 1][n2] = 'd';
			break;
		}
		else if (direction == 3 && n1 - 1 >= 0 && board[n1 - 1][n2] == '~') {
			board[n1 - 1][n2] = 'd';
			break;
		}
	}
}

/****************************************************************
	* Function: delay()                                         *
	* Date Created: 11/4/2020                                   *
	* Date Last Modified: 11/4/2020                             *
	* Description: pauses the program for some miliseconds.     *
	* Input parameters: miliseconds as int                      *
	* Returns: Nothing                                          *
	* Preconditions: miliseconds as int                         *
	* Postconditions: the program has been delayed for some time*
	*************************************************************/
void delay(int x) {
	clock_t time = clock();
	while (clock() < time + x)
		;
}

/****************************************************************
	* Function: selection_sort()                                *
	* Date Created: 10/25/2020                                  *
	* Date Last Modified: 10/25/2020                            *
	* Description: Sorts an array in ascending order.           *
	* Input parameters: int array and size of array             *
	* Returns: a sorted array of the passed array               *
	* Preconditions: int array and size of array                *
	* Postconditions: a sorted array has been returned.       *
	*************************************************************/
int* selection_sort(int list[], int size) {
	int passes = 0, max_index = 0, i = 0;
	for (; passes < size - 1; passes++) {
		for (i = 1, max_index = 0; i < size - passes; i++) {
			if (list[max_index] < list[i])
				max_index = i;
		}
		int temp = list[max_index];
		list[max_index] = list[size - passes - 1];
		list[size - passes - 1] = temp;
	}
	return list;
}