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
	for(int i =0 ;i<5;i++)
	{
		v.push_back(i);
	}
	v.push_back(2);

	for_each(v.begin(),v.end(),MyPrint);
	cout << "打乱后：" << endl;
	random_shuffle(v.begin(),v.end());
	for_each(v.begin(),v.end(),MyPrint);
}

int main() 
{
	srand((unsigned int)time(NULL));
	test01();
	system("cls");
	return 0;
}