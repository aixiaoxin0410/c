#include <iostream>
using namespace std;
#include<vector>

void PrintVector(vector<int>&v)
{
    for(vector<int>::iterator it = v.begin();it != v.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int>v1;
    for(int i = 0; i< 10;i++)
    {
        v1.push_back(i);
    } 
    // v1.resize(15);  //重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
    // v1.resize(15,10);  
    v1.resize(5);  //重新指定大小 ，若指定的更小，超出部分元素被删除
    PrintVector(v1);

    // if(v1.empty())
    // {
    //     cout << "v1为空" << endl;
    // }
    // else
    // {
    //     cout << "v1的大小为" << v1.size() << endl;
    //     cout << "v1的容量为" << v1.capacity() << endl;
    // }

    v1.insert(v1.begin(),2,5);
    PrintVector(v1);

    v1.erase(v1.begin());
    PrintVector(v1);

    v1.clear();
    PrintVector(v1);
}

int main()
{
    test01();

    system("cls");
    return 0;
}