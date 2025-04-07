#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void myprint(int val)
{
    cout << val << endl;
}

void test01()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int>::iterator itbegin = v1.begin();
    vector<int>::iterator itend = v1.end();

    // while(itbegin != itend)
    // {
    //     cout << *itbegin << endl;
    //     itbegin++;
    // }

    // for(vector<int>::iterator it = v1.begin();it!=v1.end();it++)
    // {
    //     cout << *it << endl;
    // }

    for_each(v1.begin(),v1.end(),myprint);
}

int main()
{
    test01();

    system("cls");
    return 0;
}