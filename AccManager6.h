#ifndef _ACCMANAGER_6_H
#define _ACCMANAGER_6_H

#include "Container6.h"
#include "FaithAccount6.h"
#include "ContriAccount6.h"
#include "Account6.h"

class AccManager
{
	Container ctr;
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