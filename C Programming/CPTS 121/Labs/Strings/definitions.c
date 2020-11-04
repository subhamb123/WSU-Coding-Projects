#include "parent.h"

char* string_reverse(char* str) {
	static int x = 0;
	if (x == 0) {
		printf("1a. Using arrays: ");
		int size = 0;
		for (size; str[size] != '\0'; size++)
			;
		for (int i = 0; i < size / 2; i++) {
			char temp = str[i];
			str[i] = str[size - i - 1];
			str[size - i - 1] = temp;
		}
		x++;
		return str;
	}
	else {
		printf("1b. Using pointers: ");
		int size = 0;
		for (size; str[size] != '\0'; size++)
			;
		for (int i = 0; i < size / 2; i++) {
			char temp = *(str + i);
			*(str + i) = *(str+size-i-1);
			*(str + size - i - 1) = temp;
		}

		return str;
	}
}

char* my_strcpy(char* destination, const char* source) {
	int i = 0;
	for (i; *(source + i) != '\0'; i++) 
		*(destination + i) = *(source + i);
	
	*(destination + i) = '\0';
	return destination;
}

char* my_strcat(char* destination, const char* source) {
	int i = 0;
	for (i; destination[i] != '\0'; i++) 
		;
	for (int j = 0; source[j] != '\0'; i++, j++) 
		destination[i] = source[j];
	
	return destination;
}

int my_strcmp(const char* s1, const char* s2) {
	int i = 0, j = 0;
	for (i; s1[i] != '\0'; i++)
		;
	for (j; s2[j] != '\0'; j++)
		;
	if (i > j) {
		for (int k = 0; k < j; k++) {
			if (s1[k] < s2[k])
				return -1;
			if (s1[k] > s2[k])
				return 1;
		}
		return 1;
	}
	else {
		for (int k = 0; k < i; k++) {
			if (s1[k] < s2[k])
				return -1;
			if (s1[k] > s2[k])
				return 1;
		}
		if (i < j)
			return -1;
	}

	return 0;
}

int my_strlen(const char* s) {
	int i = 0;
	for (i; s[i] != '\0'; i++)
		;
	return i;
}