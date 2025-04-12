#include <iostream>
using namespace std;
#include<vector>

void PrintVector(vector<int>&v)
{
    for(int i =0;i<v.size();i++)
    {
        cout << v[i] << " ";
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

    PrintVector(v1);
    cout << endl;

    cout << v1.front() << endl;
}

void test02()
{
    vector<int>v2;
    for(int i = 0; i< 10;i++)
    {
        v2.push_back(i+1);
    } 
    PrintVector(v2);
    
    vector<int>v3;
    for(int i = 10; i> 0;i--)
    {
        v3.push_back(i+1);
    } 
    PrintVector(v3); 

    v2.swap(v3);
    cout << "交换后：" << endl;
    PrintVector(v2);
    PrintVector(v3); 
}

void test03()
{
    vector<int>v4;
    for(int i =0;i<10000;i++)
    {
        v4.push_back(i);
    }

    v4.resize(3);
    cout << "大小：" << v4.size() << endl;
    cout << "容量：" << v4.capacity() << endl;

    vector<int>(v4).swap(v4);
    cout << "大小：" << v4.size() << endl;
    cout << "容量：" << v4.capacity() << endl;
}

int main()
{
    // test01();
    // test02();
    test03(); 
    system("cls");
    return 0;
}