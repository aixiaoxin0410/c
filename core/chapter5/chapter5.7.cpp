#include <iostream>
using namespace std;

//菱形继承
class A
{
public:
	A()
	{
		m_age = 10;
	}

	int m_age;
};

//利用虚继承解决菱形继承问题

class B_A:virtual public A
{

};

class C_A:virtual public A
{

};

class D_BC:public B_A, public C_A
{

};

int main() 
{
	D_BC d_bc;
	d_bc.B_A::m_age = 20;
	d_bc.C_A::m_age = 30;
	cout << d_bc.B_A::m_age << endl;
	cout << d_bc.C_A::m_age << endl;
	cout << d_bc.m_age << endl;
	system("cls");
	return 0;
}
