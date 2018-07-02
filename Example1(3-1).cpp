#include <iostream>
using namespace std;

class Calculator
{
	private:
		int num1, num2;
		int addCount, subCount, mulCount, divCount;

	public:
		void Init();
		void ShowOpCount();
		int Add(int num1, int num2);
		int Sub(int num1, int num2);
		int Mul(int num1, int num2);
		double Div(int num1, int num2);
};

void Calculator :: Init()
{
	num1 = 0;
	num2 = 0;
	addCount = 0;
	subCount = 0;
	mulCount = 0;
	divCount = 0;
}

void Calculator :: ShowOpCount()
{
	cout << "ADD = " << addCount << endl;
	cout << "SUB = " << subCount << endl;
	cout << "MUL = " << mulCount << endl;
	cout << "DIV = " << divCount << endl;
}

int Calculator :: Add(int num1, int num2)
{
	return num1 + num2;
	addCount++;
}

int Calculator :: Sub(int num1, int num2)
{
	return num1 - num2;
	subCount++;
}

int Calculator :: Mul(int num1, int num2)
{
	return num1 * num2;
	mulCount++;
}

double Calculator :: Div(int num1, int num2)
{
	if(num1 == 0 || num2 == 0)
		cout << "Not Divied to zero!";
	else
	{
		return (double)num1 / num2;
		divCount++;
	}
}

int main()
{
	Calculator cal;
	cal.Init();

	cout << "3+5= " << cal.Add(3, 5) << endl;
	cout << "3/5= " << cal.Div(3, 5) << endl;
	cout << "12-4 " << cal.Sub(12, 4) << endl;
	cout << "12/4 " << cal.Div(12, 4) << endl;

	return 0;
}