#pragma once
#include<iostream>
using namespace std;

template<class T1, class T2>
class Person
{
public:

	Person(T1 name, T2 age);
	
	void ShowPerson();

	T1 p_Name;
	T2 p_Age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->p_Name = name;
	this->p_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::ShowPerson()
{
	cout << "name:" << this->p_Name << " " << "age:" << this->p_Age << endl ;
}
