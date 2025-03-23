#include <iostream>
using namespace std;

class student
{
public:
	string name;

	int id;

	void print()
	{
		cout << "Name: " << name << endl;
		cout << "ID: " << id << endl;
	}

	void setname(string nm)
	{
		name = nm;
		cout << "Name: " << name << endl;
	}
};

int main() 
{
	student s1;
	student s2;
	s1.name = "John Doe";
	s1.id = 123456;
	s1.print();
	s2.setname("张三");
	system("cls");
	return 0;
}
