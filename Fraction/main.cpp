// Fraction
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction // �������� ��������� ��� �����, �� ������� ����� ��� ������
{
	int ch;
	int zn;

public: // ��������� ������������ ����� ������
	
	int get_ch()const
	{
		return ch;
	}
	int get_zn()const
	{
		return zn;
	}
	void set_ch(int ch)
	{
		this->ch = ch;
	}
	void set_zn(int zn)
	{
		this->zn = zn;
	}
	
	Fraction(int ch = 1, int zn = 1)
	{
		this->ch = ch;
		this->zn = zn;
		cout << "Costructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->ch = other.ch;
		this->zn = other.zn;
		cout << "CopyCostructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	////						Operators:

	Fraction& operator=(const Fraction& other)
	{
		this->ch = other.ch;
		this->zn = other.zn;
		cout << "CopyAssignment:\t" << this << endl;

		return *this;
	}
	
	//						 Methods:
	
	void print()const // ����������� �����, ������� �� ������� ������
	{
		cout << "���� ����� = " << ch << "/" << zn << endl;
	}
};


Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result; // ��������� ������, � ������� ����� ������� ���������
	result.set_ch((right.get_zn() * left.get_ch()) + (left.get_zn()*right.get_ch()));
	result.set_zn(left.get_zn() * right.get_zn());
	return result;
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction result; // ��������� ������, � ������� ����� ������� ���������
	result.set_ch((right.get_zn() * left.get_ch()) - (left.get_zn() * right.get_ch()));
	result.set_zn(left.get_zn() * right.get_zn());
	return result;
}

Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction result; // ��������� ������, � ������� ����� ������� ���������
	result.set_ch(left.get_ch() * right.get_ch());
	result.set_zn(left.get_zn() * right.get_zn());
	return result;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result; // ��������� ������, � ������� ����� ������� ���������
	result.set_ch(left.get_ch() * right.get_zn());
	result.set_zn(left.get_zn() * right.get_ch());
	return result;
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	os << "���� ����� = " << obj.get_ch() << "/" << obj.get_zn();
	return os;
}


//#define ASSIGMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");

	Fraction A(4, 5);
	Fraction B(2, 3);
	
	A.print();
	B.print();

	cout << A << endl;
	cout << B << endl;
		
	(A + B).print();
	(A - B).print();
	(A * B).print();
	(A / B).print();

	A = B;
	A.print();
	B.print();
}



// 1. ������������ - Encapsulation; - ������ ������ ���!
// 
// ������������ �������:
//		private : �������� ����, �������� ������ ������ ������/���������
//		public : �������� ����, �������� �� ������ ����� ���������
//		protected : ���������� ����, �������� ������� ������ � ������� �������� �������
//			     	���� ����������� ������� ������������ ������ ��� ������������
// get/set-������:
// 
// 2. ������������ - Inheritance;
// 3. ����������� - Polymorphism;
// 
// 
// 1. Constructor - ��� �����, ������� ������� ������;
//		- � �����������;
//		- ��� ����������;
//		- �� ��������� - ��� �����������, ������� ����� ���� ������ ��� ����������;
//		- ����������� �����������;
//		- ����������� ��������;
// 
// 2. ~Destructor - ��� �����, ������� ���������� ������ �� ����������� ��� ������� �����;
// 3.AssignmentOperator;
//

//			Operators overloading rules:
// 1. ����������� ����� ������ ������������ ���������:
// 
//	+ �������������
//	++ �������������
//	* �������������
//	** �� �������������
// 
//	2. �� ��� ������������ ��������� ����� �����������
// 
//	�� �������������:
//	? : - ternary;
//	:: Scope operator (�������� ���������� ���������);
//	. - Point optrator (�������� ������� �������);
//	.* - Pointer to class member operatpr;
//	#
//	##
//
// 3. ������������� ��������� ��������� ���������.
// 4. �������������� ��������� ���������� ��� ����������� ������ ����������.
// 
//




