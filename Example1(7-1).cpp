#include <iostream>
using namespace std;

class Account
{
protected:
	char acc_num[10];
	int balance;
public:
	Account(char* num, int bal);
};

Account :: Account(char* num, int bal) 
{
	strcpy(acc_num, num);
	balance = bal;
}

class KBAccount : public Account
{
	int limit_money;
public:
	KBAccount(char* num, int balance, int limit) : Account(num, balance)
	{
		limit_money = limit;
	}
	void ShowData() const 
	{
		cout << "���� ��ȣ: " << this->acc_num << endl;
		cout << "���� �ܾ�: " << this->balance << "��" << endl;
		cout << "��ü �ѵ�: " << this->limit_money << "��" << endl;
	}
};

int main()
{
	KBAccount acc("1234-5678", 5000, 1000000);
	acc.ShowData();

	return 0;
}