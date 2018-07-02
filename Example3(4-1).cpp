#include <iostream>
#include <string>
using namespace std;

class NameCard
{
private:
	char name[30];
	char phone[30];
	char addr[30];
	char rank[30];
public:
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
	NameCard Seong("Seong Myunghun", "333-3333", "www.ezsun.net", "missionary");
	Seong.ShowData();

	return 0;
}