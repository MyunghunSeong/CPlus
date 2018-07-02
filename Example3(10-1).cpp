#include <iostream>
#include "Example3_10_1.h"

using namespace std;

Point :: Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point :: ~Point() {}

void Point :: ShowPosition()
{
	cout << "XÁÂÇ¥ : " << x << ' ' << "YÁÂÇ¥ : " << y << endl;
}

Point Point :: operator+=(const Point& p)
{
	x += p.x;
	y += p.y;

	Point tmp(x, y);
	return tmp;
}