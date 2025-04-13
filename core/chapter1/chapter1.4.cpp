#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap1(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() 
{
	
	int a = 10;
	int b = 20;
 
	cout << "Before swap: " << a << " " << b << endl;
	// swap(a, b);
	// cout << "After swap: " << a << " " << b << endl;

	swap1(&a, &b);
	cout << "After swap1: " << a << " " << b << endl;

	system("cls");
	return 0;
}
