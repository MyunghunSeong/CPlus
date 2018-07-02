#include <iostream>
#include "AccManager6.h"

using namespace std;

AccManager :: ~AccManager()
{

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

	ctr.Insert(new Account(id, name, 0));
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

	ctr.Insert(new FaithAccount(id, name, 0));
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

	ctr.Insert(new ContriAccount(id, name, 0));
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
	int max = ctr.GetElementSum();

	for(int i = 0; i < max; i++)
	{
		Element acc = ctr.GetItem(i);
		cout << i+1 << ". " << "�̸�: " <<  acc->GetName() << ' ' << "���� ��ȣ: " << acc->GetBalance() << endl;
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
	cout << "���� ��ȣ: " << (ctr.GetItem(selection - 1))->GetId() << endl;
	cout << "��     ��: " <<  (ctr.GetItem(selection - 1))->GetBalance() << endl;

	cout << "==== �Ա� ====" << endl;
	cout << "�Ա� �ݾ� �Է�: ";
	cin >> money;

	balance =  (ctr.GetItem(selection - 1))->GetBalance() + money;

	ctr.GetItem(selection - 1)->SetBalance(balance);

	cout << "==== �Ա� �� �ܾ� ����====" << endl;
	cout << "��    ��: " <<  (ctr.GetItem(selection - 1))->GetBalance() << endl; 
	cout << endl;
}

void AccManager :: WithdrawAccount()
{
	int money = 0;
	int selection = 0;
	double balance = 0;

	inner_select_Account(selection);

	cout << "==== ���� ���� ====" << endl;
	cout << "���� ��ȣ: " <<  (ctr.GetItem(selection - 1))->GetId() << endl;
	cout << "��     ��: " <<  (ctr.GetItem(selection - 1))->GetBalance() << endl;

	cout << "==== ��� ====" << endl;
	cout << "��� �ݾ� �Է�: ";
	cin >> money;

	balance = (ctr.GetItem(selection - 1))->GetBalance()  + money;

	(ctr.GetItem(selection - 1))->SetBalance(balance);

	cout << "==== ��� �� �ܾ� ����====" << endl;
	cout << "��    ��: " << (ctr.GetItem(selection - 1))->GetBalance()  << endl; 
	cout << endl;
}

void AccManager :: SearchAccount()
{
	cout << "==== ��ü �� �ܾ� ��ȸ ====" << endl;
	int sum = ctr.GetElementSum();
	for(int i = 0; i < sum; i++)
	{
		Element acc = ctr.GetItem(i);
		acc->ShowAllData();
	}
	
	cout << endl;
} 


int AccManager :: GetSelection()
{
	return selection;
}
