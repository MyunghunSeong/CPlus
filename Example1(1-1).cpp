#include <iostream>
using namespace std;

int main()
{
	int number = 0;
	int sum = 0;

	for(int i = 0; i < 10; i++)
	{
		cout << "Input : ";
		cin >> number;
		sum += number;
	}

	cout << "Result : " << sum << endl;

	return 0;
}