#include <iostream>
using namespace std;

class Person
{
public:
    static int count;

    static void showCount()
    {
        count = 100;
        cout << "静态" << count << endl;
    }
};

int Person::count = 0;

int main() 
{
    Person p1;
    cout << Person::count << endl;
    p1.showCount();
    p1.count = 5;
    cout << p1.count << endl;

    system("cls");
    return 0;
}