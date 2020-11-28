/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 121; Lab Section 21                                       *
* Programming Assignment: PA 7 - Poker: 5 Card Draw                     *
* Date: 11/18/2020                                                      *
* Description: This program emulates the game of Poker: 5 Card Draw.    *
************************************************************************/

#include "parent.h"

/****************************************************************
	* Function: rules()                                         *
	* Date Created: 11/18/2020                                  *
	* Date Last Modified: 11/18/2020                            *
	* Description: Displays the rules                           *
	* Input parameters: None                                    *
	* Returns: Nothing                                          *
	* Preconditions: None                                       *
	* Postconditions: The rules have been displayed             *
	*************************************************************/
void rules() {
	printf("In poker 5 card draw, you play against the computer and try to get a better hand than the computer. You start with 5\nrandomly drawn cards and see if that makes a pair, two pair, three of a kind, straight, flush, or a four of a kind. The last on this list awards the most points. You can proceed to see who the winner is or decide to redraw some or all of\nyour cards to see if you get a better hand. After redrawing, a winner is declared. You can play again.\n\n");
}

/****************************************************************
	* Function: initHands()                                     *
	* Date Created: 11/18/2020                                  *
	* Date Last Modified: 11/18/2020                            *
	* Description: Initializes the player and dealer structs.   *
	* Input parameters: player and dealer as hand structs       *
	* Returns: Nothing                                          *
	* Preconditions: player and dealer as hand structs          *
	* Postconditions: the hand structs have been initialized    *
	*************************************************************/
void initHands(Hand* player, Hand* dealer) {
	for (int i = 0; i < 5; i++) {
		player->hand[i].faceIndex = 0;
		player->hand[i].suitIndex = 0;
		dealer->hand[i].faceIndex = 0;
		dealer->hand[i].suitIndex = 0;
	}
}

/****************************************************************
	* Function: shuffle()                                       *
	* Date Created: 11/18/2020                                  *
	* Date Last Modified: 11/18/2020                            *
	* Description: shuffles the deck                            *
	* Input parameters: wDeck as a 2d integer array             *
	* Returns: Nothing                                          *
	* Preconditions: wDeck as a 2d integer array                *
	* Postconditions: The deck has been shuffled                *
	*************************************************************/
void shuffle(int wDeck[][13]){
	int row = 0;    //row number
	int column = 0; //column number
	int card = 0;   //card counter

	//for each of the 52 cards, choose slot of deck randomly
	for (card = 1; card <= 52; card++){
		//choose new random location until unoccupied slot found
		do{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		//place card number in chosen slot of deck
		wDeck[row][column] = card;
	}
}

/****************************************************************
	* Function: deal()                                          *
	* Date Created: 11/18/2020                                  *
	* Date Last Modified: 11/18/2020                            *
	* Description: deals cards to the hands                     *
	* Input parameters: wDeck, n, redraw, who as ints, wFace,   *
	* wSuit as char, player as Hand struct                      *
	* Returns: Nothing                                          *
	* Preconditions: wDeck, n, redraw, who as ints, wFace,      *
	* wSuit as char, player as Hand struct                      *
	* Postconditions: the cards have been dealt                 *
	*************************************************************/
void deal(int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* player, int n, int redraw, int who){
	int row = 0;    //row number
	int column = 0; //column number
	int card = 0;   //card counter

	//deal each of the 52 cards
	for (int i = redraw, card = 1; card <= 52 && i < n + redraw; card++){
		//loop through rows of wDeck
		for (row = 0; row <= 3; row++){
			// loop through columns of wDeck for current row
			for (column = 0; column <= 12; column++){
				//if slot contains current card, display card
				if (wDeck[row][column] == card && wDeck[row][column] != -1){
					player->hand[i-1].faceIndex = column;
					player->hand[i-1].suitIndex = row;

					if(who)
						printf("Card %d: %s of %s\n", i, wFace[column], wSuit[row]);

					wDeck[row][column] = -1;
					i++;
				}
			}
		}
	}
}

/****************************************************************
	* Function: pair()                                          *
	* Date Created: 11/18/2020                                  *
	* Date Last Modified: 11/18/2020                            *
	* Description: Checks if hand has a pair                    *
	* Input parameters: hand as hand struct and highest as int  *
	* Returns: Nothing                                          *
	* Preconditions: hand as hand struct and highest as int     *
	* Postconditions: The hand has been checked                 *
	*************************************************************/
int pair(Hand* hand, int* highest) {
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (hand->hand[i].faceIndex == hand->hand[j].faceIndex) { //Checks if pair
				*highest = 1;
				return 1;
			}
		}
	}

	return 0;
}

/****************************************************************
	* Function: twoPair()                                       *
	* Date Created: 11/18/2020                                  *
	* Date Last Modified: 11/18/2020                            *
	* Description: Checks if hand has a two pair                *
	* Input parameters: hand as hand struct and highest as int  *
	* Returns: Nothing                                          *
	* Preconditions: hand as hand struct and highest as int     *
	* Postconditions: The hand has been checked                 *
	*************************************************************/
int twoPair(Hand* hand, int* highest) {
	int count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (hand->hand[i].faceIndex == hand->hand[j].faceIndex) {
				count++;
				i++;
				break;
			}
		}

		if (count == 2) { //Checks if two pairs are there
			*highest = 2;
			return 1;
		}
	}

	return 0;
}

/****************************************************************
	* Function: triple()                                        *
	* Date Created: 11/18/2020                                  *
	* Date Last Modified: 11/18/2020                            *
	* Description: Checks if hand has a three of a kind         *
	* Input parameters: hand as hand struct and highest as int  *
	* Returns: Nothing                                          *
	* Preconditions: hand as hand struct and highest as int     *
	* Postconditions: The hand has been checked                 *
	*************************************************************/
