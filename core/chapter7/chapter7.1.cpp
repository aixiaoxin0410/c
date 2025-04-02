#include <iostream>
using namespace std;
template <typename T>  //声明函数模板

void MySwap(T &a, T &b) 
{
	T temp = a;
	a = b;
	b = temp;
}


int main() 
{
	//使用模板函数交换两个变量的值

	int a = 5, b = 10;
	cout << "Before swap: a = " << a << ", b = " << b << endl;
	// MySwap(a,b);
	swap(a,b);
	cout << "After swap: a = " << a << ", b = " << b << endl;
	system("cls");
	return 0;
}
