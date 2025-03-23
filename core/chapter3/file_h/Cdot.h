#pragma once
#include <iostream>
using namespace std;
#include "./file_h/Circle.h"

class Cdot
{
public:

	void Setxy(int x,int y);

	int Getx();

	int Gety();

	double calculatedis(Circle c1, Cdot c2);

	void calculatepos(Circle c1,int distance_square);

private:
	int c_x;
	int c_y;
};