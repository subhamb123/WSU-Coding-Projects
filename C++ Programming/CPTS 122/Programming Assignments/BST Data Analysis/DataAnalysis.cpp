/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 8 - Data Analysis using Binary Search Trees*
* Date: 4/10/2021                                                       *
* Description: This program simulates product ownership using BST       *
************************************************************************/

#include "DataAnalysis.hpp"

/****************************************************************
* Class Function: runAnalysis()                                 *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Runs the program                                 *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: The program has been executed                 *
*****************************************************************/
void DataAnalysis::runAnalysis() {
	openFile();
	importFile();
	display();
	mCsvStream.close();
}

/****************************************************************
* Class Function: openFile()                                    *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Opens data.csv                                   *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: The data file has been opened                 *
*****************************************************************/
void DataAnalysis::openFile() {
	mCsvStream.open("data.csv");
}

/****************************************************************
* Class Function: lineProcess()                                 *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Reads in a line from the file                    *
* Input parameters: int&, 2x string&                            *
* Returns: Nothing                                              *
* Preconditions: int&, 2x string&                               *
* Postconditions: The line has been read and processed          *
*****************************************************************/
void DataAnalysis::lineProcess(int& units, string& type, string& transaction) {
	string line = "", temp = "";
	int i = 0;

	getline(mCsvStream, line); //Gets entire line

	//Grabs units part
	for (i; line[i] != ','; i++)
		temp += line[i];
	units = stoi(temp); //String to integer conversion

	//Grabs type part
	temp = "";
	i++;
	for (i; line[i] != ','; i++)
		temp += line[i];
	type = temp;

	//Grabs transaction part
	temp = "";
	i++;
	for (i; i < line.length(); i++)
		temp += line[i];
	transaction = temp;
}

/****************************************************************
* Class Function: importFile()                                  *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Reads in every line and inserts them into trees  *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: All data has been imported into the trees     *
*****************************************************************/
void DataAnalysis::importFile() {
	int units = 0;
	string type = "", transaction = "";

	getline(mCsvStream, type);
	while (!mCsvStream.eof()) {
		lineProcess(units, type, transaction); //Reads in a line
		insertInTrees(transaction, units, type); //Inserts data into a tree
	}

	cout << "Sold Tree:" << endl;
	mTreeSold.inOrderTraversal(); //Prints tree
	cout << endl << "Purchased Tree:" << endl;
	mTreePurchased.inOrderTraversal();
}

/****************************************************************
* Class Function: insertInTrees()                               *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Inserts the data into the trees                  *
* Input parameters: 2x string and int                           *
* Returns: Nothing                                              *
* Preconditions: 2x string and int                              *
* Postconditions: The data has been inserted into a tree        *
*****************************************************************/
void DataAnalysis::insertInTrees(string transaction, int units, string type) {
	if (transaction == "Sold")
		mTreeSold.insert(units, type);
	else if (transaction == "Purchased")
		mTreePurchased.insert(units, type);
}

/****************************************************************
* Class Function: display()                                     *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Displays the trends                              *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: The trends have been displayed                *
*****************************************************************/
void DataAnalysis::display() {
	cout << endl << "Sold the most: " << mTreeSold.findLargest().getData() << " with " << mTreeSold.findLargest().getUnits() << " units" << endl;
	cout << "Sold the least: " << mTreeSold.findSmallest().getData() << " with " << mTreeSold.findSmallest().getUnits() << " units" << endl;
	cout << "Purchased the most: " << mTreePurchased.findLargest().getData() << " with " << mTreePurchased.findLargest().getUnits() << " units" << endl;
	cout << "Purchased the least: " << mTreePurchased.findSmallest().getData() << " with " << mTreePurchased.findSmallest().getUnits() << " units" << endl << endl;
}