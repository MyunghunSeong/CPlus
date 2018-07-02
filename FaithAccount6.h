#ifndef _FAITH_6_H_
#define _FAITH_6_H_

#include "Account6.h"

class FaithAccount : public Account
{
public:
	FaithAccount() {}
	FaithAccount(char* id, char* name, double balance);
	virtual void SetBalance(double balance);
	virtual void ShowAllData();
};
#endif