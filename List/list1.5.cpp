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

//list降序排列
bool myCompare(int val1 , int val2)
{
	return val1 > val2;
}

void test01()
{
    list<int>L;
	//尾插
	L.push_back(40);
	L.push_back(20);
	L.push_back(400);
    L.push_back(30);
    L.push_back(50);

    cout << "反转" << endl;
    PrintList(L);
    L.reverse();
    PrintList(L);

    cout << "排序" << endl;
    PrintList(L);
    L.sort();
    PrintList(L);

    cout << "降序" << endl;
    PrintList(L);
    L.sort(myCompare);
    PrintList(L);
}

int main()
{
    test01();
    system("cls");
    return 0;
}