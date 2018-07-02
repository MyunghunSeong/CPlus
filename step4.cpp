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
	cout << name << " °í°´´ÔÀÇ °èÁÂ Á¤º¸" << endl;
	cout << "°èÁÂ ¹øÈ£: " << id << endl;
	cout << "ÀÜ     ¾×: " << balance << endl;
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
	cout << "±âºÎ ÃÑ¾× : " << contriMoney << endl; 
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

	acc[idx++] = new Account(name, id);
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
			cout << "Àß¸ø ´­·¶¾û" << endl;
			break;
		}
	}
	return 0;
}