/*************************************************************************************
* Programmer: Subham Behera                                                          *
* Class: CptS 122; Lab Section 13                                                    *
* Programming Assignment: PA 3 - Digital Music Manager & Doubly Linked Lists – Part 2*
* Date: 2/14/2021                                                                    *
* Description: This program manages music data with linked lists.                    *
**************************************************************************************/

#include "parent.h"

/****************************************************************
* Function: makeNode()                                          *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Makes a node so data can be inserted in list.    *
* Input parameters: pNewData as double immutable record type    *
* Returns: Pointer to the new node                              *
* Preconditions: pNewData as double immutable record type       *
* Postconditions: A node has been created.                      *
*****************************************************************/
Node* makeNode(const Record* const pNewData) {
	Node* pMem = (Node*)malloc(sizeof(Node)); //Allocates the node in the heap

	//Initializes the node with the given record.
	if (pMem != NULL) {
		pMem->pNext = NULL;
		pMem->pPrev = NULL;
		strcpy(pMem->data.album, pNewData->album);
		strcpy(pMem->data.artist, pNewData->artist);
		strcpy(pMem->data.genre, pNewData->genre);
		strcpy(pMem->data.song, pNewData->song);
		pMem->data.length.minutes = pNewData->length.minutes;
		pMem->data.length.seconds = pNewData->length.seconds;
		pMem->data.timesPlayed = pNewData->timesPlayed;
		pMem->data.rating = pNewData->rating;
	}

	return pMem;
}

/****************************************************************
* Function: insertFront()                                       *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Inserts record at front of list                  *
* Input parameters: pList as List pointer and pNewData as       *
*                   double immutable record type                *
* Returns: Success as int                                       *
* Preconditions: pList as List pointer and pNewData as          *
*                double immutable record type                   *
* Postconditions: Record has been inserted to front of list.    *
*****************************************************************/
int insertFront(List* pList, const Record* const pNewData) {
	Node* pMem = makeNode(pNewData); //Makes node with the data and stores it
	int success = 0;
	if (pMem != NULL) {
		success = 1;
		pMem->pNext = pList->pHead; //Shifts everything to the right
		pList->pHead = pMem; //Resets the head to point to new data

		//If there was at least one other node in the list, this links its previous pointer to the new data.
		if(pList->pHead->pNext != NULL)
			pMem->pNext->pPrev = pList->pHead;
	}

	return success;
}

/****************************************************************
* Function: load()                                              *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Loads data from csv file                         *
* Input parameters: file as FILE & pList as list pointer        *
* Returns: Success as int                                       *
* Preconditions: file as FILE & pList as list pointer           *
* Postconditions: Data has been loaded into list.               *
*****************************************************************/
int load(FILE* file, List* pList) {
	char line[75] = "", temp2[75] = "";
	int success = 0, number = 0;
	Duration temp = { 0 , 0 };
	Record newNode = { "", "", "", "" , temp, 0, 0 };
	while (!feof(file)) {
		success = 1;
		
		fgets(line, 75, file); //Reads in one line from the file

		//Records artist
		strcpy(temp2, strtok(line, ","));
		if (temp2[0] == '"') { //Some names had just first while others had both first and last names
			strcat(temp2, ",");
			strcat(temp2, strtok(NULL, ","));
		}
		strcpy(newNode.artist, temp2);

		strcpy(newNode.album, strtok(NULL, ",")); //Records album
		strcpy(newNode.song, strtok(NULL, ",")); //Records song
		strcpy(newNode.genre, strtok(NULL, ",")); //Records genre

		//Records minutes
		strcpy(temp2, strtok(NULL, ":"));
		number = strtol(temp2, NULL, 10); //Converts string to number
		newNode.length.minutes = number;

		//Records seconds
		strcpy(temp2, strtok(NULL, ","));
		number = strtol(temp2, NULL, 10);
		newNode.length.seconds = number;

		//Records times played
		strcpy(temp2, strtok(NULL, ","));
		number = strtol(temp2, NULL, 10);
		newNode.timesPlayed = number;

		//Records rating
		strcpy(temp2, strtok(NULL, "\n"));
		number = strtol(temp2, NULL, 10);
		newNode.rating = number;

		insertFront(pList, &newNode); //Takes this record and inserts it in the list
	}

	return success;
}

