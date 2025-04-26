#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

void Print01(int val)
{
	cout << val << " ";
}

//函数对象
class Print02 
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
	for(int i =0 ;i<5;i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(),v.end(),Print01);
	cout << endl;
	for_each(v.begin(),v.end(),Print02());
}

int main() 
{
	test01();
	system("cls");
	return 0;
}