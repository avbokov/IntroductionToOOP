#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
ostream& operator<<(ostream& os, const Fraction& obj);

class Fraction
{
	int integer;		// Öåëàÿ ÷àñòü
	int numerator;		// ×èñëèòåëü
	int denominator;	// Çíàìåíàòåëü

public:

	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//			Constractors

	Fraction();
	Fraction(const Fraction& other);

	// explicit - ÿâíûé
	explicit Fraction(int integer);

	Fraction(double decimal);

	//Fraction(double des_drob)
	//{
	//	this->integer = (int)des_drob;
	//	double drob_part = des_drob - (int)des_drob;
	//	int kol_znak = 0;
	//	while (drob_part != 0)
	//	{
	//		drob_part *= 10;
	//		drob_part = drob_part - (int)drob_part;
	//		kol_znak++;
	//	}
	//	this->numerator = (des_drob - (int)des_drob)*pow(10, kol_znak);
	//	this->denominator = pow(10, kol_znak);
	//	//reduce();
	//}

	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	~Fraction();

	//			Operators:

	//Fraction& operator=(const Fraction& other)
	//{
	//	this->integer = other.integer;
	//	this->numerator = other.numerator;
	//	this->denominator = other.denominator;
	//	cout << "CopyAssignment:\t" << this << endl;
	//	return *this; // ÎÏÅÐÀÒÎÐ ÏÐÈÑÂÀÈÂÀÍÈß ÂÑÅÃÄÀ ÂÎÇÂÐÀÙÀÅÒ ÐÀÇÈÌÅÍÎÂÀÍÍÛÉ THIS !!!
	//}

	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	Fraction operator+=(Fraction right);
	Fraction operator-=(Fraction right);

	//			Increment/Decrement

	Fraction& operator++(); // ïðåôèêñ
	Fraction operator++(int); // ïîñòôèêñ
	Fraction& operator--(); // ïðåôèêñ
	Fraction operator--(int); // ïîñòôèêñ

	//			Type-cast operators:

	explicit operator int()const;
	explicit operator double()const;

	//			Methods:

	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;
	Fraction& reduction(); // ñîêðàùàåì äðîáü, åñëè ýòî âîçìîæíî
	Fraction& reduce();

	void print()const;
};