#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////						CLASS DECLARATION - ���������� ������					///////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);

class String
{
	int size;		// ������ ������ � ������
	char* str;		// ��������� �� ������ � ������������ ������

public:

	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//				Constructors:

	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//				Operators:

	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& right);

	const char& operator[](int i)const;
	char& operator[](int i);

	//				Methods:

	void print()const;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////					CLASS DECLARATION END - ����� ���������� ������				///////
///////////////////////////////////////////////////////////////////////////////////////////////////////////