int triple(Hand* hand, int* highest) {
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				if ((hand->hand[i].faceIndex == hand->hand[j].faceIndex) && (hand->hand[j].faceIndex == hand->hand[k].faceIndex)) { //Checks if three faces are equal
					*highest = 3;
					return 1;
				}
			}
		}
	}

	return 0;
}

/****************************************************************
	* Function: straight()                                      *
	* Date Created: 11/18/2020                                  *
	* Date Last Modified: 11/18/2020                            *
	* Description: Checks if hand has a straight                *
	* Input parameters: hand as hand struct and highest as int  *
	* Returns: Nothing                                          *
	* Preconditions: hand as hand struct and highest as int     *
	* Postconditions: The hand has been checked                 *
	*************************************************************/
int straight(Hand hand, int* highest) {
	//Modified selection sort to sort based on face index
	int passes = 0, max_index = 0, i = 0;
	for (; passes < 4; passes++) {
		for (i = 1, max_index = 0; i < 5 - passes; i++) {
			if (hand.hand[max_index].faceIndex < hand.hand[i].faceIndex)
				max_index = i;
		}

		int temp = hand.hand[max_index].faceIndex;
		hand.hand[max_index].faceIndex = hand.hand[4 - passes].faceIndex;
		hand.hand[4 - passes].faceIndex = temp;
	}

	//Checks if all cards are chronological
	if ((hand.hand[0].faceIndex + 4 == hand.hand[1].faceIndex + 3) && (hand.hand[1].faceIndex + 3 == hand.hand[2].faceIndex + 2) && (hand.hand[2].faceIndex + 2 == hand.hand[3].faceIndex + 1) && (hand.hand[3].faceIndex + 1 == hand.hand[4].faceIndex)) {
		*highest = 4;
		return 1;
	}

	return 0;
}

/****************************************************************
	* Function: flush()                                         *
	* Date Created: 11/18/2020                                  *
	* Date Last Modified: 11/18/2020                            *
	* Description: Checks if hand has a flush                   *
	* Input parameters: hand as hand struct and highest as int  *
	* Returns: Nothing                                          *
	* Preconditions: hand as hand struct and highest as int     *
	* Postconditions: The hand has been checked                 *
	*************************************************************/
int flush(Hand* hand, int* highest) {
	//Checks if all suits are equal
	if ((hand->hand[0].suitIndex == hand->hand[1].suitIndex) && (hand->hand[1].suitIndex == hand->hand[2].suitIndex) && (hand->hand[2].suitIndex == hand->hand[3].suitIndex) && (hand->hand[3].suitIndex == hand->hand[4].suitIndex)) {
		*highest = 5;
		return 1;
	}

	return 0;
}

/****************************************************************
	* Function: quadruple()                                     *
	* Date Created: 11/18/2020                                  *
	* Date Last Modified: 11/18/2020                            *
	* Description: Checks if hand has a four of a kind          *
	* Input parameters: hand as hand struct and highest as int  *
	* Returns: Nothing                                          *
	* Preconditions: hand as hand struct and highest as int     *
	* Postconditions: The hand has been checked                 *
	*************************************************************/
int quadruple(Hand* hand, int* highest) {
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				for (int l = k + 1; l < 5; l++) {
					if ((hand->hand[i].faceIndex == hand->hand[j].faceIndex) && (hand->hand[j].faceIndex == hand->hand[k].faceIndex) && (hand->hand[k].faceIndex == hand->hand[l].faceIndex)) { //Checks if four faces are equal
						*highest = 6;
						return 1;
					}
				}
			}
		}
	}

	return 0;
}

/****************************************************************
	* Function: highCard()                                      *
	* Date Created: 11/18/2020                                  *
	* Date Last Modified: 11/18/2020                            *
	* Description: checks which hand has the high card          *
	* Input parameters: player and dealer as hand structs       *
	* Returns: Nothing                                          *
	* Preconditions: player and dealer as hand structs          *
	* Postconditions: high card has been determined             *
	*************************************************************/
void highCard(Hand player, Hand dealer) {
	int x = 1;

	//Sorts both hands
	int passes = 0, max_index = 0, i = 0;
	for (; passes < 4; passes++) {
		for (i = 1, max_index = 0; i < 5 - passes; i++) {
			if (player.hand[max_index].faceIndex < player.hand[i].faceIndex)
				max_index = i;
		}

		int temp = player.hand[max_index].faceIndex;
		player.hand[max_index].faceIndex = player.hand[4 - passes].faceIndex;
		player.hand[4 - passes].faceIndex = temp;
	}

	passes = 0, max_index = 0, i = 0;

	for (; passes < 4; passes++) {
		for (i = 1, max_index = 0; i < 5 - passes; i++) {
			if (dealer.hand[max_index].faceIndex < dealer.hand[i].faceIndex)
				max_index = i;
		}

		int temp = dealer.hand[max_index].faceIndex;

		dealer.hand[max_index].faceIndex = dealer.hand[4 - passes].faceIndex;
		dealer.hand[4 - passes].faceIndex = temp;
	}

	//Checks which hand has the higher card on same index position
	for (i = 4; i >= 0; i--) {
		if (player.hand[i].faceIndex > dealer.hand[i].faceIndex) {
			printf("Player won with high card!");

			x = 0;
			break;
		}

		else if (player.hand[i].faceIndex < dealer.hand[i].faceIndex) {
			printf("Dealer won with high card!");
			x = 0;
			break;
		}
	}

	//Executes if both hands are the same
	if (x)
		printf("Draw!");
}