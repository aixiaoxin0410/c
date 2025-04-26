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
	v.push_back(8);
	v.push_back(7);
	v.push_back(4);

	vector<int>v1;
	v1.resize(v.size());
	for_each(v.begin(),v.end(),MyPrint);
	cout << "拷贝结果：" << endl;
	copy(v.begin(),v.end(),v1.begin());
	for_each(v1.begin(),v1.end(),MyPrint);

}

int main() 
{
	test01();
	system("cls");
	return 0;
}