// Fraction_ClassWork
#include"Fraction.h"

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define ISTREAM_OPERATOR_CHECK
//#define COMPARISON_OPERATOR_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSION_FROM_OTHER_TYPES_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER_TYPES

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

#ifdef ARITHMETICAL_OPERATORS_CHECK
	double a = 2;
	double b = 3;
	double c = a * b;
	c++;

	Fraction A(2, 3, 4);
	/*A.to_improper();
	A.print();
	A.to_proper();
	A.print();*/
	Fraction B(3, 4, 5);

	A = B++;
	A.print();
	A = ++B;
	A.print();

	A = B--;
	A.print();
	A = --B;
	A.print();

	A *= B;
	A.print();

	A /= B;
	A.print();

	A.print();
	B.print();

	cout << A << endl;
	cout << B << endl;
		
	/*A += B;
	A.print();

	A -= B;
	A.print();*/

	/*Fraction C = A * B;
	C.print();

	C = A / B;
	C.print();

	C = A + B;
	C.print();

	C = A - B;
	C.print();

	Fraction D = C;
	C.print();

	A = B = C = Fraction(1, 2, 3); // Разобраться!!!
	A.print();
	B.print();
	C.print();*/
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef ISTREAM_OPERATOR_CHECK
	/*Fraction A;
cout << "Введите простую дробь: "; cin >> A;
cout << A << endl;

Fraction B;
cout << "Введите простую дробь: "; cin >> B;
cout << B << endl;

A.reduction();
A.print();

B.reduction();
B.print();

cout << operator==(A, B) << endl;
cout << operator!=(A, B) << endl;
cout << operator>(A, B) << endl;
cout << operator<(A, B) << endl;*/
#endif // ISTREAM_OPERATOR_CHECK

#ifdef COMPARISON_OPERATOR_CHECK
	Fraction A(2, 1, 3);
	Fraction B(2, 5, 10);
	cout << "\n---------------------------------------------\n";
	cout << (A >= B) << endl;
	cout << "\n---------------------------------------------\n";
#endif // COMPARISON_OPERATOR_CHECK

#ifdef TYPE_CONVERSIONS_BASICS
	// (type)value;	C-like notation
// type(value);	Functional notation
// Warning C4244: ... possible loss of data

	int a = 2;		// no conversion
	double b = 3;	// conversion from less to more
	int c = b;		// conversion from more to less without data loss
	int d = 8.3;	// conversion from more to less with data loss
	int e = a + b;	// 2 conversion in both directions 
					// два преобразования в обоих направлениях  
#endif // TYPE_CONVERSIONS_BASICS

#ifdef CONVERSION_FROM_OTHER_TYPES_TO_CLASS
			// 1. Другие типы в наш тип;
// 2. Из нашего типа в другие типы;

	double a = 2;	// Conversion from int to double (from less to more)
	cout << a << endl;
	Fraction A = (Fraction)5;	// Conversion from int to fraction()
	cout << A << endl;
	Fraction B;
	cout << "\n---------------------------------------------\n";
	B = Fraction(8);	// operator= (CopyAssignment)
	cout << "\n---------------------------------------------\n";
	cout << B << endl;
	//Fraction C = 12;	// explicit конструктор так не вызывается
	Fraction C(12);		// его можно вызвать только так  
#endif // CONVERSION_FROM_OTHER_TYPES_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER_TYPES
	Fraction A(2, 3, 4);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;
	// Type-cast operators;
	//operator type()
	//{
	//	// conversion
	//	// ...
	//}
	double b = (double)A;
	//Fraction - простая дробь
	//double - десятичная
	cout << b << endl;
	int c = int(A);
	cout << c << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER_TYPES

	/*Fraction A(2, 5, 10);
	cout << A.reduce() << endl;
	cout << Fraction(840, 3600).reduce() << endl;*/

	Fraction A = 2.76123;	// Перевести в простую дробь
	cout << A << endl;
}
