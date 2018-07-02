#include <iostream>
using namespace std;

const double PI = 3.14;

class Point
{
protected:
	int x, y;
public:
	Point();
	Point(int x, int y);
};

Point :: Point() 
{
	x = 0;
	y = 0;
}

Point :: Point(int x, int y)
{
	this->x = x;
	this->y = y;
}


//Circle Class
class Circle : public Point
{
	double radius;
	Point p;
public:
	Circle();
	Circle(int x, int y, double radius) : Point(x, y)
	{
		this->radius = radius;
	}
	void showData();
};

Circle :: Circle()
{
	radius = 0;
}

void Circle :: showData()
{
	cout << "�߽� ��ǥ: " << "[" << x << "," << y << "]" << endl;
	cout << "������: " << radius << endl;
	cout << "���� ����: " << radius * radius * PI << endl;
}

int main()
{
	Circle cir(3, 5, 2.2);
	cir.showData();

	return 0;
}