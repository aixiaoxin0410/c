#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<algorithm>

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	sort(v.begin(),v.end(),greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin();it!= v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<bool>v2;
	v2.resize(v.size());
	cout << v2.size() << endl;
	transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin();it!= v2.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() 
{
	// test01();
	test02();
	system("cls");
	return 0;
}