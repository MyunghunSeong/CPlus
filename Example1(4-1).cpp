#include <iostream>
using namespace std;

class Rectangle
{
	private:
		int x, y;
	public:
		Rectangle(int x, int y);
		~Rectangle() {};
		double GetVolume();
		double GetArea();

};

class Circle
{
	private:
		int radius;
	public:
		Circle(int r);
		~Circle() {};
		double GetVolume();
		double GetArea();

};

Rectangle :: Rectangle(int x, int y)
{
	Rectangle::x = x;
	Rectangle::y = y;
}

Circle :: Circle(int r)
{
	radius = r;
}

double Rectangle :: GetArea()
{
	return (double)x*y;
}

double Rectangle :: GetVolume()
{
	return (double)(x*2) + (y*2);
}

double Circle :: GetArea()
{
	return (double)radius * radius * 3.14;
}

double Circle :: GetVolume()
{
	return (double)2 * radius * 3.14;
}

int main()
{
	Rectangle rec(3, 4);
	cout << "면적: " << rec.GetArea() << endl;
	cout << "둘레: " << rec.GetVolume() << endl;

	Circle cir(5);
	cout << "면적: " << cir.GetArea() << endl;
	cout << "둘레: " << cir.GetVolume() << endl;

	return 0;
}