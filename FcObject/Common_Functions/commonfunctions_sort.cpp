#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

void MyPrint(int val)
{
	cout << val << " ";
}

void test01()
{
    vector<int>v;
	for(int i =0 ;i<5;i++)
	{
		v.push_back(i);
	}
	v.push_back(2);

	// sort(v.begin(),v.end());
	// for_each(v.begin(),v.end(),MyPrint);

	sort(v.begin(),v.end(),greater<int>());
	for_each(v.begin(),v.end(),MyPrint);
}

int main() 
{
	test01();
	system("cls");
	return 0;
}