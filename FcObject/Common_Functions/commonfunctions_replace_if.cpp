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

class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
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
	replace_if(v.begin(),v.end(),GreaterFive(),555);
	cout << endl;
	for_each(v.begin(),v.end(),MyPrint());
}

int main() 
{
	test01();
	system("cls");
	return 0;
}