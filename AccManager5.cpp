#include <iostream>
#include "AccManager5.h"
using namespace std;

int AccManager ::idx = 0;

AccManager :: ~AccManager()
{
	for(int i = 0;  i < idx; i++)
	{
		delete [] acc[i];
	}
}

void AccManager :: init()
{
	cout << "=====±â´É ¼±ÅÃ=====" << endl;
	cout << "1. °è    ÁÂ    °³   ¼³" << endl;
	cout << "2. ÀÔ               ±Ý" << endl;
	cout << "3. Ãâ               ±Ý" << endl;
	cout << "4. ÀüÃ¼ °í°´ ÀÜ¾× Á¶È¸" << endl;
	cout << "Input : ";
	cin >> selection;
	cout << endl;
}

void AccManager :: inner_SelectAccount(int& type)
{
	cout << "===== °èÁÂ ¼±ÅÃ=====" << endl;
	cout << "1. ÀÏ ¹Ý °è ÁÂ" << endl;
	cout << "2. ½Å ¿ë °è ÁÂ" << endl;
	cout << "3. ±â ºÎ °è ÁÂ" << endl;
	cin >> type;
	cout << endl;
}

void AccManager :: CreateNormalAccount()
{
	char name[30];
	char id[30];

	cout << "==== ÀÏ¹Ý °èÁÂ °³¼³====" << endl;
	cout << "ÀÌ¸§ ÀÔ·Â: ";
	cin >> name;
	cout << "°èÁÂ ÀÔ·Â: ";
	cin >> id;
	cout << endl;

	acc[idx++] = new Account(name, id, 0);
}

void AccManager :: CreateFaithAccount()
{
	char name[30];
	char id[30];

	cout << "==== ÀÏ¹Ý °èÁÂ °³¼³====" << endl;
	cout << "ÀÌ¸§ ÀÔ·Â: ";
	cin >> name;
	cout << "°èÁÂ ÀÔ·Â: ";
	cin >> id;
	cout << endl;

	acc[idx++] = new FaithAccount(name, id, 0);
}

void AccManager :: CreateContriAccount()
{
	char name[30];
	char id[30];

	cout << "==== ÀÏ¹Ý °èÁÂ °³¼³====" << endl;
	cout << "ÀÌ¸§ ÀÔ·Â: ";
	cin >> name;
	cout << "°èÁÂ ÀÔ·Â: ";
	cin >> id;
	cout << endl;

	acc[idx++] = new ContriAccount(name, id, 0);
}

void AccManager :: CreateAccount()
{
	int accountType = 0;
	inner_SelectAccount(accountType);

	switch(accountType)
	{
	case 1:
		CreateNormalAccount();
		break;
	case 2:
		CreateFaithAccount();
		break;
	case 3:
		CreateContriAccount();
		break;
	default:
		cout << "Àß¸ø ´­·¶¾û" << endl;
		break;
	}
}

void AccManager :: inner_select_Account(int& selection)
{
	cout << "==== °èÁÂ ¼±ÅÃ====" << endl;
	for(int i = 0; i < idx; i++)
	{
		cout << i+1 << ". " << "ÀÌ¸§: " <<  acc[i]->GetName() << ' ' << "°èÁÂ ¹øÈ£: " << acc[i]->GetId() << endl;
	}
	cin >> selection;
	cout << endl;
}

void AccManager :: DepositAccount()
{
	int money = 0;
	int selection = 0;
	double balance = 0;

	inner_select_Account(selection);

	cout << "==== °èÁÂ Á¤º¸ ====" << endl;
	cout << "°èÁÂ ¹øÈ£: " << acc[selection - 1]->GetId() << endl;
	cout << "ÀÜ     ¾×: " << acc[selection - 1]->GetBalance() << endl;

	cout << "==== ÀÔ±Ý ====" << endl;
	cout << "ÀÔ±Ý ±Ý¾× ÀÔ·Â: ";
	cin >> money;

	balance = acc[selection - 1]->GetBalance() + money;

	acc[selection - 1]->SetBalance(balance);

	cout << "==== ÀÔ±Ý ÈÄ ÀÜ¾× Á¤º¸====" << endl;
	cout << "ÀÜ    ¾×: " << acc[selection - 1]->GetBalance() << endl; 
	cout << endl;
}

void AccManager :: WithdrawAccount()
{
	int money = 0;
	int selection = 0;
	double balance = 0;

	inner_select_Account(selection);

	cout << "==== °èÁÂ Á¤º¸ ====" << endl;
	cout << "°èÁÂ ¹øÈ£: " << acc[selection - 1]->GetId() << endl;
	cout << "ÀÜ     ¾×: " << acc[selection - 1]->GetBalance() << endl;

	cout << "==== Ãâ±Ý ====" << endl;
	cout << "Ãâ±Ý ±Ý¾× ÀÔ·Â: ";
	cin >> money;

	balance = acc[selection - 1]->GetBalance() + money;

	acc[selection - 1]->SetBalance(balance);

	cout << "==== Ãâ±Ý ÈÄ ÀÜ¾× Á¤º¸====" << endl;
	cout << "ÀÜ    ¾×: " << acc[selection - 1]->GetBalance() << endl; 
	cout << endl;
}

void AccManager :: SearchAccount()
{
	cout << "==== ÀüÃ¼ °í°´ ÀÜ¾× Á¶È¸ ====" << endl;
	for(int i = 0; i < idx; i++)
	{
		acc[i]->ShowAllData();
	}
	cout << endl;
} 


int AccManager :: GetSelection()
{
	return selection;
}
