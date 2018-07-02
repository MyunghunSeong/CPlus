#include <iostream>
using namespace std;


void swap(int* target, int* standard)
{
	int tmp;

	tmp = *target;
	*target = *standard;
	*standard = tmp;
}

void swap(char* target, char* standard)
{
	char tmp;

	tmp = *target;
	*target = *standard;
	*standard = tmp;
}

void swap(double* target, double* standard)
{
	double tmp;

	tmp = *target;
	*target = *standard;
	*standard = tmp;
}

int main()
{
	
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	cout << num1 << ' ' << num2 << endl;

	char ch1 = 'a', ch2 = 'z';
	swap(&ch1, &ch2);
	cout << ch1 << ' ' << ch2 << endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	cout << dbl1 << ' ' << dbl2 << endl;

	return 0;
}
