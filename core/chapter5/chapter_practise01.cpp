#include <iostream>
using namespace std;

class calculator
{
public:

	virtual int getresult()
	{
		return 0;
	}

	int m_a;
	int m_b;
};

class addcalc:public calculator
{
	int getresult()
	{
		return m_a + m_b;
	}
};

class subcalc:public calculator
{
	int getresult()
	{
		return m_a - m_b;
	}
};

class mulcalc:public calculator
{
	int getresult()
	{
		return m_a * m_b;
	}
};

class divcalc:public calculator
{
	int getresult()
	{
		return m_a / m_b;
	}
};

void add()
{
	calculator *calc = new addcalc;
	calc->m_a = 10;
	calc->m_b = 20;
	cout << calc->m_a << " + " << calc->m_b << " = " << calc->getresult() << endl;
	delete calc; // 释放内存
}

int main() 
{
	add();
	system("cls");
	return 0;
}
