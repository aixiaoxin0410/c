#include <iostream>
using namespace std;

template<class T1,class T2>
class Person
{
public:

	Person(T1 name, T2 age);
	void showPerson();

	T1 p_Name;
	T2 p_Age;
}; 

//成员函数 类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->p_Name = name;
	this->p_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名: " << this->p_Name << " 年龄:" << this->p_Age << endl;
}

int main() 
{
	Person<string, int> p("Tom", 20);
	p.showPerson();
	system("cls");
	return 0;
}
