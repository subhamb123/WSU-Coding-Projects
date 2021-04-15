#include "Node.h"
#include "BST.h"

int main() {
	BST tree;
	string arr[4] = { "" };
	fstream infile;
	infile.open("names.txt", ios::in);

	for (int i = 0; !infile.eof(); i++)
		getline(infile, arr[i]);
	for (int i = 0; i < 4; i++)
		tree.insertNode(arr[i]);

	cout << tree;
	return 0;
}