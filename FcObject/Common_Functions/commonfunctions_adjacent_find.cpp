#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

void test01()
{
    vector<int>v;
	for(int i =0 ;i<5;i++)
	{
		v.push_back(i);
	}

	v.push_back(3);

	vector<int>::iterator it = adjacent_find(v.begin(),v.end());
	if(it == v.end())
	{
		cout << "没找到";
	}
	else
	{
		cout << "找到了，" << *it;
	}
}

int main() 
{
	test01();
	system("cls");
	return 0;
}