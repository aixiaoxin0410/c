#include <iostream>
using namespace std;

class Person
{
public:
    int m_age;

    static int m_staticAge;

    void func()
    {
        cout << "func" << endl;
    }

    Person(int m_age)
    {
        this->m_age = m_age; // this is a pointer to the current object
    }

    Person& PersonAdd(Person &p)
    {
        this->m_age += p.m_age;
        return *this;
    }
};

int Person::m_staticAge = 0;

int main() 
{
    Person p1(10);
    cout << sizeof(p1) << endl;

    Person p2(20);
    p2.PersonAdd(p1).PersonAdd(p1).PersonAdd(p1);
    cout << p2.m_age << endl;

    cout << p1.m_age << endl;

    system("cls");
    return 0;
}