/****************************************************************
* Function: store()                                             *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Stores list data into file temporarily           *
* Input parameters: file as FILE & pList as list pointer        *
* Returns: Success as int                                       *
* Preconditions: file as FILE & pList as list pointer           *
* Postconditions: List has been stored temporarily.             *
*****************************************************************/
int store(FILE* file, List* pList) {
	Node* pCur = pList->pHead; //Initialized to first element
	int success = 0;
	while (pCur != NULL) { //Runs until it reaches the end of the list
		success = 1;
		fprintf(file, "%s,%s,%s,%s,%d:", pCur->data.artist, pCur->data.album, pCur->data.song, pCur->data.genre, pCur->data.length.minutes);
		if (pCur->data.length.seconds < 10)
			fprintf(file, "0%d,", pCur->data.length.seconds);
		else
			fprintf(file, "%d,", pCur->data.length.seconds);
		fprintf(file, "%d,%d\n", pCur->data.timesPlayed, pCur->data.rating);
		pCur = pCur->pNext; //Advances to next element
	}
	putchar('\n');
	return success;
}

/****************************************************************
* Function: printList()                                         *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Displays all records to console.                 *
* Input parameters: pList as const List pointer.                *
* Returns: Nothing                                              *
* Preconditions: pList as const List pointer.                   *
* Postconditions: All records have been displayed to console    *
*****************************************************************/
void printList(const List* pList) {
	Node* pCur = pList->pHead;
	while (pCur != NULL) {
		printf("%s,%s,%s,%s,%d:", pCur->data.artist, pCur->data.album, pCur->data.song, pCur->data.genre, pCur->data.length.minutes);
		if (pCur->data.length.seconds < 10)
			printf("0%d,", pCur->data.length.seconds);
		else
			printf("%d,", pCur->data.length.seconds);
		printf("%d,%d\n", pCur->data.timesPlayed, pCur->data.rating);
		pCur = pCur->pNext;
	}
	putchar('\n');
}

/****************************************************************
* Function: displayByArtist()                                   *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Records by an artist are displayed.              *
* Input parameters: pList as const List pointer and string      *
* Returns: Nothing                                              *
* Preconditions: pList as const List pointer and string         *
* Postconditions: Records by an artist have been displayed.     *
*****************************************************************/
void displayByArtist(const List* pList, char* artist) {
	Node* pCur = pList->pHead;
	while (pCur != NULL) {
		if (strstr(pCur->data.artist, artist) != NULL) { //Checks if current element's artist matches with the requested artist.
			printf("%s,%s,%s,%s,%d:", pCur->data.artist, pCur->data.album, pCur->data.song, pCur->data.genre, pCur->data.length.minutes);
			if (pCur->data.length.seconds < 10)
				printf("0%d,", pCur->data.length.seconds);
			else
				printf("%d,", pCur->data.length.seconds);
			printf("%d,%d\n", pCur->data.timesPlayed, pCur->data.rating);
		}
		pCur = pCur->pNext;
	}
	putchar('\n');
}

