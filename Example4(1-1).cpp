#include <iostream>
using namespace std;

int main()
{
	int selPrice = 0;
	int Money = 0;

	while(true)
	{
		cout << "판매 급액을 만원 단위로 입력(-1 to end): ";
		cin >> selPrice;

		if(selPrice == -1)
			break;

		Money = 50 + (selPrice * 0.12);

		cout << "이번 달 급여: " << Money << "만원" << endl;
	}

	return 0;
}