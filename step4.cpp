#include <iostream>
using namespace std;


//Account Class
class Account
{
	char* id;
	char* name;
	double balance;
public:
	Account() : id(NULL), name(NULL), balance(0) {};
	Account(char* id, char* name, double balance);
	virtual ~Account();
	char* GetName();
	char* GetId();
	double GetBalance();
	virtual void SetBalance(double balance);
	virtual void ShowAllData();
};

Account :: Account(char* id, char* name, double balance=0)
{
	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->balance = balance;
}

Account :: ~Account()
{
	delete [] name;
	delete [] id;
}

void Account :: ShowAllData()
{
	cout << name << " ������ ���� ����" << endl;
	cout << "���� ��ȣ: " << id << endl;
	cout << "��     ��: " << balance << endl;
	cout << endl;
}

char* Account :: GetName()
{
	return name;
}

char* Account :: GetId()
{
	return id;
}

double Account :: GetBalance()
{
	return balance;
}

void Account :: SetBalance(double balance)
{
	this->balance = balance;
} //End of Accout Class Area

//FaithAccount Class
class FaithAccount : public Account
{
public:
	FaithAccount() {}
	FaithAccount(char* id, char* name, double balance) : Account(id, name, balance) {}
	virtual void SetBalance(double balance);
	virtual void ShowAllData();
};

void FaithAccount :: SetBalance(double balance)
{
	Account::SetBalance(balance += balance*0.01);

} 

void FaithAccount :: ShowAllData()
{
	Account::ShowAllData();
}//End of FaithAccount Class Area

//ContriAccount Class
class ContriAccount : public Account
{
	double contriMoney;
public:
	ContriAccount();
	ContriAccount(char* id, char* name, double balance) : Account(id, name, balance) {} 
	virtual void SetBalance(double balance);
	virtual void ShowAllData();
};

ContriAccount :: ContriAccount()
{
	contriMoney = 0;
}

void ContriAccount :: ShowAllData()
{
	Account::ShowAllData();
	cout << "��� �Ѿ� : " << contriMoney << endl; 
}

void ContriAccount :: SetBalance(double balance)
{
	contriMoney = balance * 0.01;
	Account::SetBalance(balance -= contriMoney);
}//End of ContriAccount Class Area

//AccManager Class
class AccManager
{
	Account* acc[100];
	static int idx;
	int selection;
public:
	AccManager() : selection(0) {};
	~AccManager();
	void inner_select_Account(int& selection);
	void init();
	void CreateAccount();
	void CreateNormalAccount();
	void CreateFaithAccount();
	void CreateContriAccount();
	void DepositAccount();
	void WithdrawAccount();
	void SearchAccount();
	void inner_SelectAccount(int& type);
	int GetSelection();
};

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

	acc[idx++] = new Account(name, id);
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
}//End of AccManager Class Area

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
			cout << "�߸� ������" << endl;
			break;
		}
	}
	return 0;
}