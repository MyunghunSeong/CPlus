#include <iostream>
using namespace std;

class Account
{
private:
	char* account;
	char* name;
	int balance;
public:
	Account();
	Account(char* name, char* account, int balance);
	~Account() 
	{
		delete [] name;
		delete [] account;
	}
	char* GetName();
	char* GetAcc();
	void SetBalance(int balance);
	int GetBalance();
};

Account* acc[100];
int idx = 0;


Account::Account()
{
	balance = 0;
}

Account::Account(char* name, char* account, int balance=0)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->account = new char[strlen(account) + 1];
	strcpy(this->account, account);

	this->balance = balance;
}

char* Account :: GetName()
{
	return name;
}

char* Account :: GetAcc()
{
	return account;
}

int Account :: GetBalance()
{
	return balance;
}

void Account :: SetBalance(int balance)
{
	this->balance = balance;
}

void init(int& selection)
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

void create()
{
	char name[30];
	char account[30];

	cout << "==== °èÁÂ °³¼³====" << endl;
	cout << "ÀÌ¸§ ÀÔ·Â: ";
	cin >> name;
	cout << "°èÁÂ ÀÔ·Â: ";
	cin >> account;
	cout << endl;

	acc[idx] = new Account(name, account);

	idx++;

}

void inner_select_Account(int& select)
{
	cout << "==== °èÁÂ ¼±ÅÃ====" << endl;
	for(int i = 0; i < idx; i++)
	{
		cout << i+1 << ". " << "ÀÌ¸§: " <<  acc[i]->GetName() << ' ' << "°èÁÂ ¹øÈ£: " << acc[i]->GetAcc() << endl;
	}
	cout << "Input : ";
	cin >> select;
	cout << endl;
}

void deposit()
{
	int money = 0;
	int selection = 0;
	int balance = 0;

	inner_select_Account(selection);

	cout << "==== °èÁÂ Á¤º¸ ====" << endl;
	cout << "°èÁÂ ¹øÈ£: " << acc[selection - 1]->GetAcc() << endl;
	cout << "ÀÜ     ¾×: " << acc[selection - 1]->GetBalance() << endl;

	cout << "==== ÀÔ±Ý ====" << endl;
	cout << "ÀÔ±Ý ±Ý¾× ÀÔ·Â: ";
	cin >> money;
	cout << endl;

	balance = acc[selection - 1]->GetBalance() + money;

	acc[selection - 1]->SetBalance(balance);

	cout << "==== ÀÔ±Ý ÈÄ ÀÜ¾× Á¤º¸====" << endl;
	cout << "ÀÜ    ¾×: " << acc[selection - 1]->GetBalance() << endl;
	cout << endl;
}

void withdraw()
{
	int money = 0;
	int selection = 0;
	int balance = 0;

	inner_select_Account(selection);

	cout << "==== °èÁÂ Á¤º¸ ====" << endl;
	cout << "°èÁÂ ¹øÈ£: " << acc[selection - 1]->GetAcc() << endl;
	cout << "ÀÜ     ¾×: " << acc[selection - 1]->GetBalance() << endl;

	cout << "==== Ãâ±Ý ====" << endl;
	cout << "Ãâ±Ý ±Ý¾× ÀÔ·Â: ";
	cin >> money;

	balance = acc[selection - 1]->GetBalance() - money;

	acc[selection - 1]->SetBalance(balance);

	cout << "==== Ãâ±Ý ÈÄ ÀÜ¾× Á¤º¸====" << endl;
	cout << "ÀÜ    ¾×: " << acc[selection - 1]->GetBalance() << endl; 
	cout << endl;
}

void select()
{
	cout << "==== ÀüÃ¼ °í°´ ÀÜ¾× Á¶È¸ ====" << endl;
	for(int i = 0; i < idx; i++)
	{
		cout << acc[i]->GetName() << " °í°´´ÔÀÇ °èÁÂ Á¤º¸" << endl;
		cout << "°èÁÂ ¹øÈ£: " << acc[i]->GetAcc() << endl;
		cout << "ÀÜ     ¾×: " << acc[i]->GetBalance() << endl;
	}
	cout << endl;
}

int main()
{
	int selection = 0;

	while(true)
	{
		init(selection);

		switch(selection)
		{
		case 1:
			create();
			break;
		case 2:
			deposit();
			break;
		case 3:
			withdraw();
			break;
		case 4:
			select();
			break;
		default:
			cout << "Àß¸ø ÀÔ·ÂÇß¾î" << endl;
			break;
		}
	}



	return 0;
}