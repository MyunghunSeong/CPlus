#include <iostream>
#include "Example2_10_1.h"

using namespace std;

int main()
{
	Point p1(2, 1);
	Point p2(2, 1);
	Point p3(3, 3);

	if(p1 != p2)
		cout << "다르다!" << endl;
	else 
		cout << "같다!" << endl;

	if(p2 != p3)
		cout << "다르다!" << endl;
	else
		cout << "같다!" << endl;

	return 0;
}