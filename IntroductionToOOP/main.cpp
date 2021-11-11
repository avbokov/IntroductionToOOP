// IntroductionToOOP
#include<iostream>
using namespace std;

class Point // создава€ структуру или класс, мы создаем новый тип данных
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double distance(double x, double y)
	{
		double dist;

		dist = sqrt(this->x * this->x + this->y * this->y);

		return dist;
	}

};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	// type name; // синтаксис объ€влени€ переменной
	int a; // объ€вление переменной 'a' типа 'int'
	Point A; // объ€вление переменной 'A' типа 'Point'
			 // создание объекта 'A' структуры 'Point'
			 // объ€вление объекта 'A' структуры 'Point'
			 // создание экземпл€ра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;

	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A; // создаем или объ€вл€ем указатель на Point
	cout << pA->x << "\t" << pA->y << endl;
#endif STRUCT_POINT

	Point A;

	A.set_x(2);
	A.set_y(3);

	cout << A.get_x() << "\t" << A.get_y() << endl;

	double d = A.distance(A.get_x(),A.get_y());

	cout << d;

}
// 1. »нкапсул€ци€ - Encapsulation;
// 
// ћодификаторы доступы:
//		private : закрытые пол€, доступны только внутри класса/структуры
//		public : открытые пол€, доступны из любого места программы
//		protected : защищенные пол€, доступны изнутри класаа и изнутри дочерних классов
//			     	Ётот модификатор доступа используетс€ только при наследовании
// get/set-методы:
// 
// 2. Ќаследование - Inheritance;
// 3. ѕолиморфизм - Polymorphism;
// 
// 
//