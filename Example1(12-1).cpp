#include <iostream>
using namespace std;

template <typename T>
class Point
{
public:
	int x;
	int y;
public:
	Point(int _x, int _y) : x(_x), y(_y) {};
	void ShowPosition();
	T Add(T a, T b);
};

template <typename T>
void Point<T> :: ShowPosition()
{
	cout << x << " " << y << endl;
}

template <typename T>
Point<T> Add(Point<T>& a, Point<T>& b)
{
	Point<T> tmp(a.x + b.x, b.y + b.y);
	return tmp;
}


int main()
{
	Point<int> p1(1,2);
	Point<int> p2(1,2);

	Point<int> p3=Add(p1, p2);
	p3.ShowPosition();

	return 0;
}