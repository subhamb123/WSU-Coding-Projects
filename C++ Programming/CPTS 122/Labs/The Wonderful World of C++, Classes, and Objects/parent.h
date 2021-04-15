#ifndef parent

#define parent
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Complex {
public:
	Complex();
	Complex(double real, double imaginary);
	void setReal(double real);
	void setImaginary(double imaginary);
	double getReal() const;
	double getImaginary() const;
	Complex& add(Complex& num);
	void read();
	void print();

private:
	double real;
	double imaginary;
};

Complex& add(const Complex& num1, const Complex& num2);
Complex& operator+ (const Complex& num1, const Complex& num2);
Complex& operator- (const Complex& num1, const Complex& num2);
istream& operator>> (istream& lhs, Complex& rhs);
ostream& operator<< (ostream& lhs, const Complex& rhs);

#endif