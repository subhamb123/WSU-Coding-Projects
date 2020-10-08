/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 121; Lab Section 21                                       *
* Programming Assignment: PA 4 - A Game of Chance "Craps"               *
* Date: 10/1/2020                                                       *
* Description: This program plays the craps game where getting a random *
*              combination can make you win or lose.                    *
************************************************************************/

//Includes the Parent.h header file.
#include "Parent.h"

//Function Definitions

/****************************************************************
	* Function: print_game_rules()                              *
	* Date Created: 10/1/2020                                   *
	* Date Last Modified: 10/1/2020                             *
	* Description: This prints the rules of the game.           *
	* Input parameters: None                                    *
	* Returns: Nothing                                          *
	* Preconditions: None                                       *
	* Postconditions: Rules have been displayed.                *
	*************************************************************/
void print_game_rules() {
	printf("In this game, you'll test your luck. The computer throws two dice and you winning or losing depends on the sum. If you \nget a sum 7 or 11 on the first throw, you win. 2, 3, or 12 results in a loss. And 4, 5, 6, 8, 9, or 10 means you have tokeep rolling until you hit this number again to win or rolling a 7 while doing this makes you lose. Every roll starts \nwith you gambling some money and if you win that round, that gets added to your stash, and if you lose, that gets \nsubtracted. You can leave any time by waging 0.\n");
}

/****************************************************************
	* Function: get_bank_balance()                              *
	* Date Created: 10/1/2020                                   *
	* Date Last Modified: 10/1/2020                             *
	* Description: Asks for player's balance.                   *
	* Input parameters: None                                    *
	* Returns: The amount of money as a double.                 *
	* Preconditions: None                                       *
	* Postconditions: The amount of money has been returned.    *
	*************************************************************/
double get_bank_balance() {
	double balance = 0;
	while (1) {
		printf("\nHow much money do you have? ");
		scanf("%lf", &balance);
		if (balance <= 0)
			printf("You must pitch in an amount greater than $0!\n");
		else
			break;
	}
	return balance;
}

/****************************************************************
	* Function: get_wager_amount()                              *
	* Date Created: 10/1/2020                                   *
	* Date Last Modified: 10/1/2020                             *
	* Description: Asks how much the player wants to wage.      *
	* Input parameters: None                                    *
	* Returns: The wager amount as a double.                    *
	* Preconditions: None                                       *
	* Postconditions: The wager amount has been returned.       *
	*************************************************************/
double get_wager_amount(){
	double wage = 0;
	printf("\nHow much money do you want to wage? ");
	scanf("%lf", &wage);
	return wage;
}

/****************************************************************
	* Function: check_wager_amount()                            *
	* Date Created: 10/1/2020                                   *
	* Date Last Modified: 10/1/2020                             *
	* Description: Checks if the wager provided is valid.       *
	* Input parameters: Wager and Balance                       *
	* Returns: True if wager is less than or equal to balance.  *
	* Preconditions: Wager and Balance                          *
	* Postconditions: 1 or 0 has been returned depending on     *
	*                 condition.                                *
	*************************************************************/
int check_wager_amount(double wager, double balance) {
	return wager <= balance && wager >= 0 ? 1 : 0;
}

/****************************************************************
	* Function: roll_die()                                      *
	* Date Created: 10/1/2020                                   *
	* Date Last Modified: 10/1/2020                             *
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
	* Function: calculate_sum_dice()                            *
	* Date Created: 10/1/2020                                   *
	* Date Last Modified: 10/1/2020                             *
	* Description: Calculates sum of two die                    *
	* Input parameters: Value of die 1 and die 2.               *
	* Returns: Sum of the two dies as an int.                   *
	* Preconditions: Value of die 1 and die 2.                  *
	* Postconditions: Sum of the two die has been returned.     *
	*************************************************************/
int calculate_sum_dice(int die1_value, int die2_value) {
	return die1_value + die2_value;
}

/****************************************************************
	* Function: is_win_loss_or_point()                          *
	* Date Created: 10/1/2020                                   *
	* Date Last Modified: 10/1/2020                             *
	* Description: Determines win or loss from round 1 results. *
	* Input parameters: Sum of the die as an int.               *
	* Returns: 1 if win, 0 is loss, -1 if point                 *
	* Preconditions: Sum of the die as an int.                  *
	* Postconditions: Result of round 1 has been returned.      *
	*************************************************************/
int is_win_loss_or_point(int sum_dice) {
	if (sum_dice == 7 || sum_dice == 11)
		return 1;
	if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
		return 0;
	return -1;
}

/****************************************************************
	* Function: is_point_loss_or_neither()                      *
	* Date Created: 10/1/2020                                   *
	* Date Last Modified: 10/1/2020                             *
	* Description: Determines win or loss based on point value  *
	* Input parameters: sum of the die and point value as ints  *
	* Returns: 1 if win, 0 is loss, -1 if neither are met.      *
	* Preconditions: sum of the die and point value as ints     *
	* Postconditions: Result has been returned                  *
	*************************************************************/
int is_point_loss_or_neither(int sum_dice, int point_value) {
	if (sum_dice == point_value)
		return 1;
	else if (sum_dice == 7)
		return 0;
	else
		return -1;
}

/****************************************************************
	* Function: adjust_bank_balance()                           *
	* Date Created: 10/1/2020                                   *
	* Date Last Modified: 10/1/2020                             *
	* Description: Adjusts the balance depending on win or loss.*
	* Input parameters: balance and wager as double and         *
	*                   add/subtract as int.                    *
	* Returns: addition if add/sub is 1 and subtraction if not. *
	* Preconditions: balance and wager as double and            *
	*                add/subtract as int.                       *
	* Postconditions: The result has been returned              *
	*************************************************************/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) {
	if (add_or_subtract == 1)
		return bank_balance + wager_amount;
	return bank_balance - wager_amount;
}

/****************************************************************
	* Function: chatter_messages()                              *
	* Date Created: 10/1/2020                                   *
	* Date Last Modified: 10/1/2020                             *
	* Description: Chats with the user based on what happens.   *
	* Input parameters: rolls & win/loss as an int and init and *
	*                   current balances as a double.           *
	* Returns: Nothing                                          *
	* Preconditions: rolls & win/loss as an int and init and    *
	*                current balances as a double.              *
	* Postconditions: A message has been displayed.             *
	*************************************************************/
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance) {
	int option = rand() % 4;
	if (number_rolls >= 10 && option == 0)
		printf("Be careful!!!\n");
	if (current_bank_balance >= 1.1*initial_bank_balance && option == 1)
		printf("How did you gain so much??\n");
	if (win_loss_neither == 1 && option == 2)
		printf("HOW? Lucky...\n");
	if (win_loss_neither == 0 && option == 3)
		printf("You deserve that.\n");
}