// Fraction_ClassWork
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction
{
	int integer;		// Целая часть
	int numerator;		// Числитель
	int denominator;	// Знаменатель

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	//			Constractors

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:" << this << endl;
	}

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:" << this << endl;
	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//			Methods:

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper()
	{
		integer = numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;
		return inverted;
	}

	void print()const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}

};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result
		(
			left.get_numerator() * right.get_numerator(),
			left.get_denominator() * right.get_denominator()
		);*/
		/*result.set_numerator(left.get_numerator() * right.get_numerator());		// сделали прям в result, в круглых скобках ()
		result.set_denominator(left.get_denominator() * right.get_denominator());*/
		//result.to_proper();
		//return result;
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
		(
			left.get_numerator() * right.get_denominator(),
			left.get_denominator() * right.get_numerator()
		).to_proper();*/
	return left * right.inverted();
}



//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//Default constructor;
	A.print();

	double b = 3;
	Fraction B = 5;// Single-argument constructor
	B.print();

	Fraction C(3, 4);
	C.print();

	Fraction D(4, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK

	int a = 2;
	int b = 3;
	int c = a * b;

	Fraction A(2, 3, 4);
	/*A.to_improper();
	A.print();
	A.to_proper();
	A.print();*/
	Fraction B(3, 4, 5);
	Fraction C = A * B;
	C.print();

	C = A / B;
	C.print();
}