// Fraction
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction // создавая структуру или класс, мы создаем новый тип данных
{
	int ch;
	int zn;

public: // открываем интерфейсную часть класса
	
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
	
	void print()const // константный метод, который не изменят объект
	{
		cout << "Ваша дробь = " << ch << "/" << zn << endl;
	}
};


Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result; // Локальный объект, в который будет сохранён результат
	result.set_ch((right.get_zn() * left.get_ch()) + (left.get_zn()*right.get_ch()));
	result.set_zn(left.get_zn() * right.get_zn());
	return result;
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction result; // Локальный объект, в который будет сохранён результат
	result.set_ch((right.get_zn() * left.get_ch()) - (left.get_zn() * right.get_ch()));
	result.set_zn(left.get_zn() * right.get_zn());
	return result;
}

Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction result; // Локальный объект, в который будет сохранён результат
	result.set_ch(left.get_ch() * right.get_ch());
	result.set_zn(left.get_zn() * right.get_zn());
	return result;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result; // Локальный объект, в который будет сохранён результат
	result.set_ch(left.get_ch() * right.get_zn());
	result.set_zn(left.get_zn() * right.get_ch());
	return result;
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	os << "Ваша дробь = " << obj.get_ch() << "/" << obj.get_zn();
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



// 1. Инкапсуляция - Encapsulation; - святая святых ООП!
// 
// Модификаторы доступы:
//		private : закрытые поля, доступны только внутри класса/структуры
//		public : открытые поля, доступны из любого места программы
//		protected : защищенные поля, доступны изнутри класаа и изнутри дочерних классов
//			     	Этот модификатор доступа используется только при наследовании
// get/set-методы:
// 
// 2. Наследование - Inheritance;
// 3. Полиморфизм - Polymorphism;
// 
// 
// 1. Constructor - это метод, который создает объект;
//		- с параметрами;
//		- без параметров;
//		- по умолчанию - это конструктор, который МОЖЕТ БЫТЬ ВЫЗВАН без параметров;
//		- конструктор копирования;
//		- конструктор переноса;
// 
// 2. ~Destructor - это метод, который уничтожает объект по звавершении его времени жизни;
// 3.AssignmentOperator;
//

//			Operators overloading rules:
// 1. Перегрузить можно только существующие операторы:
// 
//	+ перегружается
//	++ перегружается
//	* перегружается
//	** НЕ перегружается
// 
//	2. Не все существующие операторы можно перегрузить
// 
//	НЕ перегружаются:
//	? : - ternary;
//	:: Scope operator (оператор разрешения видимости);
//	. - Point optrator (оператор прямого досутпа);
//	.* - Pointer to class member operatpr;
//	#
//	##
//
// 3. Перегруженные операторы сохраняют приоритет.
// 4. Переопределить поведение операторов над встроенными типами невозможно.
// 
//




