#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		m_a = 10;
		cout << "Base Constructor" << endl;
	}
	~Base()
	{
		cout << "Base Destructor" << endl;
	}

	int m_a;
};

class Hertiage : public Base
{
public:
	Hertiage()
	{
		m_a = 100;
		cout << "Hertiage Constructor" << endl;
	}
	~Hertiage()
	{
		cout << "Hertiage Destructor" << endl;
	}

	int m_a;
};

int main() 
{
	Hertiage h;
	cout << h.m_a << endl;
	cout << h.Base::m_a << endl;
	system("cls");
	return 0;
}
