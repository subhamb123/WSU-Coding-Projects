/*************************************************************************************
* Programmer: Subham Behera                                                          *
* Class: CptS 122; Lab Section 13                                                    *
* Programming Assignment: PA 3 - Digital Music Manager & Doubly Linked Lists – Part 2*
* Date: 2/14/2021                                                                    *
* Description: This program manages music data with linked lists.                    *
**************************************************************************************/

#include "test.h"

int main() {
	srand((unsigned int)time(NULL)); //Initializes random
	FILE* infile = fopen("musicPlayList.csv", "r"), *outfile = fopen("updatedPlayList.csv", "w"); //Having one pointer caused me many problems, so I made two
	List playlist = { NULL }; //Initialize playlist
	int num = 0;
	char string[50] = "";
	
	while (num != 11) {
		printf("Choose from the menu below\n1. Load\n2. Store\n3. Display\n4. Insert\n5. Delete\n6. Edit\n7. Sort\n8. Rate\n9. Play\n10. Shuffle\n11. Exit\n\n");
		scanf("%d", &num);
		scanf("%c", &string); //Eats up garbage newline
		switch (num) {
		case 1: //If user selects load
			printf("\nSuccess: %d\n\n", load(infile, &playlist)); //Prints if successful after calling function
			break;
		case 2: //If user selects store
			printf("Success: %d\n\n", store(outfile, &playlist));
			break;
		case 3: //If user selects display
			printf("Enter option 1 if you want to view all records or option 2 if you want to view all records by a certain artist.\n");
			scanf("%d", &num);
			scanf("%c", &string);
			switch (num) {
			case 1: //If user wants to view all records
				printList(&playlist);
				break;
			case 2: //If user wants to view records by a certain artist
				printf("Enter the name of the artist.\n");
				gets(string);
				string[0] = toupper(string[0]); //Capitalizes first letter so user can input a name even with all lowercase
				displayByArtist(&playlist, string);
				break;
			default:
				puts("\nInvalid input!\n");
				break;
			}
			break;
		case 4: //If user selects insert
			printf("\nSuccess: %d\n\n", insert(&playlist, NULL)); //Writing null will prompt the user for new data instead of using a test case record
			break;
		case 5: //If user selects delete
			printf("Enter a song to delete\n");
			gets(string);
			printf("\nSuccess: %d\n\n", delete(&playlist, string));
			break;
		case 6: //If user selects edit
			printf("Enter the name of the artist to change that record.\n");
			gets(string);
			string[0] = toupper(string[0]);
			printf("\nSuccess: %d\n\n", edit(&playlist, string));
			scanf("%c", &string);
			break;
		case 7: //If user selects sort
			printf("\nSelect from the following menu (enter a number between 1 to 4)\n1. Sort based on artist (A-Z)\n2. Sort based on album title (A-Z)\n3. Sort based on rating (1-5)\n4. Sort based on times played (largest-smallest)\n\n");
			scanf("%d", &num);
			printf("\nSuccess: %d\n\n", sort(&playlist, num));
			scanf("%c", &string);
			break;
		case 8: //If user selects rate
			printf("Enter the name of the song to change the rating.\n");
			gets(string); //To capture multiple words spaced out
			printf("Enter your rating.\n");
			scanf("%d", &num);
			printf("\nSuccess: %d\n\n", rate(&playlist, string, num));
			scanf("%c", &string);
			break;
		case 9: //If user selects play
			printf("Enter the name of the song to play.\n");
			gets(string);
			play(&playlist, string);
			break;
		case 10: //If user selects shuffle
			shuffle(&playlist, NULL); //Writing null will shuffle based on random order instead of using the test case order
			break;
		case 11: //If user selects exit
			fclose(outfile);
			outfile = fopen("updatedPlayList.csv", "w");
			Exit(outfile, &playlist);
			break;
		default: //If user gives invalid option
			puts("\nInvalid input!\n");
			break;
		}
	}

	//Test cases after user exits program
	system("cls");
	puts("Here are some test cases\n");
	testInsert();
	delay(3000);
	testDelete();
	delay(3000);
	testShuffle();
	puts("Goodbye!\n");

	fclose(infile);
	fclose(outfile);

	return 0;
}