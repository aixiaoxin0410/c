#include <iostream>
using namespace std;


class Person
{
public:

	//构造函数
	Person()
	{
		cout << "Person()" << endl;
	}

	//析构函数
	~Person()
	{
		cout << "~Person()" << endl;
	}

};

void test01()
{
	Person p;
}

int main() 
{
	Person p;
	system("cls");
	return 0;
}
