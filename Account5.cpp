#include <iostream>
#include "Account5.h"
using namespace std;

Account :: Account(char* id, char* name, double balance=0)
{
	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->balance = balance;
}

Account :: ~Account()
{
	delete [] name;
	delete [] id;
}

void Account :: ShowAllData()
{
	cout << name << " �������� ���� ����" << endl;
	cout << "���� ��ȣ: " << id << endl;
	cout << "��     ��: " << balance << endl;
	cout << endl;
}

char* Account :: GetName()
{
	return name;
}

char* Account :: GetId()
{
	return id;
}

double Account :: GetBalance()
{
	return balance;
}

void Account :: SetBalance(double balance)
{
	this->balance = balance;
} 