/****************************************************************
* Function: insert()                                            *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Inserts a new record                             *
* Input parameters: pList as List pointer and pNewData as Record*
* Returns: Success as int                                       *
* Preconditions: pList as List pointer and pNewData as Record   *
* Postconditions: A new record has been inserted.               *
*****************************************************************/
int insert(List* pList, Record* const pNewData) {
	int success = 0;
	if (pNewData != NULL) { //This block executes if test case is provided.
		pNewData->length.minutes = pNewData->length.minutes >= 0 ? pNewData->length.minutes : 0;
		pNewData->length.seconds = pNewData->length.seconds >= 0 && pNewData->length.seconds < 60 ? pNewData->length.seconds : 0;
		pNewData->timesPlayed = pNewData->timesPlayed >= 0 ? pNewData->timesPlayed : 0;
		pNewData->rating = pNewData->rating >= 0 && pNewData->rating <= 5 ? pNewData->rating : 0;
		success = insertFront(pList, pNewData);
	}	
	else {
		int num = 0;
		Duration temp = { 0 , 0 };
		Record newNode = { "", "", "", "" , temp, 0, 0 };

		printf("Enter artist's name\n");
		gets(newNode.artist);
		newNode.artist[0] = toupper(newNode.artist[0]);

		printf("Enter album title\n");
		gets(newNode.album);

		printf("Enter song title\n");
		gets(newNode.song);

		printf("Enter genre\n");
		gets(newNode.genre);

		printf("Enter minutes\n");
		scanf("%d", &num);
		newNode.length.minutes = num >= 0 ? num : 0; //Verifies if provided number is valid before saving. If invalid, 0 is saved.

		printf("Enter seconds\n");
		scanf("%d", &num);
		newNode.length.seconds = num >= 0 && num < 60 ? num : 0;

		printf("Enter number of times played\n");
		scanf("%d", &num);
		newNode.timesPlayed = num >= 0 ? num : 0;

		printf("Enter rating\n");
		scanf("%d", &num);
		newNode.rating = num >= 0 && num <= 5 ? num : 0;

		success = insertFront(pList, &newNode);
	}
	
	return success;
}

/****************************************************************
* Function: delete()                                            *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Deletes a record based on the inputted song.     *
* Input parameters: pList as List pointer and string            *
* Returns: Success as int                                       *
* Preconditions: pList as List pointer and string               *
* Postconditions: A record has been deleted.                    *
*****************************************************************/
int delete(List* pList, char* song) {
	int success = 0;
	Node* pPrev = NULL, * pCur = pList->pHead;
	while (pCur != NULL && strcmp(pCur->data.song, song) != 0) { //Runs until song is found
		pPrev = pCur;
		pCur = pCur->pNext;
	}
	
	if (pCur != NULL) {
		success = 1; //Song is found
		if (pPrev != NULL) { //If null, song is at beginning
			if (pCur->pNext != NULL) { //If null, song is at end
				pCur->pNext->pPrev = pPrev;
				pPrev->pNext = pCur->pNext;
			}
			else 
				pPrev->pNext = NULL;	
		}
		else
			pList->pHead = pCur->pNext;
	
		free(pCur);
	}

	return success;
}

/****************************************************************
* Function: edit()                                              *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Edits a particular record.                       *
* Input parameters: pList as List pointer and string            *
* Returns: Success as int                                       *
* Preconditions: pList as List pointer and string               *
* Postconditions: A record has been modified.                   *
*****************************************************************/
int edit(List* pList, char* artist) {
	Node* pCur = pList->pHead;
	char string[100] = "";
	int success = 0, num = 0;

	while (pCur != NULL) {
		if (strstr(pCur->data.artist, artist) != NULL) {
			printf("Would you like to change this record? (Enter 1 for yes and 0 for no)\n%s,%s,%s,%s,%d:%d,%d,%d\n", pCur->data.artist, pCur->data.album, pCur->data.song, pCur->data.genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.timesPlayed, pCur->data.rating);
			scanf("%d", &num);

			if (num == 1) {
				scanf("%c", &string);
				printf("Change artist name (Enter '!' to skip)\n");
				gets(string);
				if (strcmp(string, "!") != 0) {
					string[0] = toupper(string[0]);
					strcpy(pCur->data.artist, string);
				}
					
				printf("Change album name (Enter '!' to skip)\n");
				gets(string);
				if (strcmp(string, "!") != 0)
					strcpy(pCur->data.album, string);

				printf("Change song name (Enter '!' to skip)\n");
				gets(string);
				if (strcmp(string, "!") != 0)
					strcpy(pCur->data.song, string);

				printf("Change genre (Enter '!' to skip)\n");
				gets(string);
				if (strcmp(string, "!") != 0)
					strcpy(pCur->data.genre, string);

				printf("Change number of minutes (Enter a negative number to skip)\n");
				scanf("%d", &num);
				if (num >= 0)
					pCur->data.length.minutes = num;

				printf("Change number of seconds (Enter an invalid seconds value to skip)\n");
				scanf("%d", &num);
				if (num >= 0 && num < 60)
					pCur->data.length.seconds = num;

				printf("Change number of times played (Enter a negative number to skip)\n");
				scanf("%d", &num);
				if (num >= 0)
					pCur->data.timesPlayed = num;

				printf("Change rating from 1 to 5 (Enter an invalid rating to skip)\n");
				scanf("%d", &num);
				if (num > 0 && num <= 5)
					pCur->data.rating = num;

				success = 1;
			}
		}
		pCur = pCur->pNext;
	}

	return success;
}

