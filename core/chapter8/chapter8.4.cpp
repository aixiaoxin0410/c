#include <iostream>
using namespace std;

void test01()
{
    string s1;
    const char * str = "hello world";
    string s2(str);  
    cout << "S2 = " << s2 << endl;
    string s3(s2);
    cout << "S3 = " << s3 << endl;
    string s4(5,'a');
    cout << "S4 = " << s4 << endl;

    string s5;
    // s5 = 'a'; //'' 只能输入一个字符，多余的算最后一个
    // cout << "S5 = " << s5 << endl;

    string s6;
    s6.assign("hello c++");
    cout << "S6 = " << s6 << endl;

    string s7;
    s7.assign("hello s13",2);
    cout << "S7 = " << s7 << endl;

}

int main()
{
    test01();
    system("cls");
    return 0;
}