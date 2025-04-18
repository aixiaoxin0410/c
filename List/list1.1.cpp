#include<iostream>
using namespace std;
#include<list>

void PrintList(const list<int> &l)
{
    for(list<int>::const_iterator it =  l.begin();it!= l.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);

    PrintList(l1);

    list<int>l2(l1.begin(),l1.end());
    PrintList(l2);

    list<int>l3(l2);
    PrintList(l3);

    list<int>l4(6,22);
    PrintList(l4);
}

int main()
{
    test01();
    system("pause");
    return 0;
}