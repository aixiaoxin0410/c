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

    //cout << L1.at(0) << endl;//错误 不支持at访问数据
	//cout << L1[0] << endl; //错误  不支持[]方式访问数据
	cout << "第一个元素为： " << L.front() << endl;
	cout << "最后一个元素为： " << L.back() << endl;

    //list容器的迭代器是双向迭代器，不支持随机访问
	list<int>::iterator it = L.begin();
	//it = it + 1;//错误，不可以跳跃访问，即使是+1
}

int main()
{
    test01();
    system("cls");
    return 0;
}