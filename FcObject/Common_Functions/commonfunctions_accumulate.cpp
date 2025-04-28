#include<iostream>
using namespace std;
#include<vector>
#include<numeric>

void test01()
{
    vector<int>v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// 0 是起始累加值
	int count = accumulate(v.begin(),v.end(),0);
	cout << count << endl;
}

int main() 
{
	test01();
	system("cls");
	return 0;
}