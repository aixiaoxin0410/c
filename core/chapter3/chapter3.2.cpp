#include <iostream>
using namespace std;

class Person
{
public:
	int m_name;

	void display()
	{
		cout << "Name: " << m_name << endl;
		cout << "Age: " << m_age << endl;
	}

	void setSalary(int salary)
	{
		if(salary < 2000)
		{
			cout << "Salary can't be negative" << endl;
			return;
		}
		m_salary = salary;
	}

protected:
	int m_age = 10;

private:
	int m_salary;
};


int main() 
{
	Person p1;
	p1.m_name = 10;
	p1.display();
	p1.setSalary(1000);
	system("cls");
	return 0;
}
