#include "parent.h"

int main() {
	char str1[] = "CptS 121 is cool!", str2[] = "CptS 121 is cool!";
	printf("%s\n", string_reverse(str1));
	printf("%s\n", string_reverse(str2));

	char src[] = "strcpy", dest[100] = "";
	printf("2a. %s\n", my_strcpy(dest, src));
	printf("2b. %s\n", my_strcat(dest, src));
	
	char str3[] = "chOcoLaTE", str4[] = "chocoLATE";
	printf("2c. %d\n", my_strcmp(str3, str4));

	printf("2d. %d\n", my_strlen(str3));

	return 0;
}