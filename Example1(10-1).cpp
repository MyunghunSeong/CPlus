#include <iostream>
#include "Example1_10_1.h"

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

Point Point :: operator-(const Point& p)
{
	Point tmp(x-p.x, y-p.y);
	return tmp;
}
