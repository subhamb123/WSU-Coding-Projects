#include "parent.h"

char* str_rev_rec(char* str, int n) {
	if (n > 1) {
		char temp = *str;
		*str = *(str + n - 1);
		*(str + n - 1) = temp;
		str_rev_rec(str + 1, n - 2);
	}

	return str;
}

char* myStrTok(char* str, const char delim) {
	int i = 0;
	static int j = 0;
	static char dup[50];
	char token[25];
	if (str != NULL) {
		strcpy(dup, str);
		j = 0;
	}

	for (i = 0; i < strlen(dup) && dup[i+j] != delim; i++)
		;

	if (i == strlen(dup))
		return "";
	
	strncpy(token, dup + j, i);
	token[i] = '\0';
	j += i + 1;

	return token;
}