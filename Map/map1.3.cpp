#include<iostream>
using namespace std;
#include<set>
#include<map>

void PrintMap(map<int,int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int>m;
	m.insert(make_pair(10,10));
	m.insert(make_pair(20,20));
	m.insert(make_pair(30,30));
	PrintMap(m);
}

int main() 
{
	test01();
	system("cls");
	return 0;
}