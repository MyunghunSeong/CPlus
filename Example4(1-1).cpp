#include <iostream>
using namespace std;

int main()
{
	int selPrice = 0;
	int Money = 0;

	while(true)
	{
		cout << "�Ǹ� �޾��� ���� ������ �Է�(-1 to end): ";
		cin >> selPrice;

		if(selPrice == -1)
			break;

		Money = 50 + (selPrice * 0.12);

		cout << "�̹� �� �޿�: " << Money << "����" << endl;
	}

	return 0;
}