#ifndef _ACCOUNT_6_H_
#define _ACCOUNT_6_H_

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

	Account& operator=(const Account& acc);
};

#endif