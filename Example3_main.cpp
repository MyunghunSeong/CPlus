#include <iostream>
#include "Example3_10_1.h"

using namespace std;

int main()
{
	Point p1(2, 1);
	Point p2(2, 1);

	p1 += p2;

	p1.ShowPosition();

	return 0;
}