/****************************************************************
* Function: sort()                                              *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Sorts list based on method provided              *
* Input parameters: pList as List pointer and option as int     *
* Returns: Success as int                                       *
* Preconditions: pList as List pointer and option as int        *
* Postconditions: The list has been sorted                      *
*****************************************************************/
int sort(List* pList, int option) {
	int success = 0, size = 0, x = 1, temp = 0;
	Node* count = pList->pHead, *pCur = count, * pPrev = NULL;
	char temp2[50] = "";
	
	//Determines size of linked list
	while (count != NULL) {
		size++;
		count = count->pNext;
	}

	switch (option) {
	case 1:
		for (int passes = 1; x; passes++) {
			x = 0;
			for (int i = 0; i < size - passes; i++) {
				if (strcmp(pCur->data.artist, pCur->pNext->data.artist) > 0) { //If this executes, all data between nodes gets swapped. Sorts based on artist.
					strcpy(temp2, pCur->data.artist);
					strcpy(pCur->data.artist, pCur->pNext->data.artist);
					strcpy(pCur->pNext->data.artist, temp2);

					strcpy(temp2, pCur->data.album);
					strcpy(pCur->data.album, pCur->pNext->data.album);
					strcpy(pCur->pNext->data.album, temp2);

					strcpy(temp2, pCur->data.song);
					strcpy(pCur->data.song, pCur->pNext->data.song);
					strcpy(pCur->pNext->data.song, temp2);

					strcpy(temp2, pCur->data.genre);
					strcpy(pCur->data.genre, pCur->pNext->data.genre);
					strcpy(pCur->pNext->data.genre, temp2);

					temp = pCur->data.length.minutes;
					pCur->data.length.minutes = pCur->pNext->data.length.minutes;
					pCur->pNext->data.length.minutes = temp;

					temp = pCur->data.length.seconds;
					pCur->data.length.seconds = pCur->pNext->data.length.seconds;
					pCur->pNext->data.length.seconds = temp;

					temp = pCur->data.timesPlayed;
					pCur->data.timesPlayed = pCur->pNext->data.timesPlayed;
					pCur->pNext->data.timesPlayed = temp;

					temp = pCur->data.rating;
					pCur->data.rating = pCur->pNext->data.rating;
					pCur->pNext->data.rating = temp;
				}
				pPrev = pCur;
				pCur = pCur->pNext;
			}

			for (int i = 0; i < size - passes; i++) {
				x = 1; //This means there are more passes to do
				if(pCur->pPrev != NULL)
					pCur = pCur->pPrev;
			}
		}
		success = 1;
		break;
	case 2:
		for (int passes = 1; x; passes++) {
			x = 0;
			for (int i = 0; i < size - passes; i++) {
				if (strcmp(pCur->data.album, pCur->pNext->data.album) > 0) { //Sorts based on album.
					strcpy(temp2, pCur->data.artist);
					strcpy(pCur->data.artist, pCur->pNext->data.artist);
					strcpy(pCur->pNext->data.artist, temp2);

					strcpy(temp2, pCur->data.album);
					strcpy(pCur->data.album, pCur->pNext->data.album);
					strcpy(pCur->pNext->data.album, temp2);

					strcpy(temp2, pCur->data.song);
					strcpy(pCur->data.song, pCur->pNext->data.song);
					strcpy(pCur->pNext->data.song, temp2);

					strcpy(temp2, pCur->data.genre);
					strcpy(pCur->data.genre, pCur->pNext->data.genre);
					strcpy(pCur->pNext->data.genre, temp2);

					temp = pCur->data.length.minutes;
					pCur->data.length.minutes = pCur->pNext->data.length.minutes;
					pCur->pNext->data.length.minutes = temp;

					temp = pCur->data.length.seconds;
					pCur->data.length.seconds = pCur->pNext->data.length.seconds;
					pCur->pNext->data.length.seconds = temp;

					temp = pCur->data.timesPlayed;
					pCur->data.timesPlayed = pCur->pNext->data.timesPlayed;
					pCur->pNext->data.timesPlayed = temp;

					temp = pCur->data.rating;
					pCur->data.rating = pCur->pNext->data.rating;
					pCur->pNext->data.rating = temp;
				}
				pPrev = pCur;
				pCur = pCur->pNext;
			}

			for (int i = 0; i < size - passes; i++) {
				x = 1;
				if (pCur->pPrev != NULL)
					pCur = pCur->pPrev;
			}
		}
		success = 1;
		break;
	case 3:
		for (int passes = 1; x; passes++) {
			x = 0;
			for (int i = 0; i < size - passes; i++) {
				if (pCur->data.rating > pCur->pNext->data.rating) { //Sorts based on rating.
					strcpy(temp2, pCur->data.artist);
					strcpy(pCur->data.artist, pCur->pNext->data.artist);
					strcpy(pCur->pNext->data.artist, temp2);

					strcpy(temp2, pCur->data.album);
					strcpy(pCur->data.album, pCur->pNext->data.album);
					strcpy(pCur->pNext->data.album, temp2);

					strcpy(temp2, pCur->data.song);
					strcpy(pCur->data.song, pCur->pNext->data.song);
					strcpy(pCur->pNext->data.song, temp2);

					strcpy(temp2, pCur->data.genre);
					strcpy(pCur->data.genre, pCur->pNext->data.genre);
					strcpy(pCur->pNext->data.genre, temp2);

					temp = pCur->data.length.minutes;
					pCur->data.length.minutes = pCur->pNext->data.length.minutes;
					pCur->pNext->data.length.minutes = temp;

					temp = pCur->data.length.seconds;
					pCur->data.length.seconds = pCur->pNext->data.length.seconds;
					pCur->pNext->data.length.seconds = temp;

					temp = pCur->data.timesPlayed;
					pCur->data.timesPlayed = pCur->pNext->data.timesPlayed;
					pCur->pNext->data.timesPlayed = temp;

					temp = pCur->data.rating;
					pCur->data.rating = pCur->pNext->data.rating;
					pCur->pNext->data.rating = temp;
				}
				pPrev = pCur;
				pCur = pCur->pNext;
			}

			for (int i = 0; i < size - passes; i++) {
				x = 1;
				if (pCur->pPrev != NULL)
					pCur = pCur->pPrev;
			}
		}
		success = 1;
		break;
	case 4:
		for (int passes = 1; x; passes++) {
			x = 0;
			for (int i = 0; i < size - passes; i++) {
				if (pCur->data.timesPlayed < pCur->pNext->data.timesPlayed) { //Sorts based on times played.
					strcpy(temp2, pCur->data.artist);
					strcpy(pCur->data.artist, pCur->pNext->data.artist);
					strcpy(pCur->pNext->data.artist, temp2);

					strcpy(temp2, pCur->data.album);
					strcpy(pCur->data.album, pCur->pNext->data.album);
					strcpy(pCur->pNext->data.album, temp2);

					strcpy(temp2, pCur->data.song);
					strcpy(pCur->data.song, pCur->pNext->data.song);
					strcpy(pCur->pNext->data.song, temp2);

					strcpy(temp2, pCur->data.genre);
					strcpy(pCur->data.genre, pCur->pNext->data.genre);
					strcpy(pCur->pNext->data.genre, temp2);

					temp = pCur->data.length.minutes;
					pCur->data.length.minutes = pCur->pNext->data.length.minutes;
					pCur->pNext->data.length.minutes = temp;

					temp = pCur->data.length.seconds;
					pCur->data.length.seconds = pCur->pNext->data.length.seconds;
					pCur->pNext->data.length.seconds = temp;

					temp = pCur->data.timesPlayed;
					pCur->data.timesPlayed = pCur->pNext->data.timesPlayed;
					pCur->pNext->data.timesPlayed = temp;

					temp = pCur->data.rating;
					pCur->data.rating = pCur->pNext->data.rating;
					pCur->pNext->data.rating = temp;
				}
				pPrev = pCur;
				pCur = pCur->pNext;
			}

			for (int i = 0; i < size - passes; i++) {
				x = 1;
				if (pCur->pPrev != NULL)
					pCur = pCur->pPrev;
			}
		}
		success = 1;
		break;
	default:
		puts("\nInvalid input!");
		break;
	}

	return success;
}

