// This example illustrates how to define a Stack class template.

#include "TestStack.h"

//#include <vector>

int main(void)
{
	int item1 = -89, item2 = 104;

	//	vector<int> my_vector; // vector<> is from the Standard Template Library (STL)

	TestStack<int> tester;

	tester.Test(item1, item2);

	cout << item1 << endl << item2 << endl;

	Stack<int> stack;
	Stack<string> stack2;

	string s1 = "6 2 + 5 * 8 4 / - =", s2 = "5 6 2 * + 9 / =", s3 = "4 5 / 6 8 * - =", s4 = "A + B * C / D - E =", s5 = "(A + B * (C - D)) / E =";
	
	cout << stack.postFix(s1) << endl;
	cout << stack.postFix(s2) << endl;
	cout << stack.postFix(s3) << endl;

	return 0;
}