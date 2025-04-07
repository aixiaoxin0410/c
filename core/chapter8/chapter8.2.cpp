#include <iostream>
using namespace std;
#include <vector>

class Person
{
public:

    Person(int age, string name)
    {
        this->p_Age = age;
        this->p_Name = name;
    }

    int p_Age;  
    string p_Name;
};

void test01()
{
    vector<Person>v;

    Person p1(11,"aa");
    Person p2(22,"bb");

    v.push_back(p1);
    v.push_back(p2);

    for(vector<Person>::iterator it = v.begin();it!= v.end();it++)
    {
        cout << "姓名：" << it->p_Name << " " << "年龄：" << it->p_Age << endl;
    }
}

void test02()
{
    vector<Person *>v;

    Person p1(11,"aa");
    Person p2(22,"bb");  
    
    v.push_back(&p1);
    v.push_back(&p2);

    for(vector<Person * >::iterator it = v.begin();it!= v.end();it++)
    {
        // cout << "::姓名：" << (*it)->p_Name << " " << "年龄：" << (*it)->p_Age << endl;
        cout << "**姓名：" << (**it).p_Name << " " << "年龄：" << (**it).p_Age << endl;
    }
}

int main()
{
    // test01();
    test02();
    system("cls");
    return 0;
}