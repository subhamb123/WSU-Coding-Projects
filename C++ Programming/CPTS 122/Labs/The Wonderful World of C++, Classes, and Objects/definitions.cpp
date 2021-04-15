#include "parent.h"

Complex::Complex() {
	real = 0;
	imaginary = 0;
}

Complex::Complex(double real, double imaginary) {
	this->real = real;
	this->imaginary = imaginary;
}

void Complex::setReal(double real) {
	this->real = real;
}

void Complex::setImaginary(double imaginary) {
	this->imaginary = imaginary;
}

double Complex::getReal() const {
	return real;
}

double Complex::getImaginary() const {
	return imaginary;
}

Complex& Complex::add(Complex& num) {
	Complex number;
	double addReal = this->real + num.real, addImaginary = this->imaginary + num.imaginary;
	number.setReal(addReal);
	number.setImaginary(addImaginary);

	return number;
}

Complex& add(const Complex& num1, const Complex& num2) {
	Complex number;
	double addReal = num1.getReal() + num2.getReal(), addImaginary = num1.getImaginary() + num2.getImaginary();
	number.setReal(addReal);
	number.setImaginary(addImaginary);

	return number;
}

void Complex::read() {
	char temp = '\0', garbage = '\0';
	cin >> this->real >> this->imaginary >> garbage;
}

void Complex::print() {
	if (this->imaginary >= 0)
		cout << this->real << "+" << this->imaginary << "i" << endl;
	else
		cout << this->real << this->imaginary << "i" << endl;
}

Complex& operator+ (const Complex& num1, const Complex& num2) {
	Complex number;
	double addReal = num1.getReal() + num2.getReal(), addImaginary = num1.getImaginary() + num2.getImaginary();
	number.setReal(addReal);
	number.setImaginary(addImaginary);

	return number;
}

Complex& operator- (const Complex& num1, const Complex& num2) {
	Complex number;
	double subReal = num1.getReal() - num2.getReal(), subImaginary = num1.getImaginary() - num2.getImaginary();
	number.setReal(subReal);
	number.setImaginary(subImaginary);

	return number;
}

istream& operator>> (istream& lhs, Complex& rhs) {
	double real = 0, imaginary = 0;
	char garbage = '\0';
	lhs >> real >> imaginary >> garbage;
	rhs.setReal(real);
	rhs.setImaginary(imaginary);
	return lhs;
}

ostream& operator<< (ostream& lhs, const Complex& rhs) {
	if (rhs.getImaginary() >= 0)
		lhs << rhs.getReal() << "+" << rhs.getImaginary() << "i" << endl;
	else
		lhs << rhs.getReal() << rhs.getImaginary() << "i" << endl;

	return lhs;
}