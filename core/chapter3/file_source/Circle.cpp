#include "./file_h/Circle.h"

void Circle::Setradius(int r)
{
    radius = r;
}

int Circle::Getradius()
{
    return radius;
}

void Circle::SetCenter(int x, int y)
{
    center_x = x;
    center_y = y;
}

int Circle::GetCenterx()
{
    return center_x;
}

int Circle::GetCentery()
{
    return center_y;
}
