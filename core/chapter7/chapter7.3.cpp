#include <iostream>
using namespace std;

// void myPrint(int a, int b)
// {
// 	cout << "调用的普通函数" << endl;
// }

void myPrint(int a, int b);

template<typename T>
void myPrint(T a, T b) 
{ 
	cout << "调用的模板" << endl;
}

int main() 
{
	int a = 10;
	int b = 20;
	
	//通过空模板参数列表，强制调用函数模板
	myPrint<>(a,b);

	system("cls");
	return 0;
}
