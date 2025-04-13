#include <iostream>
using namespace std;
#include "Myarray.hpp"

void printintarray(Myarray<int> &arr)
{
	for(int i=0;i<arr.getsize();i++)
	{
		cout << arr[i] << endl;
	}
}

class Person
{
	
public:

	Person() : p_name(""), p_age(0) {} // 添加默认构造函数
	Person(string name,int age)
	{
		this->p_name = name;
		this->p_age = age;
	}

	// ~Person();

	string p_name;	
	int p_age;
};

void printPersonarray(Myarray<Person> &p)
{
	for(int i=0;i<p.getsize();i++)
	{
		cout << "姓名：" << p[i].p_name << " " << "年龄：" << p[i].p_age << endl;
	}
}

int main() 
{
	// Myarray<int>arr(5);
	// cout << "test" << endl;
	// Myarray<int>arr1(arr);
	// cout << "test" << endl;
	// Myarray<int>arr2(100);
	// arr2 = arr;
	// cout << "test" << endl;

	Myarray<int>arr(5);
	for(int i=0;i<5;i++)
	{
		arr.tail_insert(i);
	}
	cout << "arr容量为：" << arr.getcapacity() << " " << "arr大小为：" << arr.getsize() << endl;

	printintarray(arr);

	Myarray<int>arr1(arr);
	for(int i=0;i<5;i++)
	{
		arr.tail_insert(i);
	}
	cout << "arr1容量为：" << arr1.getcapacity() << " " << "arr1大小为：" << arr1.getsize() << endl;
	printintarray(arr1);

	arr1.tail_delete();
	cout << "arr1容量为：" << arr1.getcapacity() << " " << "arr1大小为：" << arr1.getsize() << endl;

	Myarray<Person>p(10);
	Person p1("aa",44);
	Person p2("bb",55);

	p.tail_insert(p1);
	p.tail_insert(p2);

	printPersonarray(p);
	cout << "p容量为：" << p.getcapacity() << " " << "p大小为：" << p.getsize() << endl;

	system("cls");
	return 0;
}
