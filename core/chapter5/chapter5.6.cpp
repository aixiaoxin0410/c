#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		m_a = 10;
	}

	int m_a;
};

class Base1
{
public:
	Base1()
	{
		m_b = 20;
	}
	int m_b;
};

class Base2:public Base, public Base1
{
public:
	Base2()
	{
		m_c = 30;
	}
	int m_c;
};

int main() 
{
	Base2 base2;
	cout << base2.m_a <<endl;
	system("cls");
	return 0;
}
