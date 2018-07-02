#ifndef _EXAMPLE_10_1_H
#define _EXAMPLE_10_1_H

class Point
{
	int x;
	int y;
public:
	Point(int x, int y);
	~Point();
	void ShowPosition();
	Point operator-(const Point& p);
};

#endif