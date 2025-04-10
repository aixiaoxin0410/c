#include <iostream>
using namespace std;

void test01()
{
    string s1 = "aosidjhoaidwaos";
    int s11 = s1.find("o"); //从左往右查找
    cout << s11 << endl;

    int s111 = s1.rfind("aos");
    cout << s111 << endl; //从右往左查找

    string s2 = "iuhqwd";
    s2.replace(1,3,"1111");
    cout << s2 << endl;

    string s3 = "asdf";
    string s4 = "bsdf";
    int s34 = s3.compare(s4);
    if(s34 > 0)
    {
        cout << "不相等,且大于" << endl;
    }
    else if (s34 == 0)
    {
        cout << "相等" << endl;
    }
    else
    {
        cout << "不相等，且小于" << endl;
    }
}

int main()
{
    test01();
    system("cls");
    return 0;
}