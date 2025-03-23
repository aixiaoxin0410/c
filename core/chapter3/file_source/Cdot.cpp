#include "./file_h/Cdot.h"

void Cdot::Setxy(int x,int y)
{
	c_x = x;
	c_y = y;
}

int Cdot::Getx()
{
	return c_x;
}

int Cdot::Gety()
{
	return c_y;
}

double Cdot::calculatedis(Circle c1, Cdot c2)
{
	double distance_square = sqrt( pow( c2.Getx() - c1.GetCenterx(),2) + pow( c2.Gety() - c1.GetCentery(),2) );
	return distance_square;
}

void Cdot::calculatepos(Circle c1,int distance_square)
{
	if(distance_square > c1.Getradius())
	{
		cout << "The point is outside the circle." << endl;
	}
	else if(distance_square == c1.Getradius())
	{
		cout << "The point is on the circle." << endl;
	}
	else
	{
		cout << "The point is inside the circle." << endl;
	}
}
