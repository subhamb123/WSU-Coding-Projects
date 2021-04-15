/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 6 - Morse Code Lookup BST                  *
* Date: 3/19/2021                                                       *
* Description: This program translates character to morse code using BST*
************************************************************************/

#include "header.hpp"
#include "BST.hpp"

int main() {
	char c = '\0';
	BST<char, string> tree; //Initialization of BST
	tree.print(); //Prints tree using inorder traversal so nodes are printed from lowest to highest based on ascii value.

	fstream infile;
	infile.open("Convert.txt", ios::in);

	cout << endl << "This is a test of the cpts 122" << endl << "Morse code conversion tool." << endl;

	//Runs until above sample is translated
	while (c != '.') {
		infile >> c;
		c = toupper(c);
		cout << tree.search(c) << " "; //Searches for translation and prints morse code for the character
	}

	cout << endl << endl << "Other characters that can be found in Convert.txt" << endl;

	//Translates other random characters
	while (!infile.eof()) {
		infile >> c;
		c = toupper(c);
		cout << tree.search(c) << " ";
	}

	cout << endl << endl;

	infile.close();

	return 0;
}