/****************************************************************
* Function: rate()                                              *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Changes rating of a song.                        *
* Input parameters: pList as list pointer, string, and int      *
* Returns: Success as int                                       *
* Preconditions: pList as list pointer, string, and int         *
* Postconditions: The rating of a song has been modified.       *
*****************************************************************/
int rate(List* pList, char* song, int rating) {
	int success = 0;
	if (rating > 0 && rating <= 5) {
		Node* pCur = pList->pHead;
		while (pCur != NULL) {
			if (strcmp(pCur->data.song, song) == 0) {
				success = 1;
				pCur->data.rating = rating;
			}
			pCur = pCur->pNext;
		}
	}

	return success;
}

/****************************************************************
* Function: play()                                              *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Displays info about a song and goes to next.     *
* Input parameters: pList as List pointer and string            *
* Returns: Nothing                                              *
* Preconditions: pList as List pointer and string               *
* Postconditions: The songs have been played.                   *
*****************************************************************/
void play(List* pList, char* song) {
	Node* pCur = pList->pHead;
	while(pCur != NULL && strcmp(pCur->data.song, song) != 0) //This is so it starts playing at the requested song, not at the beginning
		pCur = pCur->pNext;

	while (pCur != NULL) {
		system("cls");
		printf("Artist: %s\n", pCur->data.artist);
		printf("Album: %s\n", pCur->data.album);
		printf("Song: %s\n", pCur->data.song);
		printf("Genre: %s\n", pCur->data.genre);
		printf("Length: %d minutes and %d seconds\n", pCur->data.length.minutes, pCur->data.length.seconds);
		pCur->data.timesPlayed++;
		printf("Times Played: %d\n", pCur->data.timesPlayed);
		printf("Rating: %d\n", pCur->data.rating);
		delay(3000);
		pCur = pCur->pNext;
	}

	system("cls");
}

