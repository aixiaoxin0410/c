#include <iostream>
using namespace std;

class Base
{
public:
    virtual void func() = 0;
};

class Base1 : public Base
{
public:
    virtual void func()
    {
        cout << "Base1::func()" << endl;
    };
};

int main() 
{
    // Base b; // error: cannot declare variable 'b' to be of abstract type 'Base'
    Base *base = new Base1;
    base->func();
    delete base;
    system("cls");
    return 0;
}