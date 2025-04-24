#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

void PrintV(int val)
{
	cout << val << " ";
}

class v_transform
{
public:
	int operator()(int v)
	{
		return v+100;
	}
};

void test01()
{
    vector<int>v;
	for(int i =0 ;i<5;i++)
	{
		v.push_back(i);
	}

	vector<int>vTarget;
	vTarget.resize(v.size());
	transform(v.begin(),v.end(),vTarget.begin(),v_transform());
	for_each(vTarget.begin(),vTarget.end(),PrintV);
}

int main() 
{
	test01();
	system("cls");
	return 0;
}