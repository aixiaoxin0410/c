#include<iostream>
using namespace std;

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }

};

void test01()
{
    MyAdd myadd;
    int a = myadd(20,30);
    cout << a << endl;
}

class MyPrint
{
public:
    MyPrint()
    {
        this->count = 0;
    }

    void operator()(string test)
    {
        cout << test << endl;
        this->count ++;
    }

    int count; 
};

void test02()
{
    MyPrint myprint;
    myprint("hello world");
    myprint("hello world");
    myprint("hello world");
    cout << myprint.count << endl;

}

//3、函数对象可以作为参数传递
void doPrint(MyPrint &mp , string test)
{
	mp(test);
}

void test03()
{
	MyPrint myPrint;
	doPrint(myPrint, "Hello C++");
}

int main()
{
    test01();
    test02();
    test03();
    system("cls");
    return 0;
}