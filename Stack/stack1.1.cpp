#include<iostream>
using namespace std;
#include<stack>

void test01()
{
    stack<int>s;
    s.push(10);
    s.push(20);

    cout << "堆栈的大小为" << s.size() << endl;
    
    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    cout << "堆栈的大小为" << s.size() << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}