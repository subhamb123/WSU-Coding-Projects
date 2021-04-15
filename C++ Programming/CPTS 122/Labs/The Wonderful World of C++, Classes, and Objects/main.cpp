#include "parent.h"

int main() {
	Complex n1 = { 5,3 }, n2 = { 10,6 };
	n1 = n1.add(n2);

	cout << n1.getReal() << "+" << n1.getImaginary() << "i" << endl;

	n1.setReal(1);
	n1.setImaginary(8);
	n1 = add(n1, n2);
	cout << n1.getReal() << "+" << n1.getImaginary() << "i" << endl;

	n1.setReal(1);
	n1.setImaginary(8);
	n1 = n1 + n2;
	cout << n1.getReal() << "+" << n1.getImaginary() << "i" << endl;

	n1.setReal(1);
	n1.setImaginary(8);
	n1 = n1 - n2;
	cout << n1.getReal() << "+" << n1.getImaginary() << "i" << endl;

	cout << "Enter a complex number" << endl;
	n1.read();
	if(n1.getImaginary() >= 0)
		cout << n1.getReal() << "+" << n1.getImaginary() << "i" << endl;
	else
		cout << n1.getReal() << n1.getImaginary() << "i" << endl;

	cout << "Enter two complex numbers in the form a + bi(each separated by whitespace)" << endl;

	cin >> n1 >> n2;
	if (n1.getImaginary() >= 0)
		cout << n1.getReal() << "+" << n1.getImaginary() << "i" << endl;
	else
		cout << n1.getReal() << n1.getImaginary() << "i" << endl;

	if (n2.getImaginary() >= 0)
		cout << n2.getReal() << "+" << n2.getImaginary() << "i" << endl;
	else
		cout << n2.getReal() << n2.getImaginary() << "i" << endl;

	n1.print();

	cout << n1 << n2 << endl;

	return 0;
}