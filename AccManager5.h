#ifndef _ACCMANAGER_5_H
#define _ACCMANAGER_5_H

#include "Account5.h"
#include "FaithAccount5.h"
#include "ContriAccount5.h"

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

#endif