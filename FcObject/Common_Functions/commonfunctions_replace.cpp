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

	v.push_back(1);
	v.push_back(1);
	v.push_back(8);
	v.push_back(7);
	v.push_back(4);

	for_each(v.begin(),v.end(),MyPrint);
	replace(v.begin(),v.end(),1,111);
	cout << endl;
	for_each(v.begin(),v.end(),MyPrint);
}

int main() 
{
	test01();
	system("cls");
	return 0;
}