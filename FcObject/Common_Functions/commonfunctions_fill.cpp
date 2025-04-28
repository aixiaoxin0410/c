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
    vector<int>v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// 0 是起始累加值
	fill(v.begin(),v.end(),100);
	for_each(v.begin(),v.end(),MyPrint());

}

int main() 
{
	test01();
	system("cls");
	return 0;
}