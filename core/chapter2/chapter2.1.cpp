#include <iostream>
using namespace std;

void func(int a ,int =10)
{
	cout << "hello" << endl;
}

int main() 
{
	func(10);
	
	system("cls");
	return 0;
}
