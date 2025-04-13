#include <iostream>
using namespace std;

//注意：常对象只能调用常函数，不能调用普通函数
//常对象：对象前加const
//常函数：函数后加const

class Person
{
public:
    int m_age;
    mutable int m_number; //mutable在常对象和常函数中都可以修改

    void showclass()
    {
        cout << "Person class" << endl;
    }

    void showage()
    {
        if(this == NULL)
        {
            cout << "Object is NULL" << endl;
            return;
        }   
        cout << "Age: " << m_age << endl;
    }

    // This is a const function
    void showname() const
    {   
        m_number = 10; 
    }
};


int main() 
{
    Person *p1 = NULL;

    p1->showage();
    //p1->showclass(); // This will give error because p1 is NULL
    p1->showclass();

    system("cls");
    return 0;
}