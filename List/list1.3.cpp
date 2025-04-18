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
    list<int>L;
	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//头插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

    PrintList(L);

    L.pop_back();
    PrintList(L);

    L.pop_front();
    PrintList(L);

    list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	PrintList(L);
 
    L.erase(++it);
    PrintList(L);

    L.push_back(10000);
    L.push_back(10000);
	PrintList(L);
	L.remove(10000);//删除容器中所有与elem值匹配的元素。
	PrintList(L);

    L.clear();
	PrintList(L);
}

int main()
{
    test01();
    system("cls");
    return 0;
}