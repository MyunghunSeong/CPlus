#include <iostream>

using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

class Point
{
private:
	int x, y;
public:
	Point() : x(0), y(0) {};
	Point(int _x, int _y) : x(_x), y(_y) {};
	friend istream& operator>>(istream& is, Point& p);
	friend ostream& operator<<(ostream& os, const Point p);
};

istream& operator>>(istream& is, Point& p)
{
	is >> p.x >> p.y;
	return is;
}

ostream& operator<<(ostream& os, const Point p)
{
	os << "[" << p.x << ", " << p.y << "]" << endl;
	return os;
}

int main()
{
	Point p;
	cout << p;

	cout << "x, y ют╥б : ";
	cin >> p;
	cout << p;

	return 0;
}
