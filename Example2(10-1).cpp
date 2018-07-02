#include <iostream>
#include "Example2_10_1.h"

using namespace std;

Point :: Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point :: ~Point() {}

void Point :: ShowPosition()
{
	cout << "X ÁÂÇ¥ : " << x << ' ' << "YÁÂÇ¥ : " << y << endl;
}

bool Point :: operator!=(const Point& p)
{
	if(p.x != x && p.y != y)
		return true;
	else
		return false;
}