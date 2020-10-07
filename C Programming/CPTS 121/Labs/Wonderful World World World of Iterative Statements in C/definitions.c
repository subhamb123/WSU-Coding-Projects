#include "parent.h"

int greatest_common_divisor(int num1, int num2) {

}

int read_data(FILE* infile) {
	int data = 0;
	fscanf(infile, "%d", &data);
	return data;
}

void print(FILE* outfile, int num) {
	fprintf(outfile, "%d", num);
}