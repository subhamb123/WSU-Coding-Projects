#include "Parent.h"

int main() {
	FILE* infile = fopen("numbers.dat", "r");
	int sum = 0, temp = 0, flip = 1;
	while (!feof(infile)) {
		fscanf(infile, "%d", &temp);
		sum += temp;
	}
	for (int i = 2; i < sum; i++) {
		if (sum % i == 0){
			printf("1a. %d is not prime.\n", sum);
			flip = 0;
			break;
		}
	}
	if(flip)
		printf("1a. %d is prime.\n", sum);

	flip = 1;
	int digit = 0, digitSum = 0;
	while (sum != 0) {
		digit = sum % 10;
		digitSum += digit;
		sum /= 10;
	}
	for (int i = 2; i < digitSum; i++) {
		if (digitSum % i == 0) {
			printf("1b. %d is not prime.\n", digitSum);
			flip = 0;
			break;
		}
	}
	if (flip)
		printf("1b. %d is prime.\n", digitSum);

	int n = 0, product = 1;
	printf("2. ");
	while (!(n < 0)) {
		printf("Enter a positive number to see factorial. Enter a negative to quit.\n");
		scanf("%d", &n);
		if(n == 0 || n == 1)
			printf("%d! = %d\n", n, product);

		else if (!(n < 0)) {
			for (int i = 2; i <= n; i++)
				product *= i;
			printf("%d! = %d\n", n, product);
		}
		product = 1;
	}

	int num = 0, next = 0, term1 = 0, term2 = 1;
	printf("3. Enter an element\n");
	scanf("%d", &num);
	for (int i = 1; i <= num; ++i) {
		if (i == num)
			break;
		next = term1 + term2;
		term1 = term2;
		term2 = next;
	}

	printf("The fibonacci number for element %d of the series is %d.\n", num, term1);
	return 0;
}