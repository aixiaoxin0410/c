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

    list<int>l2;
    l2.assign(6,22);
    PrintList(l2);

    cout << "交换后：" << endl;
    l1.swap(l2);
    PrintList(l1);
    PrintList(l2);

    cout << "L1的大小为： " << l1.size() << endl;

    //重新指定大小
	l1.resize(10);
	PrintList(l1);

    l1.resize(2);
	PrintList(l1);
    
}

int main()
{
    test01();
    system("pause");
    return 0;
}