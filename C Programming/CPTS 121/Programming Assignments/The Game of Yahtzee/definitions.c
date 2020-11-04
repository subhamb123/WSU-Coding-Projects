/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 121; Lab Section 21                                       *
* Programming Assignment: PA 5 - The Game of Yahtzee                    *
* Date: 10/16/2020                                                      *
* Description: This program emulates the game of Yahtzee.               *
************************************************************************/

#include "parent.h"

/****************************************************************
	* Function: roll_die()                                      *
	* Date Created: 10/25/2020                                  *
	* Date Last Modified: 10/25/2020                            *
	* Description: Returns a random number between 1 and 6.     *
	* Input parameters: None                                    *
	* Returns: Random integer between 1 and 6.                  *
	* Preconditions: None                                       *
	* Postconditions: A random integer has been returned.       *
	*************************************************************/
int roll_die() {
	return (rand() % 6 + 1);
}

/****************************************************************
	* Function: combinations()                                  *
	* Date Created: 10/25/2020                                  *
	* Date Last Modified: 10/25/2020                            *
	* Description: Displays the different combinations.         *
	* Input parameters: None                                    *
	* Returns: Nothing                                          *
	* Preconditions: None                                       *
	* Postconditions: The combinations have been displayed.     *
	*************************************************************/
void combinations() {
	printf("\t1. Sum of 1s\t7. Three-of-a-kind\n");
	printf("\t2. Sum of 2s\t8. Four-of-a-kind\n");
	printf("\t3. Sum of 3s\t9. Full house\n");
	printf("\t4. Sum of 4s\t10. Small straight\n");
	printf("\t5. Sum of 5s\t11. Large straight\n");
	printf("\t6. Sum of 6s\t12. Yahtzee\n");
	printf("\t\t13. Chance\n");
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

/****************************************************************
	* Function: delay()                                         *
	* Date Created: 10/25/2020                                  *
	* Date Last Modified: 10/25/2020                            *
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
	* Function: rules()                                         *
	* Date Created: 10/25/2020                                  *
	* Date Last Modified: 10/25/2020                            *
	* Description: Displays the rules                           *
	* Input parameters: None                                    *
	* Returns: Nothing                                          *
	* Preconditions: None                                       *
	* Postconditions: The rules have been displayed             *
	*************************************************************/
void rules() {
	printf("Two players take turns rolling dice to achieve different combinations, each of which award different amount of points. \nThe objective is to have more points than your opponent. With each turn, a player first rolls all the dice, and then hasthe option to reroll any number of dice to get desired combination up to two times. Next, a player must choose a \ndistinct combination each turn. Then, the players switch. At the end, if the sum of combinations 1-6 is greater than 63 for a player, 35 bonus points is awarded. When the game ends, players have the option to play again.\n\n");
	delay(15000);
	printf("The following table will be shown whenever picking a combination: \n\n");
	combinations();
	printf("\n-Choosing combinations 1-6 sums up every occurance of a particular number depending on the combination and adds \n that to the total score. \n-Combination 7 checks if at least three dice are equal, then sums all the dice and this gets added to total score if \n condition is met. \n-Combination 8 is the same as 7, except with at least 4 dice. \n-Combination 9 awards 25 points if three dice have same value and the other two have different, but same value. \n-Combination 10 awards 30 points if at least four dice are in chronological order. \n-Combination 11 is the same as 10 but with all of the dice and awards 40 points. \n-Combination 12 is the same as 7 & 8, but with all of the dice and awards 50 points. \n-Combination 13 sums all of the dice and adds that to total score no matter the combination.\n\n");
}