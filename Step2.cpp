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
	cout << "=====��� ����=====" << endl;
	cout << "1. ��    ��    ��   ��" << endl;
	cout << "2. ��               ��" << endl;
	cout << "3. ��               ��" << endl;
	cout << "4. ��ü �� �ܾ� ��ȸ" << endl;
	cout << "Input : ";
	cin >> selection;
	cout << endl;
}

void create()
{
	char name[30];
	char account[30];

	cout << "==== ���� ����====" << endl;
	cout << "�̸� �Է�: ";
	cin >> name;
	cout << "���� �Է�: ";
	cin >> account;
	cout << endl;

	acc[idx] = new Account(name, account);

	idx++;

}

void inner_select_Account(int& select)
{
	cout << "==== ���� ����====" << endl;
	for(int i = 0; i < idx; i++)
	{
		cout << i+1 << ". " << "�̸�: " <<  acc[i]->GetName() << ' ' << "���� ��ȣ: " << acc[i]->GetAcc() << endl;
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

	cout << "==== ���� ���� ====" << endl;
	cout << "���� ��ȣ: " << acc[selection - 1]->GetAcc() << endl;
	cout << "��     ��: " << acc[selection - 1]->GetBalance() << endl;

	cout << "==== �Ա� ====" << endl;
	cout << "�Ա� �ݾ� �Է�: ";
	cin >> money;
	cout << endl;

	balance = acc[selection - 1]->GetBalance() + money;

	acc[selection - 1]->SetBalance(balance);

	cout << "==== �Ա� �� �ܾ� ����====" << endl;
	cout << "��    ��: " << acc[selection - 1]->GetBalance() << endl;
	cout << endl;
}

void withdraw()
{
	int money = 0;
	int selection = 0;
	int balance = 0;

	inner_select_Account(selection);

	cout << "==== ���� ���� ====" << endl;
	cout << "���� ��ȣ: " << acc[selection - 1]->GetAcc() << endl;
	cout << "��     ��: " << acc[selection - 1]->GetBalance() << endl;

	cout << "==== ��� ====" << endl;
	cout << "��� �ݾ� �Է�: ";
	cin >> money;

	balance = acc[selection - 1]->GetBalance() - money;

	acc[selection - 1]->SetBalance(balance);

	cout << "==== ��� �� �ܾ� ����====" << endl;
	cout << "��    ��: " << acc[selection - 1]->GetBalance() << endl; 
	cout << endl;
}

void select()
{
	cout << "==== ��ü �� �ܾ� ��ȸ ====" << endl;
	for(int i = 0; i < idx; i++)
	{
		cout << acc[i]->GetName() << " ������ ���� ����" << endl;
		cout << "���� ��ȣ: " << acc[i]->GetAcc() << endl;
		cout << "��     ��: " << acc[i]->GetBalance() << endl;
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
			cout << "�߸� �Է��߾�" << endl;
			break;
		}
	}



	return 0;
}