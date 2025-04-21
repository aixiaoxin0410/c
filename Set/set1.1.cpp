#include<iostream>
using namespace std;
#include<set>

void PrinsSet(set<int>st)
{
    for(set<int>::iterator it = st.begin(); it!=st.end();it++)
    {
        cout << *it << " ";
    }
}

void test01()
{
    set<int> st1;
    st1.insert(10);
    st1.insert(30);
    st1.insert(20);
    st1.insert(30);
    PrinsSet(st1);

    if(!st1.empty())
    {
        cout << "容器不为空" << " ";
        cout << "容器的大小" << st1.size() << endl;
    }
    else
    {
        cout << "容器为空" << endl;
    }
    
    set<int>st2;
    st2.insert(101);
    st2.insert(301);
    st2.insert(201);
    st2.insert(301);
    PrinsSet(st2);

    cout << "交换后：" << endl;
    st1.swap(st2);

    PrinsSet(st1);
    PrinsSet(st2);
}

int main()
{
    test01();
    system("cls");
    return 0;
}