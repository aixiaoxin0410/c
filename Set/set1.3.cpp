#include<iostream>
using namespace std;
#include<set>

void test01()
{
    set<int> st1;
    pair<set<int>::iterator, bool> set = st1.insert(10);
    if(set.second)
    {
        cout << "success" << endl;
    }
    else
    {
        cout << "fail" << endl;
    }

    set = st1.insert(10);
	if (set.second) 
    {
		cout << "第二次插入成功!" << endl;
	}
	else {
		cout << "第二次插入失败!" << endl;
	}

    multiset<int>ms;
    ms.insert(10);
    ms.insert(10);
    for(multiset<int>::iterator it = ms.begin(); it != ms.end();it++)
    {
        cout << *it << " ";
    }
}

void test02()
{
	pair<string, int> p("Tom", 20);
	cout << "姓名：" <<  p.first << " 年龄：" << p.second << endl;

    pair<string,int> p2 = make_pair("heart",30);
    cout << "姓名：" << p2.first << " 年龄：" << p2.second << endl;
}

int main()
{
    // test01();
    test02();
    system("cls");
    return 0;
}