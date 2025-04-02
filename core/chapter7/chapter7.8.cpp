#include <iostream>
using namespace std;

template<class T>
class Person
{
public:
	T t;
};

class son:public Person<int>
{

};

//如果想灵活指定父类中T类型，子类也需要变类模板
template<class T1,class T2>
class son2:public Person<T2>
{
public:
	son2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	T1 obj;	
}; 

int main() 
{
	son s1;
	son2<int,char>s2;
	system("cls");

	return 0;
}
