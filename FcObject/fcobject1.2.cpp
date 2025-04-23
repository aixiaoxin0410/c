#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

struct GreaterFive
{
	bool operator()(int val) 
    {
		return val > 4;
	}
};

void test01()
{
    vector<int>v;
    for(int i =0 ;i <5;i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());
    if(it == v.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << "找到了 " << *it << endl;
    }
}

int main()
{
    test01();
    system("cls");
    return 0;
}