//String_separation
#include"String.h"



#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK
//#define CONSTRUCTORS_CALLING

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef CONSTRUCTORS_CHECK
	//String str = 5;		// DefaultConstructor
	String str(5);		// DefaultConstructor - в таком виде благодар€ explicit
	str.print();

	String str1 = "Hello";
	str1 = str1;
	//str1.print();
	cout << str1 << endl;

	String str2 = str1;		// CopyConstructor
	cout << str2 << endl;
	// Deep copy
	// Shallow copy

	String str3;
	str3 = str2;		// CopyAssignment (operator=)
	//str3.operator=(str2);    вызов оператора присвоить €вным образом
	cout << str3 << endl;

	int a = 2;
	int b = 3;
	a = b;
	cout << a << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << "\n----------------------------------------------------\n";
	String str3;	// не€вно вызываем оператор +
	str3 = str1 + str2;
	cout << "\n----------------------------------------------------\n";
	cout << str3 << endl;
	//cout << operator+(str1, str2) << endl;	// €вный вызов оператора +
	//str1 += str2;
	//cout << str1 << endl;

	// Move - методы (методы переноса).
	/* онструктор переноса
	ќпертор присваивани€ переноса*/
#endif // OPERATOR_PLUS_CHECK

#ifdef CONSTRUCTORS_CALLING
	String str1;				// Defaul constructor
	cout << str1 << endl;
	String str2 = "Hello";		// Single-Argument constructor
	cout << str2 << endl;
	String str3 = str2;			// Copy Constructor
	cout << str3 << endl;

	String str4();				// здесь не создаЄтс€ никакой объект,
								// эта строка не вызывает конструктор по умолчанию €вным образом
								//здесь объ€вл€етс€ фугкйци€ str4(), котора€ ничего не принимает,
								// и возвращает объект класса String
	//cout << str4 << endl;
	String str5{};				// явный вызов конструктора
	str5.print();
#endif // CONSTRUCTORS_CALLING

	

}