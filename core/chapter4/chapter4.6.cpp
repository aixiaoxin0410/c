#include <iostream>
using namespace std;

class Phone
{
public:
    int m_number;

    Phone()
    {
        cout << "Phone()" << endl;
    }

    Phone(int number)
    {
        m_number = number;
    }
};

class Person
{
public:
    int age;
    string m_name;
    Phone m_phone;

    Person(string name , int pnum)
    {
        m_name = name;
        m_phone.m_number = pnum;
        cout << "Person()" << endl;
    }
};

int main() 
{
    Person p1("John", 1234567890);

    cout << p1.m_phone.m_number << endl;

    cout << "p1.m_name: " << p1.m_name << endl;

    Phone p2(15156165);

    cout << p2.m_number << endl;

    cout << p1.m_phone.m_number << endl;

    system("cls");
    return 0;
}