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

int main() {
	srand((unsigned int)time(NULL)); //Sets up random.
	print_game_rules(); //Prints game rules.
	double initBalance = get_bank_balance() /*Prompts user for their initial balance*/, finalBalance = initBalance, wage = 1;
	int die1 = 0, die2 = 0, sum = 0, point = 0,  roll = 0, rolls = 0, x = 1;
	char c = '\0'; //Initializes a garbage character collector.

	while (wage != 0) {
		printf("Current Balance: $%.2f\n", finalBalance); //Displays their current balance
		//This block only executes when their balance becomes $0
		if (finalBalance == 0) {
			printf("You're broke! Better luck next time...\n");
			x = 0;
			break;
		}
		//This block runs until the user provided a wager less than or equal to their balance amount.
		while (1) {
			wage = get_wager_amount();
			if (check_wager_amount(wage, finalBalance) == 0)
				printf("Wager amount has to be less than your balance!\n");
			else
				break;
		}
		scanf("%c", &c); //Eats up the newline when wager is provided so pressing enter when rolling the die works.
		if (wage != 0) {
			printf("Press enter to roll die.\n");
			scanf("%c", &c);
			rolls++; //Incremeants rolls
			die1 = roll_die(); //A random number between 1 and 6 is returned and stored.
			die2 = roll_die();
			sum = calculate_sum_dice(die1, die2); //This stores the sum of the two die.
			point = sum;

			printf("Roll %d Sum: %d\n", rolls, sum); //Prints out the sum of that roll.

			roll = is_win_loss_or_point(sum); //Stores the result of win, loss, or point of first round.

			//First round win condition. 
			if (roll == 1) {
				finalBalance = adjust_bank_balance(finalBalance, wage, 1);
				chatter_messages(rolls, roll, initBalance, finalBalance);
			}

			//First round lose condition.
			else if (roll == 0) {
				finalBalance = adjust_bank_balance(finalBalance, wage, 0);
				chatter_messages(rolls, roll, initBalance, finalBalance);
			}

			//First round point condition.
			else {
				//This block runs until the user wins or loses for rounds after the first.
				while (1) {
					printf("Press enter to roll die.\n");
					scanf("%c", &c);
					rolls++;
					die1 = roll_die();
					die2 = roll_die();
					sum = calculate_sum_dice(die1, die2);
					printf("Roll %d Sum: %d\n", rolls, sum);
					roll = is_point_loss_or_neither(sum, point);

					//Win condition and breaks the while loop.
					if (roll == 1) {
						finalBalance = adjust_bank_balance(finalBalance, wage, 1);
						chatter_messages(rolls, roll, initBalance, finalBalance);
						break;
					}

					//Lose condition and breaks the while loop.
					else if (roll == 0) {
						finalBalance = adjust_bank_balance(finalBalance, wage, 0);
						chatter_messages(rolls, roll, initBalance, finalBalance);
						break;
					}
				}
			}
		}
		
	}
	
	//Only prints when user doesn't want to play anymore by waging $0.
	if(x)
		printf("Your final balance is $%.2f.\n", finalBalance); 

	return 0;
}