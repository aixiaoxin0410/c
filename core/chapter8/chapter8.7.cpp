#include <iostream>
using namespace std;

void test01()
{
    string s1 = "hello";
    for(int i = 0 ; i < s1.size() ; i++)
    {
        cout << s1[i] ;
    }

    cout << endl;

    for(int i = 0 ; i < s1.size() ; i++)
    {
        cout << s1.at(i) ;
    }

    cout << endl;

    s1.erase(0,2);
    cout << s1 << endl;

    string s2 = "hello world";
    string s3 = s2.substr(1,3);
    cout << s3 << endl;

    string s4 = "zhangsan@email.com";
    int s44 = s4.find("@");
    string ename = s4.substr(0,s44);
    cout << ename << endl;

}

int main()
{
    test01();
    system("cls");
    return 0;
}