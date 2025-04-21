#include<iostream>
using namespace std;
#include<set>
#include<map>

void PrintMap(map<int,int>&m)
{
    for(map<int,int>::iterator it = m.begin();it!=m.end();it++)
    {
        cout << "Key：" << (*it).first << " " << "Value："  << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    map<int,int>m1;
    m1.insert(pair<int,int>(15,10));
    m1.insert(pair<int,int>(4,14.5));
    m1.insert(pair<int,int>(2,1));
    PrintMap(m1);
}

int main()
{
    test01();
    system("cls");
    return 0;
}