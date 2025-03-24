#include <iostream>
using namespace std;

class Person
{
public:

	//成员函数重载+号
	// Person operator+(Person &p)
	// {
	// 	Person temp;
	// 	temp.m_a = this->m_a + p.m_a;
	// 	temp.m_b = this->m_b + p.m_b;
	// 	return temp;
	// }
	
	int m_a;
	int m_b;

};

//全局函数重载+号
// Person operator+(Person &p1,Person &p2)
// {
// 	Person temp;
// 	temp.m_a = p1.m_a + p2.m_a;
// 	temp.m_b = p1.m_b + p2.m_b;
// 	return temp;
// }

//运算符重载 可以发生函数重载 
Person operator+(Person& p2, int val)  
{
	Person temp;
	temp.m_a = p2.m_a + val;
	temp.m_b = p2.m_b + val;
	return temp;
}

int main() 
{
	Person p1;
	p1.m_a = 10;
	p1.m_b = 10;

	Person p2;
	p2.m_a = 10;
	p2.m_b = 10;

	//成员函数重载本质调用
	//Person p3 = p1.operator+(p2);
	//Person p3 = p1 + p2;

	Person p3 = p1 + 100;

	cout << p3.m_a << endl;
	cout << p3.m_b << endl;

	system("cls");
	return 0;
}
