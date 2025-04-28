#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include<algorithm>

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
    vector<int>v1;
	for(int i =0;i<10;i++)
	{
		v1.push_back(i);
	}

    vector<int>v2;
	for(int i =5;i<15;i++)
	{
		v2.push_back(i);
	}

	vector<int>vTarget;
	vTarget.resize(v1.size()+v2.size());

	for_each(v1.begin(),v1.end(),MyPrint());
	cout << endl;
	for_each(v2.begin(),v2.end(),MyPrint());
	cout << endl;
	
	cout << "并集后的结果：" << endl;
	vector<int>::iterator it = set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
	for_each(vTarget.begin(),it,MyPrint());
}

int main() 
{
	test01();
	system("cls");
	return 0;
}