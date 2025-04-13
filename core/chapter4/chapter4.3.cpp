#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person()" << endl;
    }

    Person(int a)
    {
        m_age = a;
        cout << "Person(int a)" << endl;
    }

    Person(const Person &p)
    {
        m_age = p.m_age;
        cout << "Person(const Person &p)" << endl;
        cout << "const m_age: " << m_age << endl;
    }

    int m_age;
};

int main() 
{
    Person p1;
    Person p2(10);
    Person p3(p2);

    system("cls");
    return 0;
}