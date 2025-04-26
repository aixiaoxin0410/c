#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

class Greater4
{
public:
	bool operator()(int val)
	{
		return val > 2;
	}

};

class Person
{
public:
	Person(string name, int age)
	{
		this->p_Age = age;
		this->p_name = name;
	}
	int p_Age;
	string p_name;
};

class P_Greater20
{
public:
	bool operator()(const Person &p)
	{
		return p.p_Age > 20;
	}

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
	int ret = count_if(v.begin(),v.end(),Greater4());
	cout << "大于2：" << ret << endl;
}

void test02()
{
	vector<Person> v;

	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	int ret1 = count_if(v.begin(),v.end(),P_Greater20());
	cout << "大于20：" << ret1 << endl;
}

int main() 
{
	test01();
	test02();
	system("cls");
	return 0;
}