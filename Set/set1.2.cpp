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
    // st1.erase(30);
    PrinsSet(st1);

    set<int>::iterator pos = st1.find(20);
    if(pos != st1.end())
    {
        cout << "找到了" << *pos <<endl;
    }
    else
    {
        cout << "没找到" << endl;
    }

    int num = st1.count(50);
    cout << "num = " << num << endl;
}

int main()
{
    test01();
    system("cls");
    return 0;
}