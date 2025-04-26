#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}

};

void test01()
{
    vector<int>v;

	v.push_back(11);
	v.push_back(8);
	v.push_back(7);
	v.push_back(4);
	for_each(v.begin(),v.end(),MyPrint());
	cout << endl;
	vector<int>v1;
	v1.push_back(111);
	v1.push_back(81);
	v1.push_back(71);
	v1.push_back(41);
	for_each(v1.begin(),v1.end(),MyPrint());
	cout << endl;
	cout << "交换后：" << endl;

	swap(v,v1);
	for_each(v.begin(),v.end(),MyPrint());
	cout << endl;
	for_each(v1.begin(),v1.end(),MyPrint());
}

int main() 
{
	test01();
	system("cls");
	return 0;
}