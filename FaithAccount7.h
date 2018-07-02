#ifndef _FAITH_7_H_
#define _FAITH_7_H_

#include "Account7.h"

class FaithAccount : public Account
{
public:
	FaithAccount() {}
	FaithAccount(char* id, char* name, double balance);
	virtual void SetBalance(double balance);
	virtual void ShowAllData();
};
#endif