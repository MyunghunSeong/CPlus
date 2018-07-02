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
	cout << "=====±â´É ¼±ÅÃ=====" << endl;
	cout << "1. °è    ÁÂ    °³   ¼³" << endl;
	cout << "2. ÀÔ               ±Ý" << endl;
	cout << "3. Ãâ               ±Ý" << endl;
	cout << "4. ÀüÃ¼ °í°´ ÀÜ¾× Á¶È¸" << endl;
	cout << "Input : ";
	cin >> selection;
	cout << endl;
}

void AccManager :: inner_select_Account(int& select)
{
	cout << "==== °èÁÂ ¼±ÅÃ====" << endl;
	for(int i = 0; i < idx; i++)
	{
		cout << i+1 << ". " << "ÀÌ¸§: " <<  acc[i]->GetName() << ' ' << "°èÁÂ ¹øÈ£: " << acc[i]->GetId() << endl;
	}
	cin >> select;
	cout << endl;
}

void AccManager :: create()
{
	char name[30];
	char account[30];

	cout << "==== °èÁÂ °³¼³====" << endl;
	cout << "ÀÌ¸§ ÀÔ·Â: ";
	cin >> name;
	cout << "°èÁÂ ÀÔ·Â: ";
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

void AccManager :: withdraw()
{
	int money = 0;
	int selection = 0;
	int balance = 0;

	inner_select_Account(selection);

	cout << "==== °èÁÂ Á¤º¸ ====" << endl;
	cout << "°èÁÂ ¹øÈ£: " << acc[selection - 1]->GetId() << endl;
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

void AccManager :: select()
{
	cout << "==== ÀüÃ¼ °í°´ ÀÜ¾× Á¶È¸ ====" << endl;
	for(int i = 0; i < idx; i++)
	{
		cout << acc[i]->GetName() << " °í°´´ÔÀÇ °èÁÂ Á¤º¸" << endl;
		cout << "°èÁÂ ¹øÈ£: " << acc[i]->GetId() << endl;
		cout << "ÀÜ     ¾×: " << acc[i]->GetBalance() << endl;
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
			cout << "Àß¸ø ÀÔ·ÂÇß¾û" << endl;
			break;
		}


	}

	return 0;
}