#include <iostream>
using namespace std;

template <typename T>
class Point
{
public:
	T x, y;
public:
	Point<T>(int _x = 0, int _y = 0) : x(_x), y(_y) {};
	~Point<T>() {}
	void ShowPosition();
	void Swap(Point<T>& p1, Point<T>& p2);
};

template <typename T>
void Point<T> :: ShowPosition()
{
	cout << x << '	' << y << endl;
}

template <typename T>
void Swap(Point<T>& p1, Point<T>& p2)
{
	Point<int> tmp;

	tmp.x = p1.x;
	p1.x = p2.x;
	p2.x = tmp.x;

	tmp.y = p1.y;
	p1.y = p2.y;
	p2.y = tmp.y;
}

template<typename T1> 
void Swap(T1& a, T1& b)
{
	T1 tmp;

	tmp = a;
	a = b;
	b = tmp;
}


int main()
{
	Point<int> p1(1,2);
	Point<int> p2(100, 200);

	Swap(p1, p2);
	p1.ShowPosition();
	p2.ShowPosition();

	int a = 10, b = 20;
	Swap(a, b);
	cout << a << '	' << b << endl;
	
	return 0;
}