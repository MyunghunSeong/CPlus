#include <iostream>
#include "Example2_10_1.h"

using namespace std;

int main()
{
	Point p1(2, 1);
	Point p2(2, 1);
	Point p3(3, 3);

	if(p1 != p2)
		cout << "�ٸ���!" << endl;
	else 
		cout << "����!" << endl;

	if(p2 != p3)
		cout << "�ٸ���!" << endl;
	else
		cout << "����!" << endl;

	return 0;
}