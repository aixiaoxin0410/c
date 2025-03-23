#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Circle
{
public:
	void Setradius(int r);

	int Getradius();

	void SetCenter(int x, int y);

	int GetCenterx();

	int GetCentery();

private:
	int radius;
	int center_x;
	int center_y;
};