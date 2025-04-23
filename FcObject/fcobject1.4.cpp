#include<iostream>
using namespace std;
#include<functional>

void test01()
{
	negate<int>n;
	cout << n(1) << endl;

	plus<int>p;
	cout << p(10,10) << endl;
}

int main() 
{
	test01();
	system("cls");
	return 0;
}