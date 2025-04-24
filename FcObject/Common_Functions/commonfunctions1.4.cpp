#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

class Person
{
public:
	Person(int age, string name)
	{
		this->p_Age = age;
		this->p_Name = name;
	}
	bool operator==(const Person &p)
	{
		if(this->p_Age == p.p_Age && this->p_Name == p.p_Name)
		{
			return true;
		}
	}

	int p_Age;
	string p_Name;
};

class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 1;
	}
};

class GreaterAge15
{
public:
	bool operator()(Person &p)
	{
		return p.p_Age > 15;
	}
};


void test01()
{
    vector<int>v;
	for(int i =0 ;i<5;i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());
	if(it == v.end())
	{
		cout << "没找到";
	}
	else
	{
		cout << "找到了，" << *it;
	}
}

void test02()
{
	vector<Person>v1;
	Person p1(15,"a");
	Person p2(16,"b");

	v1.push_back(p1);
	v1.push_back(p2);

	vector<Person>::iterator it = find_if(v1.begin(),v1.end(),GreaterAge15());
	if(it == v1.end())
	{
		cout << "没找到";
	}
	else
	{
		cout << "找到了，" << "年龄为：" << it->p_Age;
	}
}

int main() 
{
	// test01();
	test02();
	system("cls");
	return 0;
}