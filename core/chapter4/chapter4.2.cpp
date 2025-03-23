#include <iostream>
using namespace std;

class Person 
{
public:
    //无参（默认）构造函数
    Person() {
        cout << "无参构造函数!" << endl;
    }
    //有参构造函数
    Person(int a) {
        age = a;
        cout << "有参构造函数!" << endl;
        cout << "age = " << age << endl;
    }
    //拷贝构造函数
    Person(const Person& p) {
        age = p.age;
        cout << "拷贝构造函数!" << endl;
        cout << "age1 = " << age << endl;
    }
    //析构函数
    ~Person() {
        cout << "析构函数!" << endl;
    }
    int age;
};


int main() {

    Person p1(10);
    Person p2(p1);
    system("pause");
    system("cls");
    return 0;
}