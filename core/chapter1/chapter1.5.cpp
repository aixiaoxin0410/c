#include <iostream>
using namespace std;

int& test()
{
	static int a = 10;
	return a;
}

int main() 
{
	
	int& b = test();
	cout << b << endl;
	
	test()=1000;
	cout << b << endl;

	system("cls");
	return 0;
}
