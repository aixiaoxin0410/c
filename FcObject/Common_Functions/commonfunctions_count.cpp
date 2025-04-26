#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

class Person
{
public:
	Person(string name, int age)
	{
		this->p_Age = age;
		this->p_name = name;
	}

	bool operator==(const Person &p)
	{
		if(this->p_Age == p.p_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int p_Age;
	string p_name;
};

void test01()
{
    vector<int>v;
	for(int i =0 ;i<5;i++)
	{
		v.push_back(i);
	}

	v.push_back(2);
	v.push_back(2);
	v.push_back(2);

	int num = count(v.begin(),v.end(),1);
	cout << num;
}

void test02()
{
	vector<Person> v;

	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("曹操", 25);

	Person p("a",20);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	int num1 = count(v.begin(),v.end(),p);
	cout << num1 << endl;
}

int main() 
{
	// test01();
	test02();
	system("cls");
	return 0;
}