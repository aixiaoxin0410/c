#include <iostream>
using namespace std;

class circle
{
public:
	int radius;

	double calczc()
	{
		return 2 * 3.14 * radius;
	}

};

int main() 
{
	circle c1;
	c1.radius = 10;

	cout << "The circumference of the circle is: " << c1.calczc() << endl;
	system("cls");
	return 0;
}
