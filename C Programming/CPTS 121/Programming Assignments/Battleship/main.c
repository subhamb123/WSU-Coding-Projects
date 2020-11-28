/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 121; Lab Section 21                                       *
* Programming Assignment: PA 6 - Basic Game of Battleship               *
* Date: 11/1/2020                                                       *
* Description: This program emulates the game of Battleship.            *
************************************************************************/

#include "parent.h"

int main() {
	srand((unsigned int)time(NULL)); //Initializes random
	FILE* outfile = fopen("battleship.log", "w"); //Allows to write data into battleship.log
	Stats player = { 0, 0, 0, 0, 0 }, computer = { 0, 0, 0, 0, 0 }; //Initializes the structs
	int option = 0, playing = 1, n1 = 0, n2 = 0, ccount1 = 5, bcount1 = 4, rcount1 = 3, scount1 = 3, dcount1 = 2, ccount2 = 5, bcount2 = 4, rcount2 = 3, scount2 = 3, dcount2 = 2, temp[10] = { 0 }, hash1[rows][columns] = { {0} }, hash2[rows][columns] = { {0} };
	char pBoard[rows][columns] = { {'\0'} }, cBoard[rows][columns] = { {'\0'} }, c = '\0', garbage = '\0';

	//These initializes the boards
	init_board(pBoard);
	init_board(cBoard);

	option = welcome_screen(); //Gets user option at the end of the welcome message

	//Executes if user wants to manually place ships
	if (option == 1) 
		manually_place_ships_on_board(pBoard);

	//Executes if user wants to randomly place ships
	if (option == 2) 
		randomly_place_ships_on_board(pBoard);
	
	randomly_place_ships_on_board(cBoard); //Randomly places ships on computer's board
	option = rand() % 2; //Randomizes who starts first

	scanf("%c", &garbage); //Collects garbage newline
	system("cls"); //Clears the screen

	//Keeps running until there is a winner
	while (playing) {
		//User's turn
		if (option) {
			printf("Player's move\n\n");
			printf("Player's Board:\n");
			print_board(pBoard, 0); 
			printf("\nComputer's Board:\n");
			print_board(cBoard, 1); //Second argument of 1 tells program to hide computer's ship positions

			//This block runs until valid input is entered or if it is the first time user is prompted to enter a target.
			do {
				printf("\nEnter a target (row col)\n");
				scanf("%d%d", &n1, &n2);
				scanf("%c", &garbage);
			}
			while (n1 >= rows || n1 < 0 || n2 >= columns || n2 < 0 || hash1[n1][n2] == 1);
			printf("\nHit enter to continue!");
			scanf("%c", &c);
			system("cls");
			printf("Target %d, %d\n", n1, n2);

			//If user hits a target
			if (cBoard[n1][n2] != '~') {
				//Ship specific conditionals to decrement number of that type of ship cells left
				if (cBoard[n1][n2] == 'c')
					ccount2--;
				if (cBoard[n1][n2] == 'b')
					bcount2--;
				if (cBoard[n1][n2] == 'r')
					rcount2--;
				if (cBoard[n1][n2] == 's')
					scount2--;
				if (cBoard[n1][n2] == 'd')
					dcount2--;
				cBoard[n1][n2] = '*'; //Updates computer's board with '*' to indicate hit
				player.hits++; //Increments number of hits
				printf("%d, %d is a hit!\n\n", n1, n2);
				fprintf(outfile, "Target %d, %d by player: Hit\n", n1, n2); //Logs to battleship.log
			}
			//If user misses a target
			else {
				cBoard[n1][n2] = 'm'; //Updates computer's board with 'm' to indicate miss
				player.misses++; //Increments number of misses
				printf("%d, %d is a miss!\n\n", n1, n2);
				fprintf(outfile, "Target %d, %d by player: Miss\n", n1, n2);
			}

			hash1[n1][n2]++; //This makes sure this same coordinate isn't picked again.
			player.shots++;
			option = 0; //Indicates computer's turn
			delay(1000); //Delays for 1 second for readability
		}
		//Computer's turn
		else {
			printf("Computer's move\n\n");
			printf("Player's Board:\n");
			print_board(pBoard, 0);
			printf("\nComputer's Board:\n");
			print_board(cBoard, 1);
			//This block runs until valid coordinates are obtained or if it is the first time computer is given coordinates.
			do
				n1 = rand() % 10, n2 = rand() % 10;
			while (hash2[n1][n2] == 1);
			printf("\nHit enter to continue!");
			scanf("%c", &c);
			system("cls");
			printf("Target %d, %d\n", n1, n2);
			if (pBoard[n1][n2] != '~') {
				if (pBoard[n1][n2] == 'c')
					ccount1--;
				if (pBoard[n1][n2] == 'b')
					bcount1--;
				if (pBoard[n1][n2] == 'r')
					rcount1--;
				if (pBoard[n1][n2] == 's')
					scount1--;
				if (pBoard[n1][n2] == 'd')
					dcount1--;
				pBoard[n1][n2] = '*';
				computer.hits++;
				printf("%d, %d is a hit!\n\n", n1, n2);
				fprintf(outfile, "Target %d, %d by computer: Hit\n", n1, n2);
			}
			else {
				pBoard[n1][n2] = 'm';
				computer.misses++;
				printf("%d, %d is a miss!\n\n", n1, n2);
				fprintf(outfile, "Target %d, %d by computer: Miss\n", n1, n2);
			}

			hash2[n1][n2]++;
			computer.shots++;
			option = 1;
			delay(1000);
		}

		//Checks if a particular ship has sunk
		if (ccount1 == 0 && temp[0] == 0) {
			printf("Player's carrier sunk!\n");
			fprintf(outfile, "Player's carrier sunk!\n");
			temp[0]++; //Makes sure it doesn't repeat this message again
		}
		if (bcount1 == 0 && temp[1] == 0) {
			printf("Player's battleship sunk!\n");
			fprintf(outfile, "Player's battleship sunk!\n");
			temp[1]++;
		}
		if (rcount1 == 0 && temp[2] == 0) {
			printf("Player's cruiser sunk!\n");
			fprintf(outfile, "Player's cruiser sunk!\n");
			temp[2]++;
		}
		if (scount1 == 0 && temp[3] == 0) {
			printf("Player's submarine sunk!\n");
			fprintf(outfile, "Player's submarine sunk!\n");
			temp[3]++;
		}
		if (dcount1 == 0 && temp[4] == 0) {
			printf("Player's destroyer sunk!\n");
			fprintf(outfile, "Player's destroyer sunk!\n");
			temp[4]++;
		}
		if (ccount2 == 0 && temp[5] == 0) {
			printf("Computer's carrier sunk!\n");
			fprintf(outfile, "Computer's carrier sunk!\n");
			temp[5]++;
		}
		if (bcount2 == 0 && temp[6] == 0) {
			printf("Computer's battleship sunk!\n");
			fprintf(outfile, "Computer's battleship sunk!\n");
			temp[6]++;
		}
		if (rcount2 == 0 && temp[7] == 0) {
			printf("Computer's cruiser sunk!\n");
			fprintf(outfile, "Computer's cruiser sunk!\n");
			temp[7]++;
		}
		if (scount2 == 0 && temp[8] == 0) {
			printf("Computer's submarine sunk!\n");
			fprintf(outfile, "Computer's submarine sunk!\n");
			temp[8]++;
		}
		if (dcount2 == 0 && temp[9] == 0) {
			printf("Computer's destroyer sunk!\n");
			fprintf(outfile, "Computer's destroyer sunk!\n");
			temp[9]++;
		}
		
		//Computer wins
		if (ccount1 == 0 && bcount1 == 0 && rcount1 == 0 && scount1 == 0 && dcount1 == 0) {
			computer.win = 1;
			playing = 0; //To exit loop as winner has been determined
			printf("The computer wins!\n");
		}
		//Player wins
		if (ccount2 == 0 && bcount2 == 0 && rcount2 == 0 && scount2 == 0 && dcount2 == 0) {
			player.win = 1;
			playing = 0;
			printf("The player wins!\n");
		}
	}

	//Calculates hit/miss ratio
	player.ratio = (double) player.hits / (double) player.misses;
	computer.ratio = (double) computer.hits / (double) computer.misses;
	
	//Logs end-of-game statistics to battleship.log
	fprintf(outfile, "\n----------STATISTICS----------\n");
	fprintf(outfile, "Player Stats:\n");
	fprintf(outfile, "Hits: %d\n", player.hits);
	fprintf(outfile, "Misses: %d\n", player.misses);
	fprintf(outfile, "Shots: %d\n", player.shots);
	fprintf(outfile, "Hits to Miss Ratio: %.2f%%\n", player.ratio * 100);
	fprintf(outfile, "%s\n", player.win ? "Player won.\n" : "Player lost.\n");

	fprintf(outfile, "\nComputer Stats:\n");
	fprintf(outfile, "Hits: %d\n", computer.hits);
	fprintf(outfile, "Misses: %d\n", computer.misses);
	fprintf(outfile, "Shots: %d\n", computer.shots);
	fprintf(outfile, "Hits to Miss Ratio: %.2f%%\n", computer.ratio * 100);
	fprintf(outfile, "%s\n", computer.win ? "Computer won.\n" : "Computer lost.\n");

	printf("Statistics outputted to logfile successfully!\n");

	fclose(outfile);

	return 0;
}