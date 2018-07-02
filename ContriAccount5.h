#ifndef _CONTRI_5_H
#define _CONTRI_5_H

#include "Account5.h"

class ContriAccount : public Account
{
	double contriMoney;
public:
	ContriAccount();
	ContriAccount(char* id, char* name, double balance); 
	virtual void SetBalance(double balance);
	virtual void ShowAllData();
};

#endif