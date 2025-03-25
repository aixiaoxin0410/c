#include <iostream>
using namespace std;

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Hertiage : public Base
{
public:
	int m_D;
};

void func()
{
	cout << sizeof(Hertiage) << endl;
}

int main() 
{
	Hertiage h;
	func();
	system("cls");
	return 0;
}
