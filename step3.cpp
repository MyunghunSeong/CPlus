#include <iostream>
using namespace std;

class Account
{
	char* name;
	char* id;
	int balance;
public:
	Account(char* name, char* id, int balance);
	~Account();
	Account(const Account& a);
	char* GetName() const;
	char* GetId() const;
	int GetBalance() const;
	void SetBalance(int balance);
	void ShowData();
};

Account :: Account(char* name, char* id, int balance=0)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);

	this->balance = balance;
}

Account :: ~Account()
{
	delete [] name;
	delete [] id;
}

Account :: Account(const Account& a)
{
	this->name = new char[strlen(a.name) + 1];
	strcpy(this->name, a.name);

	this->id = new char[strlen(a.id) + 1];
	strcpy(this->id, a.id);

	this->balance = a.balance;
}

char* Account :: GetName() const
{
	return name;
}

char* Account :: GetId() const
{
	return id;
}

int Account :: GetBalance() const
{
	return balance;
}

void Account :: SetBalance(int balance)
{
	this->balance = balance;
}

//AccManager Class
class AccManager
{
	Account* acc[100];
	static int idx;
	int selection;
public:
	AccManager();
	~AccManager();
	void init();
	void create();
	void deposit();
	void withdraw();
	void select();
	void inner_select_Account(int& selection);
	int GetSelect();
};

AccManager :: AccManager()
{
	int selection = 0;
}

AccManager :: ~AccManager()
{
	for(int i = 0; i < idx; i++)
		delete [] acc;
}

int AccManager :: GetSelect() 
{
	return selection;
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

void AccManager :: inner_select_Account(int& select)
{
	cout << "==== ���� ����====" << endl;
	for(int i = 0; i < idx; i++)
	{
		cout << i+1 << ". " << "�̸�: " <<  acc[i]->GetName() << ' ' << "���� ��ȣ: " << acc[i]->GetId() << endl;
	}
	cin >> select;
	cout << endl;
}

void AccManager :: create()
{
	char name[30];
	char account[30];

	cout << "==== ���� ����====" << endl;
	cout << "�̸� �Է�: ";
	cin >> name;
	cout << "���� �Է�: ";
	cin >> account;
	cout << endl;

	acc[idx++] = new Account(name, account);
}

void AccManager :: deposit()
{
	int money = 0;
	int selection = 0;
	int balance = 0;

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

void AccManager :: withdraw()
{
	int money = 0;
	int selection = 0;
	int balance = 0;

	inner_select_Account(selection);

	cout << "==== ���� ���� ====" << endl;
	cout << "���� ��ȣ: " << acc[selection - 1]->GetId() << endl;
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

void AccManager :: select()
{
	cout << "==== ��ü �� �ܾ� ��ȸ ====" << endl;
	for(int i = 0; i < idx; i++)
	{
		cout << acc[i]->GetName() << " ������ ���� ����" << endl;
		cout << "���� ��ȣ: " << acc[i]->GetId() << endl;
		cout << "��     ��: " << acc[i]->GetBalance() << endl;
		cout << endl;
	}
	cout << endl;
}

int AccManager ::idx = 0;

enum 
{
	CREATE = 1,
	DEPOSIT = 2,
	WITHDRAW = 3,
	SEARCH = 4
};

int main()
{
	AccManager manager;

	while(true)
	{
		manager.init();

		switch(manager.GetSelect())
		{
		case CREATE:
			manager.create();
			break;
		case DEPOSIT:
			manager.deposit();
			break;
		case WITHDRAW:
			manager.withdraw();
			break;
		case SEARCH:
			manager.select();
			break;
		default:
			cout << "�߸� �Է��߾�" << endl;
			break;
		}


	}

	return 0;
}