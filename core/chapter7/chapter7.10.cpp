#include <iostream>
using namespace std;

// 第一种解决方式，包含源文件
// #include "Person.h"

// 第二种方法(常用)：将.h和.cpp的内容写在一起，然后将后缀名改成.hpp文件
#include "Person.hpp"

// template<class T1, class T2>
// class Person
// {
// public:

// 	Person(T1 name, T2 age);
	
// 	void ShowPerson();

// 	T1 p_Name;
// 	T2 p_Age;
// };

// template<class T1, class T2>
// Person<T1, T2>::Person(T1 name, T2 age)
// {
// 	this->p_Name = name;
// 	this->p_Age = age;
// }

// template<class T1, class T2>
// void Person<T1, T2>::ShowPerson()
// {
// 	cout << "name:" << this->p_Name << " " << "age:" << this->p_Age << endl ;
// }

int main() 
{
	Person<string, int> p1("张三",18);
	p1.ShowPerson();
	system("cls");
	return 0;
}
	