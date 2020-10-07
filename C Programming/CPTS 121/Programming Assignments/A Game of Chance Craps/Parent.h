/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 121; Lab Section 21                                       *
* Programming Assignment: PA 4 - A Game of Chance "Craps"               *
* Date: 10/1/2020                                                       *
* Description: This program plays the craps game where getting a random *
*              combination can make you win or lose.                    *
************************************************************************/

//Guard Code
#ifndef Parent_h

//Constant Macros
#define _CRT_SECURE_NO_WARNINGS

//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function Prototypes
void print_game_rules();
double get_bank_balance();
double get_wager_amount();
int check_wager_amount(double wager, double balance);
int roll_die();
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);

#endif