#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<ctime>

void MyPrint(int val)
{
	cout << val << " ";
}

void test01()
{
    vector<int>v;
	vector<int>v1;
	for(int i =0 ;i<5;i++)
	{
		v.push_back(i);
		v1.push_back(i+10);
	}
	vector<int>vTarget;
	vTarget.resize(v.size()+v1.size());
	merge(v.begin(),v.end(),v1.begin(),v1.end(),vTarget.begin());
	for_each(vTarget.begin(),vTarget.end(),MyPrint);
}

int main() 
{
	test01();
	system("cls");
	return 0;
}