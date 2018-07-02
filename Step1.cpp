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
	cout << "=====��� ����=====" << endl;
	cout << "1. ��    ��    ��   ��" << endl;
	cout << "2. ��               ��" << endl;
	cout << "3. ��               ��" << endl;
	cout << "4. ��ü �� �ܾ� ��ȸ" << endl;
	cout << "Input : ";
	cin >> *select;
}

void inner_Create()
{
	cout << "==== ���� ����====" << endl;
	cout << "�̸� �Է�: ";
	cin >> account[Idx].name;
	cout << "���� �Է�: ";
	cin >> account[Idx].account;

	Idx++;
}

void inner_select_Account(int* select)
{
	cout << "==== ���� ����====" << endl;
	for(int i = 0; i < Idx; i++)
	{
		cout << i+1 << ". " << "�̸�: " <<  account[i].name << ' ' << "���� ��ȣ: " << account[i].account << endl;
	}
	cin >> *select;
}

void inner_Deposit()
{
	int money = 0;
	int selection = 0;

	inner_select_Account(&selection);

	cout << "==== ���� ���� ====" << endl;
	cout << "���� ��ȣ: " << account[selection - 1].account << endl;
	cout << "��     ��: " << account[selection - 1].balance << endl;

	cout << "==== �Ա� ====" << endl;
	cout << "�Ա� �ݾ� �Է�: ";
	cin >> money;

	account[selection - 1].balance += money;

	cout << "==== �Ա� �� �ܾ� ����====" << endl;
	cout << "��    ��: " << account[selection - 1].balance << endl; 
}

void inner_Withdraw()
{
	int money = 0;
	int selection = 0;

	inner_select_Account(&selection);

	cout << "==== ���� ���� ====" << endl;
	cout << "���� ��ȣ: " << account[selection - 1].account << endl;
	cout << "��     ��: " << account[selection - 1].balance << endl;

	cout << "==== ��� ====" << endl;
	cout << "��� �ݾ� �Է�: ";
	cin >> money;

	account[selection - 1].balance -= money;

	cout << "==== ��� �� �ܾ� ����====" << endl;
	cout << "��    ��: " << account[selection - 1].balance << endl; 
}

void inner_Search()
{
	cout << "==== ��ü �� �ܾ� ��ȸ ====" << endl;
	for(int i = 0; i < Idx; i++)
	{
		cout << account[i].name << " ������ ���� ����" << endl;
		cout << "���� ��ȣ: " << account[i].account << endl;
		cout << "��     ��: " << account[i].balance << endl;
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