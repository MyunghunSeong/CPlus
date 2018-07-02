#ifndef _FAITH_5_H_
#define _FAITH_5_H_

#include "Account4.h"

class FaithAccount : public Account
{
public:
	FaithAccount() {}
	FaithAccount(char* id, char* name, double balance);
	virtual void SetBalance(double balance);
	virtual void ShowAllData();
};
#endif