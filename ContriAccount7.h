#ifndef _CONTRI_7_H
#define _CONTRI_7_H

#include "Account7.h"

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