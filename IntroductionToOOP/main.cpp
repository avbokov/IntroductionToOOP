// IntroductionToOOP
#include<iostream>
using namespace std;

class Point // �������� ��������� ��� �����, �� ������� ����� ��� ������
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
	// type name; // ��������� ���������� ����������
	int a; // ���������� ���������� 'a' ���� 'int'
	Point A; // ���������� ���������� 'A' ���� 'Point'
			 // �������� ������� 'A' ��������� 'Point'
			 // ���������� ������� 'A' ��������� 'Point'
			 // �������� ���������� 'A' ��������� 'Point'
	A.x = 2;
	A.y = 3;

	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A; // ������� ��� ��������� ��������� �� Point
	cout << pA->x << "\t" << pA->y << endl;
#endif STRUCT_POINT

	Point A;

	A.set_x(2);
	A.set_y(3);

	cout << A.get_x() << "\t" << A.get_y() << endl;

	double d = A.distance(A.get_x(),A.get_y());

	cout << d;

}
// 1. ������������ - Encapsulation;
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
//