/****************************************************************
* Function: shuffle()                                           *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Plays songs in random order                      *
* Input parameters: pList as List pointer and order as int array*
* Returns: Nothing                                              *
* Preconditions: pList as List pointer and order as int array   *
* Postconditions: Songs have been played randomly.              *
*****************************************************************/
void shuffle(List* pList, int* order) {
	if (order != NULL) { //This block executes if test case is provided.
		int size = 0, x = 0;
		Node* count = pList->pHead, * pCur = pList->pHead;

		while (count != NULL) {
			size++;
			count = count->pNext;
		}
		
		for (int i = 0; i < size; i++) {
			if (i == 0) {
				for (int j = 1; j < order[i]; j++)
					pCur = pCur->pNext;

				printf("Artist: %s\n", pCur->data.artist);
				printf("Album: %s\n", pCur->data.album);
				printf("Song: %s\n", pCur->data.song);
				printf("Genre: %s\n", pCur->data.genre);
				printf("Length: %d minutes and %d seconds\n", pCur->data.length.minutes, pCur->data.length.seconds);
				pCur->data.timesPlayed++;
				printf("Times Played: %d\n", pCur->data.timesPlayed);
				printf("Rating: %d\n", pCur->data.rating);
				putchar('\n');
			}
			else {
				if (order[i] - order[i - 1] > 0) {
					for (int j = 1; j <= order[i] - order[i - 1]; j++)
						pCur = pCur->pNext;

					printf("Artist: %s\n", pCur->data.artist);
					printf("Album: %s\n", pCur->data.album);
					printf("Song: %s\n", pCur->data.song);
					printf("Genre: %s\n", pCur->data.genre);
					printf("Length: %d minutes and %d seconds\n", pCur->data.length.minutes, pCur->data.length.seconds);
					pCur->data.timesPlayed++;
					printf("Times Played: %d\n", pCur->data.timesPlayed);
					printf("Rating: %d\n", pCur->data.rating);
					putchar('\n');
				}
				else {
					for (int j = 1; j <= abs(order[i] - order[i - 1]); j++)
						pCur = pCur->pPrev;

					printf("Artist: %s\n", pCur->data.artist);
					printf("Album: %s\n", pCur->data.album);
					printf("Song: %s\n", pCur->data.song);
					printf("Genre: %s\n", pCur->data.genre);
					printf("Length: %d minutes and %d seconds\n", pCur->data.length.minutes, pCur->data.length.seconds);
					pCur->data.timesPlayed++;
					printf("Times Played: %d\n", pCur->data.timesPlayed);
					printf("Rating: %d\n", pCur->data.rating);
					putchar('\n');
				}
			}
		}
	}
	else {
		int size = 0, x = 0;
		Node* count = pList->pHead, * pCur = pList->pHead;

		while (count != NULL) {
			size++;
			count = count->pNext;
		}

		//Generates distinct random numbers for dynamic array.
		int* arr = (int*)malloc(size * sizeof(int));
		for (int i = 0; i < size; i++) {
			x = 0;
			int num = rand() % size + 1;
			for (int j = 0; j < size; j++) {
				if (num == arr[j]) {
					x = 1;
					break;
				}
			}
			if (x)
				i--;
			else
				arr[i] = num;
		}

		for (int i = 0; i < size; i++) {
			if (i == 0) {
				for (int j = 1; j < arr[i]; j++)
					pCur = pCur->pNext;

				system("cls");
				printf("Artist: %s\n", pCur->data.artist);
				printf("Album: %s\n", pCur->data.album);
				printf("Song: %s\n", pCur->data.song);
				printf("Genre: %s\n", pCur->data.genre);
				printf("Length: %d minutes and %d seconds\n", pCur->data.length.minutes, pCur->data.length.seconds);
				pCur->data.timesPlayed++;
				printf("Times Played: %d\n", pCur->data.timesPlayed);
				printf("Rating: %d\n", pCur->data.rating);
				delay(3000);
			}
			else {
				if (arr[i] - arr[i - 1] > 0) {
					for (int j = 1; j <= arr[i] - arr[i - 1]; j++)
						pCur = pCur->pNext;

					system("cls");
					printf("Artist: %s\n", pCur->data.artist);
					printf("Album: %s\n", pCur->data.album);
					printf("Song: %s\n", pCur->data.song);
					printf("Genre: %s\n", pCur->data.genre);
					printf("Length: %d minutes and %d seconds\n", pCur->data.length.minutes, pCur->data.length.seconds);
					pCur->data.timesPlayed++;
					printf("Times Played: %d\n", pCur->data.timesPlayed);
					printf("Rating: %d\n", pCur->data.rating);
					delay(3000);
				}
				else {
					for (int j = 1; j <= abs(arr[i] - arr[i - 1]); j++)
						pCur = pCur->pPrev;

					system("cls");
					printf("Artist: %s\n", pCur->data.artist);
					printf("Album: %s\n", pCur->data.album);
					printf("Song: %s\n", pCur->data.song);
					printf("Genre: %s\n", pCur->data.genre);
					printf("Length: %d minutes and %d seconds\n", pCur->data.length.minutes, pCur->data.length.seconds);
					pCur->data.timesPlayed++;
					printf("Times Played: %d\n", pCur->data.timesPlayed);
					printf("Rating: %d\n", pCur->data.rating);
					delay(3000);
				}
			}
		}
		free(arr);
		system("cls");
	}
}

/****************************************************************
* Function: Exit()                                              *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Exits program by storing all data.               *
* Input parameters: file as FILE & pList as list pointer        *
* Returns: Nothing                                              *
* Preconditions: file as FILE & pList as list pointer           *
* Postconditions: Data has been stored.                         *
*****************************************************************/
void Exit(FILE* file, List* pList) {
	store(file, pList);
}

/****************************************************************
* Function: delay()                                             *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: pauses the program for some miliseconds.         *
* Input parameters: miliseconds as int                          *
* Returns: Nothing                                              *
* Preconditions: miliseconds as int                             *
* Postconditions: the program has been delayed for some time    *
*****************************************************************/
void delay(int x) {
	//I found this delay function on stack overflow
	clock_t time = clock();
	while (clock() < time + x)
		;
}