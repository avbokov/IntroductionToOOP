// IntroductionToOOP
#include<iostream>
using namespace std;

class Point // создавая структуру или класс, мы создаем новый тип данных
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
		/*double dist;
		dist = sqrt(this->x * this->x + this->y * this->y);
		return dist;*/
		return sqrt(this->x * this->x + this->y * this->y);
	}

};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	// type name; // синтаксис объявления переменной
	int a; // объявление переменной 'a' типа 'int'
	Point A; // объявление переменной 'A' типа 'Point'
			 // создание объекта 'A' структуры 'Point'
			 // объявление объекта 'A' структуры 'Point'
			 // создание экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;

	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A; // создаем или объявляем указатель на Point
	cout << pA->x << "\t" << pA->y << endl;
#endif STRUCT_POINT

	Point A;

	A.set_x(2);
	A.set_y(3);

	cout << A.get_x() << "\t" << A.get_y() << endl;
		
	cout << A.distance(A.get_x(),A.get_y());
		

}
// 1. Инкапсуляция - Encapsulation;
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
//