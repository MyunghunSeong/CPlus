#ifndef _ACCMANAGER_7_H
#define _ACCMANAGER_7_H

#include "Container7.h"
#include "FaithAccount7.h"
#include "ContriAccount7.h"
#include "Account6.h"

class AccManager
{
	Container<Account*> ctr;
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

#endif