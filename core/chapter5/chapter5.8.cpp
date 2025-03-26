#include <iostream>
using namespace std;

class Animal
{
public:
	// 虚函数
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "猫在说话" << endl;
	}
};

void DoSpeak(Animal & animal)
{
	animal.speak();
}

int main() 
{
	Cat cat;
	DoSpeak(cat);
	system("cls");
	return 0;
}
