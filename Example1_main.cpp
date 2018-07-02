#include <iostream>
#include "Example1_10_1.h"

using namespace std;

int main()
{
	Point p1(4, 2);
	Point p2(2, 1);
	Point p3 = p1-p2;
	p3.ShowPosition();

	return 0;
}