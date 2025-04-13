#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person()" << endl;
    }

    Person(int a,int height)
    {
        m_age = a;
        m_height = new int(height);
        cout << "Person(int a)" << endl;
    }

    Person(const Person &p)
    {
        m_age = p.m_age;
        m_height = new int(*p.m_height);
        cout << "Person(const Person &p)" << endl;
    }

    ~Person()
    {
        if(m_height != NULL)
        {
            delete m_height;
            m_height = NULL;
        }
        cout << "~Person()" << endl;
    }

    int m_age;
    int *m_height;
};

int main() 
{
    Person p1(10, 160);

    cout << "p1.m_age: " << p1.m_age << " " << "p1.m_height: " << *p1.m_height << endl;

    Person p2(p1);

    cout << "p2.m_age: " << p2.m_age << " " << "p2.m_height: " << *p2.m_height << endl;

    system("cls");
    return 0;
}