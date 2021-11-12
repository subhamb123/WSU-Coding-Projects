/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 223                                                       *
* Programming Assignment: PA 1 - Learning Linux Commands Matching Game  *
*                                and C++ Review                         *
* Date: 8/30/2021                                                       *
* Description: This program is a matching game to learn Linux commands. *
************************************************************************/

/*
 * ADVANTAGES/DISADVANTAGES LINKED LIST: An advantage is the list can store "unlimited" commands. A disadvantage is remembering to include all the functions that make up a linked list, especially the syntax when templates are used.
 * ADVANTAGES/DISADVANTAGES ARRAY: An advantage is when a profile is found when loading a previous game, its index is stored so no time is wasted when finding it to modify its score after a game. A disadvantage is arrays aren't really resizable, so the program can only hold up to 50 profiles.
*/

#include "header.h"

int main() {
    srand(time(nullptr)); //Initialize random

    int option = 0, score = 0, questions = 0, i = 50, random = 0, random2 = 0, random3 = 0, answer = 0, userAnswer = 0, match = 0, elements = 0;
    string name = "", sc = "", command = "", description = "", garbage = "", currentC = "", currentD = "", randomD = "", randomD2 = "";
    bool indicator = false;
    Profile profiles[50];
    List<string, string> l;

    fstream file;
    file.open("commands.csv", ios::in); //Open in read mode

    while (!file.eof()) {
        getline(file, command, ','); //Grab the important info
        getline(file, garbage, '\"');
        getline(file, description, '\"');
        getline(file, garbage, '\n');
        l.insertFront(command, description);
    }

    file.close();
    file.open("profiles.csv", ios::in);

    while (!file.eof() && i != 0) {
        //Shift all indices 1 to the right
        for (int j = 50 - i; j > 0; j--) {
            profiles[j].setName(profiles[j - 1].getName());
            profiles[j].setPoints(profiles[j - 1].getPoints());
        }

        getline(file, name, ',');
        getline(file, sc, '\n');
        score = stoi(sc, nullptr, 10); //String to int
        profiles[0].setName(name);
        profiles[0].setPoints(score);

        i--; //Saves time by checking occupied indices only
    }

    file.close();

    Node<string, string>* pCur = l.getRoot(); //Pointer to traverse through the list

    while (option != 6) {
        system("clear");
        cout << "Linux Commands Matching Game Menu\n---------------------------------" << endl;
        cout << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n5. Remove Command\n6. Exit\n" << endl;

        cin >> option;

        switch (option) {
            case 1:
                cout << endl << "Rules\n-----\n1. Create new profile and play game by using option 2 or load an existing \nprofile by using option 3.\n2. In the game, you'll be asked what the command does from the three options. \nCorrect: +1 point; Incorrect: -1 point.\n3. You can add a command using option 4.\n4. You can delete an existing command using option 5.\n5. Exit the game using option 6.\n" << endl << "Press enter to continue..." << endl;
                cin.get(); //Capture enter
                cin.get();
                break;
            case 2: {
                redo:
                cout << "Your name: ";
                cin >> name;

                for (int j = 0; j < name.length(); j++)
                    name[j] = tolower(name[j]); //Makes name lowercase

                //Checks for redundant names
                for (int j = 0; j < 50 - i; j++) {
                    if (profiles[j].getName() == name) {
                        cout << "Profile already exists!" << endl;
                        goto redo;
                    }
                }

                score = 0;

                play:
                pCur = l.getRoot();
                elements = 0;

                while (pCur != nullptr) {
                    elements++;
                    pCur = pCur->getNext();
                }

                int *hashTable = new int[elements]{0}; //Hashtable keeps track which answers have been used already

                questions = 0;

                while (questions < 5 || questions > elements) {
                    cout << endl << "Number of questions (5 - " << elements << "): ";
                    cin >> questions;
                }

                system("clear");

                for (int j = 0; j < questions; j++) {
                    userAnswer = 0;
                    pCur = l.getRoot();

                    //Ensures unique question
                    do
                        random = rand() % elements;
                    while (hashTable[random] != 0);

                    hashTable[random]++;

                    //Traverses to the picked node
                    for (int k = 0; k < random; k++)
                        pCur = pCur->getNext();

                    currentC = pCur->getCommand();
                    currentD = pCur->getDescription();

                    //Picks 2 other random answers
                    do
                        random2 = rand() % elements;
                    while (random == random2);

                    do
                        random3 = rand() % elements;
                    while (random == random3 || random2 == random3);

                    pCur = l.getRoot();

                    for (int k = 0; k < random2; k++)
                        pCur = pCur->getNext();

                    randomD = pCur->getDescription();

                    pCur = l.getRoot();

                    for (int k = 0; k < random3; k++)
                        pCur = pCur->getNext();

                    randomD2 = pCur->getDescription();

                    cout << currentC << endl << endl;

                    //Picks random listing order
                    random = rand() % 3;
                    do
                        random2 = rand() % 3;
                    while (random == random2);

                    if (random == 0 && random2 == 1) {
                        answer = 1;
                        cout << "1. " << currentD << endl << "2. " << randomD << endl << "3. " << randomD2 << endl
                             << endl;
                    }
                    if (random == 0 && random2 == 2) {
                        answer = 1;
                        cout << "1. " << currentD << endl << "2. " << randomD2 << endl << "3. " << randomD << endl
                             << endl;
                    }
                    if (random == 1 && random2 == 0) {
                        answer = 2;
                        cout << "1. " << randomD << endl << "2. " << currentD << endl << "3. " << randomD2 << endl
                             << endl;
                    }
                    if (random == 1 && random2 == 2) {
                        answer = 3;
                        cout << "1. " << randomD << endl << "2. " << randomD2 << endl << "3. " << currentD << endl
                             << endl;
                    }
                    if (random == 2 && random2 == 0) {
                        answer = 2;
                        cout << "1. " << randomD2 << endl << "2. " << currentD << endl << "3. " << randomD << endl
                             << endl;
                    }
                    if (random == 2 && random2 == 1) {
                        answer = 3;
                        cout << "1. " << randomD2 << endl << "2. " << randomD << endl << "3. " << currentD << endl
                             << endl;
                    }

                    while (userAnswer < 1 || userAnswer > 3) {
                        cout << "Your answer (1 - 3): ";
                        cin >> userAnswer;
                    }

                    if (answer == userAnswer) {
                        score++;
                        cout << endl << "Correct! " << currentC << " - " << currentD
                             << ". You have been awarded 1 point. Your point total is " << score << endl << endl;
                    } else {
                        score--;
                        cout << endl << "Incorrect! " << currentC << " - " << currentD
                             << ". You have lost 1 point. Your point total is " << score << endl << endl;
                    }
                }

                cout << "Press enter to continue..." << endl;
                cin.get();
                cin.get();

                if (indicator) //Changes score of an existing profile
                    profiles[match].setPoints(score);
                else { //Creates new profile
                    profiles[50 - i].setName(name);
                    profiles[50 - i].setPoints(score);
                    i--;
                }

                delete[] hashTable; //Deallocates array from heap
                indicator = false;
                break;
            }
            case 3:
                cout << "Profile name: ";
                cin >> name;
                for(int j = 0; j < name.length(); j++)
                    name[j] = tolower(name[j]);

                for (int j = 0; j < 50 - i; j++) {
                    if (profiles[j].getName() == name) {
                        match = j;
                        score = profiles[j].getPoints();
                        cout << "Score: " << score << endl;
                        indicator = true;
                        goto play; //Goes to a specific part of option 2 so that it doesn't ask for the name again and starts playing
                    }
                }

                cout << "Name not found" << endl << endl;

                cout << "Press enter to continue..." << endl;
                cin.get();
                cin.get();

                break;
            case 4:
            restart:
                pCur = l.getRoot();
                cout << "Enter new command (enter 'q' to quit): ";
                cin >> command;

                if (command == "q")
                    break;

                while (pCur != nullptr) {
                    if (pCur->getCommand() == command)
                        goto restart; //If command is redundant

                    pCur = pCur->getNext();
                }

                cout << "Enter its description: ";
                getline(cin >> ws, description); //Allows multiple words

                l.insertFront(command, description);

                cout << "Press enter to continue..." << endl;
                cin.get();

                break;
            case 5:
            restart2:
                pCur = l.getRoot();
                cout << "Enter command to delete (enter 'q' to quit): ";
                cin >> command;

                if (command == "q") {
                    cout << endl;
                    break;
                }

                while (pCur != nullptr) {
                    if (pCur->getCommand() == command)
                        goto onward; //If command exists

                    pCur = pCur->getNext();
                }

                goto restart2; //If command doesn't exist

            onward:
                l.delNode(command);

                cout << "Press enter to continue..." << endl;
                cin.get();
                cin.get();

                break;

            case 6:
                file.open("commands.csv", ios::out);
                pCur = l.getRoot();

                while(pCur != nullptr){
                    file << pCur->getCommand() << ", \"" << pCur->getDescription() << "\"";
                    if(pCur->getNext() != nullptr)
                        file << endl;
                    pCur = pCur->getNext();
                }

                file.close();
                file.open("profiles.csv", ios::out);

                for(int j = 0; j < 50 - i; j++) {
                    file << profiles[j].getName() << ", " << profiles[j].getPoints();

                    if(i + j != 49)
                        file << endl; //Ensures no newline at end of file
                }

                file.close();

                l.delList(l.getRoot()); //Deletes the list

                break;
            default:
                break;
        }
    }

    return 0;
}