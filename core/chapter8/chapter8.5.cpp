#include <iostream>
using namespace std;

void test01()
{
    string s1 = "去";
    s1 += "为权威的";
    cout << s1 << endl;

    string s2 = "球";
    s2.append(s1,0,6); //取“去为”，每个字符3字节，共6字节
    cout << s2 << endl;

}

int main()
{
    test01();
    system("cls");
    return 0;
}