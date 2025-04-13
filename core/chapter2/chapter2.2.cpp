#include <iostream>
using namespace std;

void func()
{
	cout << "hello a" << endl;
}

void func(int a )
{
	cout << "int a" << endl;
}

void func(double a )
{
	cout << "double a" << endl;
}

void func(string a)
{
	cout << "string a" << endl;
}

int main() 
{
	func();
	func(10);
	func(10.5);
	func("a");
  	
	system("cls");
	return 0;
}
