#ifndef _EXAMPLE3_10_1_H_
#define _EXAMPLE3_10_1_H_

class Point
{
	int x;
	int y;
public:
	Point(int x, int y);
	~Point();
	void ShowPosition();
	Point operator+=(const Point& p);
};

#endif