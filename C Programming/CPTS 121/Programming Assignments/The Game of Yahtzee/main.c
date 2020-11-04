/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 121; Lab Section 21                                       *
* Programming Assignment: PA 5 - The Game of Yahtzee                    *
* Date: 10/16/2020                                                      *
* Description: This program emulates the game of Yahtzee.               *
************************************************************************/

#include "parent.h"

int main() {
	srand((unsigned int)time(NULL)); //Initializes random
	int option = 0, p1[5] = { 0 }, p2[5] = { 0 }, temp[5] = { 0 }, score1[13] = { 0 }, score2[13] = { 0 }, arr1[13] = { 0 }, arr2[13] = { 0 }, rolls = 0, round = 0, die = 0, combination = 0, partScore = 0, totSc1 = 0, totSc2 = 0, bonus1 = 0, bonus2 = 0, y1 = 0, y2 = 0;
	char c = '\0', ans = 'y', garbage = '\0';
	while (option != 3) { //Option 3 is to exit
		int x = 0;
		option = 0;
		printf("1. Print game rules\n2. Start a game of Yahtzee\n3. Exit\n\nEnter a number depending on what you want to do.\n");
		scanf("%d", &option);
		//Deals with garbage input
		while (1) {
			scanf("%c", &garbage);
			if (garbage == '\n')
				break;
		}
		putchar('\n');
		//Prints out rules
		if (option == 1) {
			system("cls");
			rules();
		}
		//Main game block
		else if (option == 2) {
			while (round < 13) {
				round++;
				system("cls");
				printf("Round %d\n", round);
				printf("Current Score: %d\n", totSc1);
				printf("Player 1, enter any key to roll dice.\n");
				scanf("%c", &c);
				//Fixes formatting
				if (c != '\n') {
					scanf("%c", &c);
					x = 1;
				}

				if (x)
					putchar('\n');
				
				//Rolls dice
				for (int i = 0; i < 5; i++) {
					p1[i] = roll_die();
					printf("Die %d: %d \n", i + 1, p1[i]);
				}
				//Checks for additional Yahtzees
				if ((p1[0] == p1[1]) && (p1[1] == p1[2]) && (p1[2] == p1[3]) && (p1[3] == p1[4]) && (y1 == 1)) {
					printf("You got another Yahtzee! 100 bonus points!\n");
					totSc1 += 100;
					printf("Current Score: %d\n", totSc1);
				}
				rolls++;
				putchar('\n');
				while (rolls < 3) {
					x = 0, die = 0;
					//Formatting
					if (rolls != 1) {
						for (int i = 0; i < 5; i++)
							printf("Die %d: %d \n", i + 1, p1[i]);
					}
					combinations(); //Displays combinations
					c = '\0';
					//Executes if invalid response is provided or if it's the first time the user is prompted to use the combination
					while (c != 'y' && c != 'n') {
						printf("Do you want to use your roll as a combination? (y/n)\n");
						scanf("%c", &c);
						while (1) {
							scanf("%c", &garbage);
							if (garbage == '\n')
								break;
						}
						
						c = tolower(c);
					}
					//Executes if user wants to reroll the dice
					if (c == 'n') {
						ans = 'y';
						while (ans == 'y' && x < 5){
							x++;
							//Executes if invalid response is provided or if it's the first time the user is prompted to reroll a die
							while (die < 1 || die > 5 || temp[die - 1] == 1) {
								printf("Which die do you want to reroll? (1-5)\n");
								scanf("%d", &die);
								while (1) {
									scanf("%c", &garbage);
									if (garbage == '\n')
										break;
								}
							}
							
							p1[die - 1] = roll_die();
							temp[die - 1] = 1;
							printf("Die %d: %d\n", die, p1[die - 1]);

							//Asks if user wants to roll another die.
							if (x < 5) {
								printf("Do you want to roll another die? (y/n)\n");
								scanf("%c", &ans);
								while (1) {
									scanf("%c", &garbage);
									if (garbage == '\n')
										break;
								}
								ans = tolower(ans);
							}
							else
								delay(1000);
						}
						//This clears the array which keeps track of if a die has been rerolled so all dice can be rerolled for each reroll set. 
						for (int i = 0; i < 5; i++)
							temp[i] = 0;
						rolls++;
						system("cls");
					}
					else
						break; //When user is done rerolling.
				}
				system("cls");
				for (int i = 0; i < 5; i++)
					printf("Die %d: %d \n", i + 1, p1[i]);

				combinations();
				printf("Cominations left: ");
				//Displays which combinations are available.
				for (int i = 0; i < 13; i++) {
					if (arr1[i] == 0)
						printf("%d ", i + 1);
				}
				putchar('\n');
				//Executes if invalid response is provided or if it's the first time the user is prompted to select a combination
				while (!(combination >= 1) || !(combination <= 13) || arr1[combination-1] == 1) {
					printf("What combination do you want to use?\n");
					scanf("%d", &combination);
					while (1) {
						scanf("%c", &garbage);
						if (garbage == '\n')
							break;
					}
				}//                     |||
				//Combination 1         vvv keeps track of if a combination is already used
				if (combination == 1 && arr1[0] == 0) {
					for (int i = 0; i < 5; i++) {
						//For every occurance, partScore is incremented by value
						if (p1[i] == 1)
							partScore++;
					}
					score1[0] = partScore;
					arr1[0]++; //To avoid user from picking this combination again
				}
				//Combination 2
				else if (combination == 2 && arr1[1] == 0) {
					for (int i = 0; i < 5; i++) {
						if (p1[i] == 2)
							partScore+=2;
					}
					score1[1] = partScore;
					arr1[1]++;
				}
				//Combination 3
				else if (combination == 3 && arr1[2] == 0) {
					for (int i = 0; i < 5; i++) {
						if (p1[i] == 3)
							partScore+=3;
					}
					score1[2] = partScore;
					arr1[2]++;
				}
				//Combination 4
				else if (combination == 4 && arr1[3] == 0) {
					for (int i = 0; i < 5; i++) {
						if (p1[i] == 4)
							partScore+=4;
					}
					score1[3] = partScore;
					arr1[3]++;
				}
				//Combination 5
				else if (combination == 5 && arr1[4] == 0) {
					for (int i = 0; i < 5; i++) {
						if (p1[i] == 5)
							partScore+=5;
					}
					score1[4] = partScore;
					arr1[4]++;
				}
				//Combination 6
				else if (combination == 6 && arr1[5] == 0) {
					for (int i = 0; i < 5; i++) {
						if (p1[i] == 6)
							partScore+=6;
					}
					score1[5] = partScore;
					arr1[5]++;
				}
				//Combination 7
				else if (combination == 7 && arr1[6] == 0) {
					//Loops for every combo of 3 dice and checks if they are all equal
					for (int i = 0; i < 5; i++) {
						for (int j = i + 1; j < 5; j++) {
							for (int k = j + 1; k < 5; k++) {
								if ((p1[i] == p1[j]) && (p1[j] == p1[k])) {
									partScore = p1[0] + p1[1] + p1[2] + p1[3] + p1[4];
									break;
								}
							}
						}
					}
					score1[6] = partScore;
					arr1[6]++;
				}
				//Combination 8
				else if (combination == 8 && arr1[7] == 0) {
					//Loops for every combo of 4 dice and checks if they are all equal
					for (int i = 0; i < 5; i++) {
						for (int j = i + 1; j < 5; j++) {
							for (int k = j + 1; k < 5; k++) {
								for (int l = k + 1; l < 5; l++) {
									if ((p1[i] == p1[j]) && (p1[j] == p1[k]) && (p1[k] == p1[l])) {
										partScore = p1[0] + p1[1] + p1[2] + p1[3] + p1[4];
										break;
									}
								}
							}
						}
					}
					score1[7] = partScore;
					arr1[7]++;
				}
				//Combination 9
				else if (combination == 9 && arr1[8] == 0) {
					//Loops for every combo of 3 dice and checks if they are all equal
					int die1 = 0, die2 = 0;
					for (int i = 0; i < 5; i++) {
						for (int j = i + 1; j < 5; j++) {
							for (int k = j + 1; k < 5; k++) {
								if ((p1[i] == p1[j]) && (p1[j] == p1[k])) {
									temp[i] = 1, temp[j] = 1, temp[k] = 1;
									//This finds the remaining two values
									for (int l = 0; l < 5; l++) {
										if (temp[l] == 0) {
											die1 = p1[l];
											temp[l] = 1;
											break;
										}
									}
									for (int l = 0; l < 5; l++) {
										if (temp[l] == 0) {
											die2 = p1[l];
											temp[l] = 1;
											break;
										}
									}
									//If remaining two dice are same, the points are awarded.
									if (die1 == die2)
										partScore = 25;
								}
							}
						}
					}
					for (int i = 0; i < 5; i++)
						temp[i] = 0;
					score1[8] = partScore;
					arr1[8]++;
				}
				//Combination 10
				else if (combination == 10 && arr1[9] == 0) {
					//Sorts the passed array
					int* dup = NULL;
					dup = selection_sort(p1, 5);
					//Loops for every combo of 3 dice and checks if they are all chronological
					for (int i = 0; i < 5; i++) {
						for (int j = i + 1; j < 5; j++) {
							for (int k = j + 1; k < 5; k++) {
								for (int l = k + 1; l < 5; l++) {
									if ((dup[i] + 3 == dup[j] + 2) && (dup[j] + 2 == dup[k] + 1) && (dup[k] + 1 == dup[l])) {
										partScore = 30;
										break;
									}
								}
							}
						}
					}
					score1[9] = partScore;
					arr1[9]++;
				}
				//Combination 11
				else if (combination == 11 && arr1[10] == 0) {
					int* dup = NULL;
					dup = selection_sort(p1, 5);
					//Loops for every combo of 4 dice and checks if they are all chronological
					if ((dup[0] + 4 == dup[1] + 3) && (dup[1] + 3 == dup[2] + 2) && (dup[2] + 2 == dup[3] + 1) && (dup[3] + 1 == dup[4]))
						partScore = 40;

					score1[10] = partScore;
					arr1[10]++;
				}
				//Combination 12
				else if (combination == 12 && arr1[11] == 0) {
					//Checks if all dice are equal
					if ((p1[0] == p1[1]) && (p1[1] == p1[2]) && (p1[2] == p1[3]) && (p1[3] == p1[4]))
						partScore = 50;

					y1++;
					score1[11] = partScore;
					arr1[11]++;
				}
				//Combination 13
				else if (combination == 13 && arr1[12] == 0) {
					//Sums all of the dice and awards that many points
					partScore = p1[0] + p1[1] + p1[2] + p1[3] + p1[4];;
					score1[12] = partScore;
					arr1[12]++;
				}

				totSc1 += partScore; //Adds to total score
				if(partScore == 1)
					printf("1 point has been added to player 1's score.\n");
				else
					printf("%d points have been added to player 1's score.\n", partScore);
				
				//Resets variables
				partScore = 0;
				rolls = 0;
				combination = 0;

				delay(3000);

				//Player 2's turn
				system("cls");
				printf("Current Score: %d\n", totSc2);
				printf("Player 2, enter any key to roll dice.\n");
				scanf("%c", &c);
				
				if (c != '\n') {
					scanf("%c", &c);
					x = 1;
				}

				if (x)
					putchar('\n');

				
				for (int i = 0; i < 5; i++) {
					p2[i] = roll_die();
					printf("Die %d: %d \n", i + 1, p2[i]);
				}

				if ((p2[0] == p2[1]) && (p2[1] == p2[2]) && (p2[2] == p2[3]) && (p2[3] == p2[4]) && (y2 == 1)) {
					printf("You got another Yahtzee! 100 bonus points!\n");
					totSc2 += 100;
					printf("Current Score: %d\n", totSc2);
				}
				rolls++;
				putchar('\n');
				while (rolls < 3) {
					x = 0, die = 0;
					
					if (rolls != 1) {
						for (int i = 0; i < 5; i++)
							printf("Die %d: %d \n", i + 1, p2[i]);
					}
					combinations(); 
					c = '\0';
					
					while (c != 'y' && c != 'n') {
						printf("Do you want to use your roll as a combination? (y/n)\n");
						scanf("%c", &c);
						while (1) {
							scanf("%c", &garbage);
							if (garbage == '\n')
								break;
						}

						c = tolower(c);
					}
					
					if (c == 'n') {
						ans = 'y';
						while (ans == 'y' && x < 5) {
							x++;
							
							while (die < 1 || die > 5 || temp[die - 1] == 1) {
								printf("Which die do you want to reroll? (1-5)\n");
								scanf("%d", &die);
								while (1) {
									scanf("%c", &garbage);
									if (garbage == '\n')
										break;
								}
							}

							p2[die - 1] = roll_die();
							temp[die - 1] = 1;
							printf("Die %d: %d\n", die, p2[die - 1]);

							if (x < 5) {
								printf("Do you want to roll another die? (y/n)\n");
								scanf("%c", &ans);
								while (1) {
									scanf("%c", &garbage);
									if (garbage == '\n')
										break;
								}
								ans = tolower(ans);
							}
							else
								delay(1000);
						}
						
						for (int i = 0; i < 5; i++)
							temp[i] = 0;
						rolls++;
						system("cls");
					}
					else
						break;
				}
				system("cls");
				for (int i = 0; i < 5; i++)
					printf("Die %d: %d \n", i + 1, p2[i]);

				combinations();
				printf("Cominations left: ");
				
				for (int i = 0; i < 13; i++) {
					if (arr2[i] == 0)
						printf("%d ", i + 1);
				}
				putchar('\n');
				
				while (!(combination >= 1) || !(combination <= 13) || arr2[combination - 1] == 1) {
					printf("What combination do you want to use?\n");
					scanf("%d", &combination);
					while (1) {
						scanf("%c", &garbage);
						if (garbage == '\n')
							break;
					}
				}
				
				if (combination == 1 && arr2[0] == 0) {
					for (int i = 0; i < 5; i++) {
						if (p2[i] == 1)
							partScore++;
					}
					score2[0] = partScore;
					arr2[0]++;
				}
				
				else if (combination == 2 && arr2[1] == 0) {
					for (int i = 0; i < 5; i++) {
						if (p2[i] == 2)
							partScore += 2;
					}
					score2[1] = partScore;
					arr2[1]++;
				}
				
				else if (combination == 3 && arr2[2] == 0) {
					for (int i = 0; i < 5; i++) {
						if (p2[i] == 3)
							partScore += 3;
					}
					score2[2] = partScore;
					arr2[2]++;
				}
				
				else if (combination == 4 && arr2[3] == 0) {
					for (int i = 0; i < 5; i++) {
						if (p2[i] == 4)
							partScore += 4;
					}
					score2[3] = partScore;
					arr2[3]++;
				}
				
				else if (combination == 5 && arr2[4] == 0) {
					for (int i = 0; i < 5; i++) {
						if (p2[i] == 5)
							partScore += 5;
					}
					score2[4] = partScore;
					arr2[4]++;
				}
				
				else if (combination == 6 && arr2[5] == 0) {
					for (int i = 0; i < 5; i++) {
						if (p2[i] == 6)
							partScore += 6;
					}
					score2[5] = partScore;
					arr2[5]++;
				}
				
				else if (combination == 7 && arr2[6] == 0) {
					for (int i = 0; i < 5; i++) {
						for (int j = i + 1; j < 5; j++) {
							for (int k = j + 1; k < 5; k++) {
								if ((p2[i] == p2[j]) && (p2[j] == p2[k])) {
									partScore = p2[0] + p2[1] + p2[2] + p2[3] + p2[4];
									break;
								}
							}
						}
					}
					score2[6] = partScore;
					arr2[6]++;
				}
				
				else if (combination == 8 && arr2[7] == 0) {
					for (int i = 0; i < 5; i++) {
						for (int j = i + 1; j < 5; j++) {
							for (int k = j + 1; k < 5; k++) {
								for (int l = k + 1; l < 5; l++) {
									if ((p2[i] == p2[j]) && (p2[j] == p2[k]) && (p2[k] == p2[l])) {
										partScore = p2[0] + p2[1] + p2[2] + p2[3] + p2[4];
										break;
									}
								}
							}
						}
					}
					score2[7] = partScore;
					arr2[7]++;
				}
				
				else if (combination == 9 && arr2[8] == 0) {
					int die1 = 0, die2 = 0;
					for (int i = 0; i < 5; i++) {
						for (int j = i + 1; j < 5; j++) {
							for (int k = j + 1; k < 5; k++) {
								if ((p2[i] == p2[j]) && (p2[j] == p2[k])) {
									temp[i] = 1, temp[j] = 1, temp[k] = 1;
									for (int l = 0; l < 5; l++) {
										if (temp[l] == 0) {
											die1 = p2[l];
											temp[l] = 1;
											break;
										}
									}
									for (int l = 0; l < 5; l++) {
										if (temp[l] == 0) {
											die2 = p2[l];
											temp[l] = 1;
											break;
										}
									}
									if (die1 == die2)
										partScore = 25;
								}
							}
						}
					}
					for (int i = 0; i < 5; i++)
						temp[i] = 0;
					score2[8] = partScore;
					arr2[8]++;
				}
				
				else if (combination == 10 && arr2[9] == 0) {
					int* dup = NULL;
					dup = selection_sort(p2, 5);
					for (int i = 0; i < 5; i++) {
						for (int j = i + 1; j < 5; j++) {
							for (int k = j + 1; k < 5; k++) {
								for (int l = k + 1; l < 5; l++) {
									if ((dup[i] + 3 == dup[j] + 2) && (dup[j] + 2 == dup[k] + 1) && (dup[k] + 1 == dup[l])) {
										partScore = 30;
										break;
									}
								}
							}
						}
					}
					score2[9] = partScore;
					arr2[9]++;
				}
				
				else if (combination == 11 && arr2[10] == 0) {
					int* dup = NULL;
					dup = selection_sort(p2, 5);
					if ((dup[0] + 4 == dup[1] + 3) && (dup[1] + 3 == dup[2] + 2) && (dup[2] + 2 == dup[3] + 1) && (dup[3] + 1 == dup[4]))
						partScore = 40;

					score2[10] = partScore;
					arr2[10]++;
				}
				
				else if (combination == 12 && arr2[11] == 0) {
					if ((p2[0] == p2[1]) && (p2[1] == p2[2]) && (p2[2] == p2[3]) && (p2[3] == p2[4]))
						partScore = 50;

					y2++;
					score2[11] = partScore;
					arr2[11]++;
				}
				
				else if (combination == 13 && arr2[12] == 0) {
					partScore = p2[0] + p2[1] + p2[2] + p2[3] + p2[4];;
					score2[12] = partScore;
					arr2[12]++;
				}

				totSc2 += partScore;
				if (partScore == 1)
					printf("1 point has been added to player 2's score.\n");
				else
					printf("%d points have been added to player 2's score.\n", partScore);

				partScore = 0;
				rolls = 0;
				combination = 0;

				delay(3000);
			}

			system("cls");

			//Adds bonus if applicable
			for (int i = 0; i < 6; i++) {
				bonus1 += score1[i];
				bonus2 += score2[i];
			}
			if (bonus1 >= 63) {
				totSc1 += 35;
				printf("35 bonus points has been added to player 1's score!\n");
			}
			if (bonus2 >= 63) {
				totSc2 += 35;
				printf("35 bonus points has been added to player 2's score!\n");
			}
			putchar('\n');
			//Prints final scores and determines winner
			printf("Player 1's final score: %d\n", totSc1);
			printf("Player 2's final score: %d\n", totSc2);
			if (totSc1 > totSc2)
				printf("Player 1 wins!\n\n");
			else if (totSc1 < totSc2)
				printf("Player 2 wins!\n\n");
			else
				printf("Draw!\n\n");

			//Resets all of the values
			bonus1 = 0, bonus2 = 0, totSc1 = 0, totSc2 = 0, y1 = 0, y2 = 0, round = 0;
			for (int i = 0; i < 13; i++) {
				score1[i] = 0;
				score2[i] = 0;
				arr1[i] = 0;
				arr2[i] = 0;
			}
		}
	}
	//End of program
	system("cls");
	printf("Goodbye!\n");

	return 0;
}