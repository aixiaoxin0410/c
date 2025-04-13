#include <iostream>
using namespace std;

class Base
{
public:
	void func()
	{
		cout << "Base::func()" << endl;
	}

	void func(int a)
	{
		cout << "Base::func(int)" << endl;
	}

	int m_a;
};

class Hertiage : public Base
{
public:
	void func()
	{
		cout << "Hertiage::func()" << endl;
	}
	int m_a;
};

int main() 
{
	Hertiage h;
	h.func();
	h.Base::func();
	h.Base::func(10);
	system("cls");
	return 0;
}
