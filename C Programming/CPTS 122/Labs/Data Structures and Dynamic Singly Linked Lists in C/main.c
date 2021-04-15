#include "parent.h"

int main() {
	FILE* infile = fopen("import.txt", "r"), * outfile = fopen("export.txt", "w");
	Node* list = (Node*)malloc(sizeof(Node));
	list->pNext = NULL;
	Contact newData = { "", "", "", "" };
	int option = 0;

	while (option != 7) {
		printf("Choose from the menu below\n1. Add\n2. Remove\n3. Edit\n4. Print\n5. Store\n6. Load\n7. Exit\n\n");
		scanf("%d", &option);
		switch (option) {
		case 1:
			printf("Enter a name\n");
			scanf("%s", &newData.name);
			printf("Enter a phone number\n");
			scanf("%s", &newData.phone);
			printf("Enter an email address\n");
			scanf("%s", &newData.email);
			printf("Enter a title\n");
			scanf("%s", &newData.title);

			printf("Success: %d\n", insertContactInOrder(&list, newData));
			break;
		case 2:
			printf("Enter a name\n");
			scanf("%s", &newData.name);

			printf("Success: %d\n", deleteContact(&list, newData));
			break;
		case 3:
			printf("Enter a name\n");
			scanf("%s", &newData.name);

			printf("Success: %d\n", editContact(list, newData));
			break;
		case 4:
			printList(list);
			break;
		case 5:
			printf("Success: %d\n", storeContacts(outfile, list));
			break;
		case 6:
			printf("Success: %d\n", loadContacts(infile, &list));
			break;
		default:
			break;
		}

	}
	return 0;
}