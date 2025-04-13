#include <iostream>
using namespace std;

class Person
{
	//friend ostream & operator<<(ostream &cout, Person &p);
public:

	int m_a;
	int m_b;

};

ostream & operator<<(ostream &cout, Person &p) 
{
	cout << p.m_b;
	return cout;
}

int main() 
{
	Person p1;
	p1.m_a = 10;
	p1.m_b = 10;

	cout << p1.m_a << endl;
	cout << p1 << endl;

	system("cls");
	return 0;
}
