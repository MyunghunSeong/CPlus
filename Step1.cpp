#include <iostream>
using namespace std;

struct Account
{
	char account[30];
	char name[30];
	int balance;
};

struct Account account[10];
static int Idx = 0;

void init_Account(int* select)
{
	cout << "=====±â´É ¼±ÅÃ=====" << endl;
	cout << "1. °è    ÁÂ    °³   ¼³" << endl;
	cout << "2. ÀÔ               ±Ý" << endl;
	cout << "3. Ãâ               ±Ý" << endl;
	cout << "4. ÀüÃ¼ °í°´ ÀÜ¾× Á¶È¸" << endl;
	cout << "Input : ";
	cin >> *select;
}

void inner_Create()
{
	cout << "==== °èÁÂ °³¼³====" << endl;
	cout << "ÀÌ¸§ ÀÔ·Â: ";
	cin >> account[Idx].name;
	cout << "°èÁÂ ÀÔ·Â: ";
	cin >> account[Idx].account;

	Idx++;
}

void inner_select_Account(int* select)
{
	cout << "==== °èÁÂ ¼±ÅÃ====" << endl;
	for(int i = 0; i < Idx; i++)
	{
		cout << i+1 << ". " << "ÀÌ¸§: " <<  account[i].name << ' ' << "°èÁÂ ¹øÈ£: " << account[i].account << endl;
	}
	cin >> *select;
}

void inner_Deposit()
{
	int money = 0;
	int selection = 0;

	inner_select_Account(&selection);

	cout << "==== °èÁÂ Á¤º¸ ====" << endl;
	cout << "°èÁÂ ¹øÈ£: " << account[selection - 1].account << endl;
	cout << "ÀÜ     ¾×: " << account[selection - 1].balance << endl;

	cout << "==== ÀÔ±Ý ====" << endl;
	cout << "ÀÔ±Ý ±Ý¾× ÀÔ·Â: ";
	cin >> money;

	account[selection - 1].balance += money;

	cout << "==== ÀÔ±Ý ÈÄ ÀÜ¾× Á¤º¸====" << endl;
	cout << "ÀÜ    ¾×: " << account[selection - 1].balance << endl; 
}

void inner_Withdraw()
{
	int money = 0;
	int selection = 0;

	inner_select_Account(&selection);

	cout << "==== °èÁÂ Á¤º¸ ====" << endl;
	cout << "°èÁÂ ¹øÈ£: " << account[selection - 1].account << endl;
	cout << "ÀÜ     ¾×: " << account[selection - 1].balance << endl;

	cout << "==== Ãâ±Ý ====" << endl;
	cout << "Ãâ±Ý ±Ý¾× ÀÔ·Â: ";
	cin >> money;

	account[selection - 1].balance -= money;

	cout << "==== Ãâ±Ý ÈÄ ÀÜ¾× Á¤º¸====" << endl;
	cout << "ÀÜ    ¾×: " << account[selection - 1].balance << endl; 
}

void inner_Search()
{
	cout << "==== ÀüÃ¼ °í°´ ÀÜ¾× Á¶È¸ ====" << endl;
	for(int i = 0; i < Idx; i++)
	{
		cout << account[i].name << " °í°´´ÔÀÇ °èÁÂ Á¤º¸" << endl;
		cout << "°èÁÂ ¹øÈ£: " << account[i].account << endl;
		cout << "ÀÜ     ¾×: " << account[i].balance << endl;
	}
}

void inner_Branch_Func(int* select)
{
	switch(*select)
	{
	case 1:
		inner_Create();
		break;
	case 2:
		inner_Deposit();
		break;
	case 3:
		inner_Withdraw();
		break;
	case 4:
		inner_Search();
		break;
	default:
		break;
	}
}

int main()
{
	int selection = 0;

	while(true)
	{
		init_Account(&selection);
	
		inner_Branch_Func(&selection);
	}

	return 0;
}