#include <iostream>
#include "ContriAccount5.h";

using namespace std;

ContriAccount :: ContriAccount(char* id, char* name, double balance) : Account(id, name, balance)
{
	contriMoney = 0;
}

void ContriAccount :: ShowAllData()
{
	Account::ShowAllData();
	cout << "±âºÎ ÃÑ¾× : " << contriMoney << endl; 
}

void ContriAccount :: SetBalance(double balance)
{
	contriMoney = balance * 0.01;
	Account::SetBalance(balance -= contriMoney);
}