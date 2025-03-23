#include <iostream>
using namespace std;

int * func()
{
	int *p=new int(10);
	return p;
}

void test()
{
	int *p=func();
	*p=20;
	cout<<*p<<endl;
	delete p;
}

int main() 
{
	int *q=func();
	cout<<*q<<endl;
	test();
	system("cls");
	return 0;
}
