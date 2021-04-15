/*************************************************************************************
* Programmer: Subham Behera                                                          *
* Class: CptS 122; Lab Section 13                                                    *
* Programming Assignment: PA 3 - Digital Music Manager & Doubly Linked Lists – Part 2*
* Date: 2/14/2021                                                                    *
* Description: This program manages music data with linked lists.                    *
**************************************************************************************/

#include "test.h"

/****************************************************************
* Function: testInsert()                                        *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Tests insert function                            *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: The insert function has been tested.          *
*****************************************************************/
void testInsert() {
	puts("Insert test\n");
	List list = { NULL };

	//Makes new test case
	Duration temp = { 4 , 36 };
	Record newNode = { "\"Perry, Katy\"", "Witness", "Chained to the Rhythm", "pop", temp, -1, 6 };

	puts("Test case:");
	printf("Artist: %s\n", newNode.artist);
	printf("Album: %s\n", newNode.album);
	printf("Song: %s\n", newNode.song);
	printf("Genre: %s\n", newNode.genre);
	printf("Length: %d minutes and %d seconds\n", newNode.length.minutes, newNode.length.seconds);
	printf("Times Played: %d\n", newNode.timesPlayed);
	printf("Rating: %d\n", newNode.rating);
	printf("\nSuccess: %d\n\n", insert(&list, &newNode));

	printList(&list);
}

/****************************************************************
* Function: testDelete()                                        *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Tests delete function                            *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: The delete function has been tested.          *
*****************************************************************/
void testDelete() {
	puts("Delete test\n");
	List list = { NULL };
	Duration temp = { 4 , 36 };
	Record newNode = { "\"Perry, Katy\"", "Witness", "Chained to the Rhythm", "pop", temp, 3, 5 };
	insert(&list, &newNode);

	puts("Test case: delete song \"Chained to the Rhythm\"");
	delete(&list, "Chained to the Rhythm");
	printf("Success: %d because head pointer is null\n\n", list.pHead == NULL ? 1 : 0);
}

/****************************************************************
* Function: testShuffle()                                       *
* Date Created: 2/3/2021                                        *
* Date Last Modified: 2/3/2021                                  *
* Description: Tests shuffle function                           *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: The shuffle function has been tested.         *
*****************************************************************/
void testShuffle() {
	puts("Shuffle test\n");
	int order[3] = { 3, 1, 2 };
	List list = { NULL };
	Duration temp = { -2 , 3 };

	//Third node
	Record newNode = { "\"Perry, Katy\"", "Witness", "Chained to the Rhythm", "pop", temp, -123, 1000 };
	insert(&list, &newNode);

	//Second node
	newNode.length.minutes = 200;
	newNode.length.seconds = 61;
	newNode.timesPlayed = 3;
	newNode.rating = -1;
	strcpy(newNode.artist, "\"Perri, Christina\"");
	strcpy(newNode.album, "HEAD OF HEART");
	strcpy(newNode.song, "Trust");
	strcpy(newNode.genre, "Pop");
	insert(&list, &newNode);

	//First node
	newNode.length.minutes = 4;
	newNode.length.seconds = 11;
	newNode.timesPlayed = 24;
	newNode.rating = 4;
	strcpy(newNode.artist, "Adele");
	strcpy(newNode.album, "25");
	strcpy(newNode.song, "Remedy");
	strcpy(newNode.genre, "Pop");
	insert(&list, &newNode);

	shuffle(&list, order);
}