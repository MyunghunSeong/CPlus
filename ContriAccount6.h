#ifndef _CONTRI_6_H
#define _CONTRI_6_H

#include "Account6.h"

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