#include <iostream>
using namespace std;

int main()
{
	int number = 0;

	while(true)
	{
		cout << "Input Number(����� -1�Է�): ";
		cin >> number;

		if(number == -1)
			break;

		for(int i = 1; i < 10; i++)
		{
			cout << number << " * " << i << " = " << number * i << endl;
		}
	}

	return 0;
}