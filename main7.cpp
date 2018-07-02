#include <iostream>
#include "AccManager7.h"

using namespace std;

int main()
{
	AccManager manager;

	while(true)
	{
		manager.init();

		switch(manager.GetSelection())
		{
		case 1:
			manager.CreateAccount();
			break;
		case 2:
			manager.DepositAccount();
			break;
		case 3:
			manager.WithdrawAccount();
			break;
		case 4:
			manager.SearchAccount();
			break;
		default:
			cout << "Àß¸ø ´­·¶¾û" << endl;
			break;
		}
	}
	return 0;
}