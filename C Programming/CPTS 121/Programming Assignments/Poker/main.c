/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 121; Lab Section 21                                       *
* Programming Assignment: PA 7 - Poker: 5 Card Draw                     *
* Date: 11/18/2020                                                      *
* Description: This program emulates the game of Poker: 5 Card Draw.    *
************************************************************************/

#include "parent.h"

int main(void){
	int option = 0, x = 0, y = 0, card = 0, temp[5] = { 0 }, pHighest = 0, dHighest = 0;
	char garbage = '\0', c = '\0', ans = '\0';

	//Initialize suit array
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	//Initialize face array
	const char* face[13] = { "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };

	//initalize deck array
	int deck[4][13] = { 0 };

	Hand player, dealer;
	initHands(&player, &dealer); //Initializes the hands
	
	srand(time(NULL));

	while (option != 3) { //Option 3 is to exit		
		printf("1. Print game rules\n2. Start a game of poker 5 card draw\n3. Exit\n\nEnter a number depending on what you want to do.\n");
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
			//Resets all variables so consecutive rounds won't be affected from previous results.
			option = 0, x = 0, y = 0, card = 0, pHighest = 0, dHighest = 0;
			c = '\0', ans = '\0';

			for (int i = 0; i < 5; i++)
				temp[i] = 0;

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 13; j++) 
					deck[i][j] = 0;
			}

			shuffle(deck); //Shuffles the deck

			system("cls");
			printf("These are your cards:\n");

			//Chooses who is dealt cards first
			int random = rand() % 2;
			if (random) {
				deal(deck, &face, &suit, &player, 5, 1, 1); //This deals the cards. The 5 is the total number of cards, 1 is redraw parameter, and last 1 is if the cards are displayed or not.
				deal(deck, &face, &suit, &dealer, 5, 1, 0);
			}
			else {
				deal(deck, &face, &suit, &dealer, 5, 1, 0);
				deal(deck, &face, &suit, &player, 5, 1, 1);
			}

			printf("\n");

			//Asks if user wants to redraw.
			while (c != 'y' && c != 'n') {
				printf("Do you want to redraw a card? (y/n)\n");
				scanf("%c", &c);

				while (1) {
					scanf("%c", &garbage);

					if (garbage == '\n')
						break;
				}

				c = tolower(c);
			}

			//Executes if user wants to redraw a card
			if (c == 'y') {
				ans = 'y';

				while (ans == 'y' && x < 5) {
					x++;

					//Executes if invalid response is provided or if it's the first time the user is prompted to redraw a card
					while (card < 1 || card > 5 || temp[card - 1] != 0) {
						printf("Which card do you want to redraw? (1-5)\n");
						scanf("%d", &card);
						while (1) {
							scanf("%c", &garbage);

							if (garbage == '\n')
								break;
						}
					}

					deal(deck, &face, &suit, &player, 1, card, 1);
					temp[card - 1]++; //Tracks which cards have already been picked.

					//Asks if user wants to redraw another card.
					if (x < 5) {
						printf("Do you want to redraw another card? (y/n)\n");
						scanf("%c", &ans);

						while (1) {
							scanf("%c", &garbage);

							if (garbage == '\n')
								break;
						}

						ans = tolower(ans);
					}
				}
			}

			system("cls");

			printf("Your cards:\n");
			for (int i = 0; i < 5; i++) 
				printf("Card %d: %s of %s\n", i + 1, face[player.hand[i].faceIndex], suit[player.hand[i].suitIndex]);

			//Displays the dealer's cards before
			printf("\nDealer's cards before:\n");
			for (int i = 0; i < 5; i++)
				printf("Card %d: %s of %s\n", i + 1, face[dealer.hand[i].faceIndex], suit[dealer.hand[i].suitIndex]);

			//Dealer decides which cards to replace. Four of a kind, flush, and straight are good enough.
			if (quadruple(&dealer, &dHighest))
				;

			else if (flush(&dealer, &dHighest))
				;

			else if (straight(dealer, &dHighest))
				;

			else if (triple(&dealer, &dHighest)) { //Strives to get a four of a kind
				int i, j, k, l, m;
				for (i = 0; i < 5; i++) {
					for (j = i + 1; j < 5; j++) {
						for (k = j + 1; k < 5; k++) {
							if ((dealer.hand[i].faceIndex == dealer.hand[j].faceIndex) && (dealer.hand[j].faceIndex == dealer.hand[k].faceIndex)) {
								y = 1;
								break;
							}
						}

						if (y)
							break;
					}

					if (y)
						break;
				}

				//Determines which cards weren't part of the combo and redraws them.
				for (int a = 0; a < 5; a++) {
					if (i != a && j != a && k != a) {
						l = a;
						break;
					}
				}

				for (int a = 0; a < 5; a++) {
					if (i != a && j != a && k != a && l != a){
						m = a;
						break;
					}
				}

				deal(deck, &face, &suit, &dealer, 1, l + 1, 0);
				deal(deck, &face, &suit, &dealer, 1, m + 1, 0);
			}

			else if (twoPair(&dealer, &dHighest)) { //Strives to get a three of a kind
				int count = 0, i, j, k, l, m;
				for (k = 0; k < 5; k++) {
					for (l = k + 1; l < 5; l++) {
						if (dealer.hand[k].faceIndex == dealer.hand[l].faceIndex) {
							if (count == 0) {
								i = k;
								j = l;
							}

							count++;

							if(count == 1)
								k++;

							break;
						}
					}

					if (count == 2) 
						break;
				}

				for (int a = 0; a < 5; a++) {
					if (i != a && j != a && k != a && l != a) {
						m = a;
						break;
					}
				}

				deal(deck, &face, &suit, &dealer, 1, m + 1, 0);
			}

			else if (pair(&dealer, &dHighest)) { //Strives to get a two pair.
				int i, j, k, l, m;
				for (i = 0; i < 5; i++) {
					for (j = i + 1; j < 5; j++) {
						if (dealer.hand[i].faceIndex == dealer.hand[j].faceIndex) {
							y = 1;
							break;
						}
					}

					if (y)
						break;
				}

				for (int a = 0; a < 5; a++) {
					if (i != a && j != a) {
						k = a;
						break;
					}
				}

				for (int a = 0; a < 5; a++) {
					if (i != a && j != a && k != a) {
						l = a;
						break;
					}
				}

				for (int a = 0; a < 5; a++) {
					if (i != a && j != a && k != a && l != a) {
						m = a;
						break;
					}
				}

				deal(deck, &face, &suit, &dealer, 1, k + 1, 0);
				deal(deck, &face, &suit, &dealer, 1, l + 1, 0);
				deal(deck, &face, &suit, &dealer, 1, m + 1, 0);
			}

			else //Redraws all 5 cards when no combo is there
				deal(deck, &face, &suit, &dealer, 5, 1, 0);

			//Displays the dealer's cards after
			printf("\nDealer's cards after:\n");
			for (int i = 0; i < 5; i++)
				printf("Card %d: %s of %s\n", i + 1, face[dealer.hand[i].faceIndex], suit[dealer.hand[i].suitIndex]);

			printf("\n");
			
			//Assigns arbitrary points
			pair(&player, &pHighest); //1 point
			twoPair(&player, &pHighest); //2 points
			triple(&player, &pHighest); //3 points
			straight(player, &pHighest); //4 points
			flush(&player, &pHighest); //5 points
			quadruple(&player, &pHighest); //6 points

			pair(&dealer, &dHighest);
			twoPair(&dealer, &dHighest);
			triple(&dealer, &dHighest);
			straight(dealer, &dHighest);
			flush(&dealer, &dHighest);
			quadruple(&dealer, &dHighest);

			//Player won
			if (pHighest > dHighest) {
				printf("Player won ");
				x = 1;
			}

			//Dealer won
			else if (pHighest < dHighest){
				printf("Dealer won ");
				x = 1;
			}

			//Executes when both have same combo
			else {
				highCard(player, dealer); //High card breaks the tie
				x = 0;
			}
			
			//Prints how a player won
			if (x) {
				switch (pHighest > dHighest ? pHighest : dHighest) {
				case 1:
					printf("with a pair!");
					break;
				case 2:
					printf("with a two pair!");
					break;
				case 3:
					printf("with a three of a kind!");
					break;
				case 4:
					printf("with a straight!");
					break;
				case 5:
					printf("with a flush!");
					break;
				case 6:
					printf("with a four of a kind!");
					break;
				}
			}

			printf("\n\n");
		}
	}

	//End of program
	system("cls");
	printf("Goodbye!\n");
	return 0;
}