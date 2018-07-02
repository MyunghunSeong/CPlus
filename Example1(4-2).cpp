#include <iostream>
using namespace std;

class NameCard
{
private:
	char name[30];
	char phone[30];
	char addr[30];
	char rank[30];
public:
	NameCard() {}
	NameCard(char* name, char* phone, char* addr, char* rank);
	~NameCard() {}
	void ShowData();
};

NameCard::NameCard(char* name, char* phone, char* addr, char* rank)
{
	strcpy(NameCard::name, name);
	strcpy(NameCard::phone, phone);
	strcpy(NameCard::addr, addr);
	strcpy(NameCard::rank, rank);
}

void NameCard::ShowData()
{
	cout << "이    름 : " << name << endl;
	cout << "전화번호 : " << phone << endl;
	cout << "주    소 : " << addr << endl;
	cout << "직    급 : " << rank << endl;
}

int main()
{
	NameCard* cards[3];
	char name[30], phone[30], addr[30], rank[30];

	for(int i = 0; i < 3; i++)
	{
		cout << i+1 << "번째 입력" << endl;
		cout << "name : ";
		cin >> name;

		cout << "phone : ";
		cin >> phone;

		cout << "address : ";
		cin >> addr;

		cout << "rank : ";
		cin >> rank;

		cards[i] = new NameCard(name, phone, addr, rank);

		cards[i]->ShowData();
		delete cards[i];

		name[30] = NULL;
		phone[30] = NULL;
		addr[30] = NULL;
		rank[30] = NULL;
	}

	return 0;
}