#include <iostream>
using namespace std;

template<class TypeName,class TypeAge=int>
class Person
{
public:
	Person(TypeName name,TypeAge age)
	{
		this->p_name = name;
		this->p_age = age;
	}

	void ShowPerson()
	{
		cout << "Name:" << this->p_name << " " << "Age:" << this->p_age << endl;	
	}

	TypeName p_name;
	TypeAge p_age;
};

//类模板在模板参数列表中可以有默认参数
void test()
{
	Person<string>p2("猪八戒",888);
	p2.ShowPerson();
}

int main() 
{
	Person<string,int> p1("孙悟空",999);
	p1.ShowPerson();
	test();
	system("cls");
	return 0;
}
