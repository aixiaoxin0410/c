#include <iostream>
#include <cmath>
using namespace std;

#include "./file_h/Circle.h"
#include "./file_h/Cdot.h"

int main() 
{
	Circle c1;
	c1.Setradius(5);
	c1.SetCenter(0, 0);
	Cdot c2;
	c2.Setxy(4, 0);

	int a =c2.calculatedis(c1, c2);
	c2.calculatepos(c1, a);

	system("cls");
	return 0;
}
