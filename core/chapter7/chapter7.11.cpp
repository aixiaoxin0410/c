#include <iostream>
using namespace std;

// 提前让编译器知道这个函数的存在
template<class T1, class T2>
class Person;


// 全局函数内外实现
template<class T1, class T2>
void printPerson1(Person<T1, T2> p)
{
	cout << "姓名：" << p.p_Name << " " << "年龄：" << p.p_Age << endl ;	
}


template<class T1, class T2>
class Person
{

	// friend void printPerson(Person<T1, T2> p)
	// {
	// 	cout << "姓名：" << p.p_Name << " " << "年龄：" << p.p_Age << endl ;
	// }

	friend void printPerson1<>(Person<T1, T2> p);

public:

	Person(T1 name, T2 age)
	{
		this->p_Name = name;
		this->p_Age = age;
	}
	
private:
	T1 p_Name;
	T2 p_Age;
};

int main() 
{
	Person<string, int> p1("张三",18);
	printPerson1(p1);
	system("cls");
	return 0;
}
	