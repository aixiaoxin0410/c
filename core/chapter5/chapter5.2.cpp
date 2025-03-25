#include <iostream>
using namespace std;

class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Hertiage : public Base1
{
public:
	void func()
	{
		m_A = 10;
		m_B = 10;
		// m_C = 10; // m_C is private in Base1
	}
};

class Hertiage1 : protected Base1
{
public:
	void func()
	{
		m_A = 10;
		m_B = 10;
	}
};

class Hertiage2 : private Base1
{
public:
	void func()
	{
		m_A = 10;
		m_B = 10;
	}
};

int main() 
{
	Hertiage h;
	h.func();
	cout << h.m_A << endl;
	Hertiage1 h1;
	// h1.m_A = 10;
	h1.func();
	Hertiage2 h2;
	// h2.m_A = 10;
	system("cls");
	return 0;
}
