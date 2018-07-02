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
	cout << "=====��� ����=====" << endl;
	cout << "1. ��    ��    ��   ��" << endl;
	cout << "2. ��               ��" << endl;
	cout << "3. ��               ��" << endl;
	cout << "4. ��ü �� �ܾ� ��ȸ" << endl;
	cout << "Input : ";
	cin >> selection;
	cout << endl;
}

void AccManager :: inner_SelectAccount(int& type)
{
	cout << "===== ���� ����=====" << endl;
	cout << "1. �� �� �� ��" << endl;
	cout << "2. �� �� �� ��" << endl;
	cout << "3. �� �� �� ��" << endl;
	cin >> type;
	cout << endl;
}

void AccManager :: CreateNormalAccount()
{
	char name[30];
	char id[30];

	cout << "==== �Ϲ� ���� ����====" << endl;
	cout << "�̸� �Է�: ";
	cin >> name;
	cout << "���� �Է�: ";
	cin >> id;
	cout << endl;

	acc[idx++] = new Account(name, id, 0);
}

void AccManager :: CreateFaithAccount()
{
	char name[30];
	char id[30];

	cout << "==== �Ϲ� ���� ����====" << endl;
	cout << "�̸� �Է�: ";
	cin >> name;
	cout << "���� �Է�: ";
	cin >> id;
	cout << endl;

	acc[idx++] = new FaithAccount(name, id, 0);
}

void AccManager :: CreateContriAccount()
{
	char name[30];
	char id[30];

	cout << "==== �Ϲ� ���� ����====" << endl;
	cout << "�̸� �Է�: ";
	cin >> name;
	cout << "���� �Է�: ";
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
		cout << "�߸� ������" << endl;
		break;
	}
}

void AccManager :: inner_select_Account(int& selection)
{
	cout << "==== ���� ����====" << endl;
	for(int i = 0; i < idx; i++)
	{
		cout << i+1 << ". " << "�̸�: " <<  acc[i]->GetName() << ' ' << "���� ��ȣ: " << acc[i]->GetId() << endl;
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

	cout << "==== ���� ���� ====" << endl;
	cout << "���� ��ȣ: " << acc[selection - 1]->GetId() << endl;
	cout << "��     ��: " << acc[selection - 1]->GetBalance() << endl;

	cout << "==== �Ա� ====" << endl;
	cout << "�Ա� �ݾ� �Է�: ";
	cin >> money;

	balance = acc[selection - 1]->GetBalance() + money;

	acc[selection - 1]->SetBalance(balance);

	cout << "==== �Ա� �� �ܾ� ����====" << endl;
	cout << "��    ��: " << acc[selection - 1]->GetBalance() << endl; 
	cout << endl;
}

void AccManager :: WithdrawAccount()
{
	int money = 0;
	int selection = 0;
	double balance = 0;

	inner_select_Account(selection);

	cout << "==== ���� ���� ====" << endl;
	cout << "���� ��ȣ: " << acc[selection - 1]->GetId() << endl;
	cout << "��     ��: " << acc[selection - 1]->GetBalance() << endl;

	cout << "==== ��� ====" << endl;
	cout << "��� �ݾ� �Է�: ";
	cin >> money;

	balance = acc[selection - 1]->GetBalance() + money;

	acc[selection - 1]->SetBalance(balance);

	cout << "==== ��� �� �ܾ� ����====" << endl;
	cout << "��    ��: " << acc[selection - 1]->GetBalance() << endl; 
	cout << endl;
}

void AccManager :: SearchAccount()
{
	cout << "==== ��ü �� �ܾ� ��ȸ ====" << endl;
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
