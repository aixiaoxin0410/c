#include <iostream>
using namespace std;

class Animal
{
public:
	
	virtual void speak() // 虚函数
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
