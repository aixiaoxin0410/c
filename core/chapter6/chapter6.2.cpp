#include <iostream>
using namespace std;
#include<fstream>

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

int main() 
{
	ofstream fout;
	fout.open("file.txt",ios::out|ios::binary);
	Person p = {"张三", 18};
	fout.write((const char*)&p, sizeof(p));
	fout.close();

	ifstream fin;
	fin.read((char*)&p, sizeof(p));
	cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
	fout.close();

	system("cls");
	return 0;
}
