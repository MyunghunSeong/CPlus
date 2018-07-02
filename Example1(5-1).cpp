#include <iostream>
using namespace std;

class NameCard
{
	char* name;
	char* phone;
	char* job;
	char* rank;
public:
	NameCard();
	NameCard(char* name, char* phone, char* job, char* rank);
	NameCard(const NameCard& obj);
	~NameCard();
	void ShowData();
};

NameCard :: NameCard()
{
	name = NULL;
	phone = NULL;
	job = NULL;
	rank = NULL;
}

NameCard :: NameCard(char* name, char* phone, char* job, char* rank)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->phone = new char[strlen(phone) + 1];
	strcpy(this->phone, phone);

	this->job = new char[strlen(job) + 1];
	strcpy(this->job, job);

	this->rank = new char[strlen(rank) + 1];
	strcpy(this->rank, rank);
}

NameCard :: NameCard(const NameCard& obj)
{
	name = new char[strlen(obj.name) + 1];
	strcpy(name, obj.name);

	phone = new char[strlen(obj.phone) + 1];
	strcpy(phone, obj.phone);

	job = new char[strlen(obj.job) + 1];
	strcpy(job, obj.job);

	rank = new char[strlen(obj.rank) + 1];
	strcpy(rank, obj.rank);
}

NameCard :: ~NameCard()
{
	delete [] name;
	delete [] phone;
	delete [] job;
	delete [] rank;
}

void NameCard :: ShowData()
{
	cout << "Name : " << name << endl;
	cout << "Phone : " << phone << endl;
	cout << "Job : " << job << endl;
	cout << "Rank : " << rank << endl;
	cout << endl;
}

int main()
{
	NameCard Seong("Seong Myunghun", "333-3333", "freelec", "manager");
	NameCard Seong2(Seong);
	Seong2.ShowData();

	return 0;
}