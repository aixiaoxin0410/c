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

	v.push_back(2);
	bool ret = binary_search(v.begin(),v.end(),4);
	if(ret)
	{
		cout << "找到了";
	}
	else
	{
		cout << "没找到";
	}

}

int main() 
{
	test01();
	system("cls");
	return 0;
}