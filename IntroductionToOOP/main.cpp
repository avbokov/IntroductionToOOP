// IntroductionToOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Point // создавая структуру или класс, мы создаем новый тип данных
{
	double x;
	double y;

public: // открываем интерфейсную часть класса
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

	// Constructors:
	//Point()
	//{
	//	x = y = double(); // в обе координаты кладём значение по умолчанию для double;
	//	cout << "DefaultConstructor:\t" << this << endl;
	//}
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Costructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyCostructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//						Operators:
	 
	Point& operator=(const Point& other)
	{
		
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	Point operator++() // Prefix increment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this; // сохраняем старое значение объекта
		x++;
		y++;
		return old;
	}

	//						 Methods:

	double distance(const Point& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * x_distance);

		return distance;
	}

	void print()const // константный метод, который не изменят объект
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	return sqrt(pow(A.get_x() - B.get_x(), 2)+ pow(A.get_y() - B.get_y(), 2));
}

Point operator+(const Point& left, const Point& right)
{
	Point result; // Локальный объект, в который будет сохранён результат
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

Point operator-(const Point& left, const Point& right)
{
	Point result(left.get_x() - right.get_x(), left.get_y() - right.get_y());
	return result;
}

Point operator*(const Point& left, const Point& right)
{
	return Point(left.get_x() * right.get_x(), left.get_y() * right.get_y());
}

ostream& operator<<(ostream& os, const Point& obj)
{
	os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
	return os;
}


//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGMENT_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK

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

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(3, 4);
	cout << "\n---------------------------------------------------------------\n";
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << "\n---------------------------------------------------------------\n";
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << "\n---------------------------------------------------------------\n";
	cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
	cout << "\n---------------------------------------------------------------\n";
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
	cout << "\n---------------------------------------------------------------\n";
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	cout << int() << endl; // Значение по умолчанию для int.
	Point A; // Default constructor

	/*A.set_x(2);
	A.set_y(3);*/

	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B = 5; // Single-argument constructor
	B.print();

	Point C(7); // Single-argument constructor
	C.print();

	Point D(4, 5);
	D.print();

	Point E = D; // Copy constructor
	E.print();

	Point F;	// Default Constructor
	F = E;		// Copy Assignment
	F.print();
#endif // CONSTRUCTORS_CHECK
	
#ifdef ASSIGMENT_CHECK
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	cout << "\n-----------------------------------------" << endl;
	A = B = C = Point(2, 3);
	cout << "\n-----------------------------------------" << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGMENT_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK

	int a = 2;
	int b = 2;
	int c = a + b;

	Point A(2, 3);
	Point B(3, 4);
	A += B;
	A.print();

	B = A++;
	/*A.print();
	B.print();*/
	cout << A << endl;
	cout << B << endl;

	/*for (Point i = 0; i.get_x() < 10; i++)
	{
		i.print();
	}*/


	Point C = A + B;
	C.print();
	Point D = A - B;
	D.print();
	(A * B).print();
#endif // ARITHMETICAL_OPERATORS_CHECK

		

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




