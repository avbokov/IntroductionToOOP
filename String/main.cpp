//String_constructor_delegation
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;		// размер строки в байтах
	char* str;		// указатель на строку в динамической памяти

public:

	int get_size()const
	{
		return size;
	}

	const char* get_str()const
	{
		return str;
	}

	char* get_str()
	{
		return str;
	}

	//				Constructors:

	explicit String(int size = 80) :size(size), str(new char[size] {}) // такая форма записи только для конструкторов
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}

	String(const char* str) :String(strlen(str)+1) // такая форма записи только для конструкторов
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}

	String(const String& other) : String(other.str) // такая форма записи только для конструкторов
	{
		//	Deep copy
		//this->size = other.size;
		//this->str = new char[size] {};
		//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}

	String(String&& other): size(other.size), str(other.str) // такая форма записи только для конструкторов
	{
		//this->size = other.size;
		//this->str = other.str;		// Копируем указатель на уже выделенную память, принадлежащую другому объекту
		other.str = nullptr;		// Зануляем указатель в другом объекте, чтобы деструктор НЕ смог удалить память,
									// которая ему принадлежит
		other.size = 0;
		cout << "MoveConstructor:" << this << endl;
	}

	~String()
	{
		delete[] this->str;
		this->str = nullptr;
		this->size = 0;
		cout << "Destructor:\t" << this << endl;
	}
	//				Operators:
	
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		//	Deep copy
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		other.size = 0;
		cout << "MoveAssignment:\t" << this << endl;
	}


	const char& operator[](int i)const
	{
		return str[i];
	}
	
	char& operator[](int i)
	{
		return str[i];
	}

	String& operator+=(const String& right)
	{
		return *this = *this + right;
	}

	//				Methods:

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];
	return result;
}


ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK
//#define CONSTRUCTORS_CALLING

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef CONSTRUCTORS_CHECK
	//String str = 5;		// DefaultConstructor
	String str(5);		// DefaultConstructor - в таком виде благодаря explicit
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
	//str3.operator=(str2);    вызов оператора присвоить явным образом
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
	String str3;	// неявно вызываем оператор +
	str3 = str1 + str2;
	cout << "\n----------------------------------------------------\n";
	cout << str3 << endl;
	//cout << operator+(str1, str2) << endl;	// явный вызов оператора +
	//str1 += str2;
	//cout << str1 << endl;

	// Move - методы (методы переноса).
	/*Конструктор переноса
	Опертор присваивания переноса*/
#endif // OPERATOR_PLUS_CHECK

#ifdef CONSTRUCTORS_CALLING
	String str1;				// Defaul constructor
	cout << str1 << endl;
	String str2 = "Hello";		// Single-Argument constructor
	cout << str2 << endl;
	String str3 = str2;			// Copy Constructor
	cout << str3 << endl;

	String str4();				// здесь не создаётся никакой объект,
								// эта строка не вызывает конструктор по умолчанию явным образом
								//здесь объявляется фугкйция str4(), которая ничего не принимает,
								// и возвращает объект класса String
	//cout << str4 << endl;
	String str5{};				// Явный вызов конструктора
	str5.print();
#endif // CONSTRUCTORS_CALLING

	

}