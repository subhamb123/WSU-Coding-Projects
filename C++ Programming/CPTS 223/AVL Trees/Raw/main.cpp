/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 223                                                       *
* Programming Assignment: PA 2 - AVL Trees                              *
* Date: 11/01/2021                                                      *
* Description: This program designs an AVL tree                         *
************************************************************************/

#include "AVLTree.h"

int main() {
    srand(time(nullptr)); //Initializes random

    AVLTree<int> ascendingT, descendingT, randomT;
    int ascending[50] = {0}, descending[50] = {0}, random[50] = {0}, hashTable[50] = {0}, number = 0;

    for(int i = 0; i < 50; i++) {
        ascending[i] = 2 * i + 1; //Definition of odd
        descending[i] = 2 * i + 1;
    }

    for(int i = 0; i < 25; i++){
        //Reverse the order by swapping
        int temp = descending[i];
        descending[i] = descending[49-i];
        descending[49-i] = temp;
    }

    for(int i = 0; i < 50; i++) {
        //Picks unique random number
        do
            number = rand() % 50;
        while(hashTable[number] != 0);

        hashTable[number]++; //Ensures same number isn't picked again
        random[i] = 2 * number + 1;
    }

    //Inserts data into AVL trees
    for(int i = 0; i < 50; i++) {
        ascendingT.insert(ascending[i], ascendingT.pRoot);
        descendingT.insert(descending[i], descendingT.pRoot);
        randomT.insert(random[i], randomT.pRoot);
    }

    //Prints height of each tree
    cout << "Height of ascending tree: " << ascendingT.getHeight(ascendingT.pRoot) << endl;
    cout << "Height of descending tree: " << descendingT.getHeight(descendingT.pRoot) << endl;
    cout << "Height of random tree: " << randomT.getHeight(randomT.pRoot) << endl << endl;

    //Prints if trees are valid
    cout << "Ascending tree is valid: " << (ascendingT.validate(ascendingT.pRoot) ? "True" : "False") << endl;
    cout << "Descending tree is valid: " << (descendingT.validate(descendingT.pRoot) ? "True" : "False") << endl;
    cout << "Random tree is valid: " << (randomT.validate(randomT.pRoot) ? "True" : "False") << endl << endl;

    //Prints a table from 1-100 indicating which numbers are in the trees
    cout << "'X' indicates contains() returned 1" << endl;
    cout << "Number   Ascending   Descending   Random" << endl;
    for(int i = 1; i <= 100; i++)
        cout << " " << (i < 100 ? (i < 10 ? "000" : "00") : "0") << i << (ascendingT.contains(i) ? "        X" : "         ") << (descendingT.contains(i) ? "           X" : "            ") << (randomT.contains(i) ? "          X" : "           ") << endl;

    return 0;
}