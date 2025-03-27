#include <iostream>
using namespace std;
#include<fstream>


int main() 
{
	ofstream fout;
	fout.open("file.txt",ios::out);
	fout<<"hi World";
	fout.close();

	ifstream fin;
	fin.open("file.txt",ios::in);
	if(!fin.is_open())
	{
		cout<<"Error in opening file" << endl;
		return 0;
	}



    char buffer[255] = {0};

	//方法一
	// while(fin.getline(buffer, 255))
	// {
	// 	cout<<buffer<<endl;
	// }
	
	//方法二
	while (fin >> buffer)
	{
		cout << buffer << endl;
	}

	fin.close();
	system("cls");
	return 0;
}
