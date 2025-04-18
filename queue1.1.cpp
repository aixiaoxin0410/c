#include<iostream>
using namespace std;
#include<queue>

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void test01()
{
    queue<Person>q;

    //准备数据
	Person p1("唐僧", 30);
	Person p2("孙悟空", 1000);
    Person p3("猪八戒", 900);
	Person p4("沙僧", 800);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    cout << "堆栈的大小为" << q.size() << endl;
    
    while(!q.empty())
    {
        cout << "姓名：" << q.front().m_Name <<" " << "年龄：" << q.front().m_Age << endl;//队头
        cout << "姓名：" << q.back().m_Name <<" " << "年龄：" << q.back().m_Age << endl;//队尾
        q.pop();
    }

    cout << "堆栈的大小为" << q.size() << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}