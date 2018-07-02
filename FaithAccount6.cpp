#include <iostream>
#include "FaithAccount6.h"
using namespace std;

FaithAccount :: FaithAccount(char* id, char* name, double balance) : Account(id, name, balance)
{

}

void FaithAccount :: SetBalance(double balance)
{
	Account::SetBalance(balance += balance*0.01);
} 

void FaithAccount :: ShowAllData()
{
	Account::ShowAllData();
}