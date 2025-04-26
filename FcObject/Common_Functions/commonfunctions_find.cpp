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

void test01()
{
    vector<int>v;
	for(int i =0 ;i<5;i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find(v.begin(),v.end(),5);
	if(it == v.end())
	{
		cout << "没找到";
	}
	else
	{
		cout << "找到了" << *it;
	}

}

void test02()
{
	vector<Person>v1;
	Person p1(15,"a");
	Person p2(16,"b");
	Person p3(17,"c");
	Person p4(18,"d");

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);

	Person pp(15,"a");

	vector<Person>::iterator it = find(v1.begin(),v1.end(),pp);
	if(it == v1.end())
	{
		cout << "没找到";
	}
	else
	{
		cout << "找到了," << "姓名：" << it->p_Name << " 年龄：" << it->p_Age << endl;
	}

}

int main() 
{
	// test01();
	test02();
	system("cls");
	return 0;
}