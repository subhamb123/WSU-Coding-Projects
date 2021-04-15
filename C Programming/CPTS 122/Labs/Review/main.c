#include "parent.h"

int main() {
	printf("1. Hello World, I am in CptS 122!\n");

	char str[] = "Behera, Subham";
	printf("2a. %s\n", str_rev_rec(str, strlen(str)));

	char str2[100] = "Behera,, Subham, John", str3[100] = "yellow|blue";

	strcpy(str2, myStrTok(str2, ','));
	printf("2b. %s\n", str2);
	strcpy(str2, myStrTok(NULL, ','));
	printf("%s\n", str2);
	strcpy(str2, myStrTok(NULL, '\0'));
	printf("%s\n", str2);
	strcpy(str2, myStrTok(NULL, '\t'));
	printf("%s\n", str2);
	strcpy(str3, myStrTok(str3, '|'));
	printf("%s\n", str3);
	strcpy(str3, myStrTok(NULL, '\0'));
	printf("%s\n", str3);
	strcpy(str3, myStrTok(NULL, '\t'));
	printf("%s\n", str3);

	printf("2d.\n");
	FILE* infile = fopen("characters.txt", "r");
	int i = 1, alphaNum[26] = { 0 };
	char c = '\0';
	while (!feof(infile)) {
		fscanf(infile, "%c", &c);
		if (c == '\n')
			i++;
		else {
			printf("Line %d: %c\n", i, c);
			c = tolower(c);
			alphaNum[c - 97]++;
		}
	}

	printf("------------\n");
	for (int i = 97; i < 123; i++)
		printf("%c: %d\n", i, alphaNum[i-97]);
	
	return 0;
}