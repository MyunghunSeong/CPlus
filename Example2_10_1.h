#ifndef _EXAMPLE2_10_1_H
#define _EXAMPLE2_10_1_H

class Point
{
	int x;
	int y;
public:
	Point(int x, int y);
	~Point();
	void ShowPosition();
	bool operator!=(const Point& p);
};

#endif