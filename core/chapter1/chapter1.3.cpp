#include <iostream>
using namespace std;

#define MAX 100

int b = 10; 

int main() 
{
	
	int a = 10;

	cout << &a << endl;
	cout << &b << endl;

	static int c = 10;
	cout << &c << endl;

	cout << &("Hello World") << endl;

	system("cls");
	return 0;
}
