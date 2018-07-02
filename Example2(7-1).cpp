#include <iostream>
using namespace std;

class Person
{
protected:
	int age;
	char* name;
public:
	Person(int age, char* name);
	Person(const Person& p);
	~Person();
};

Person :: Person(int age, char* name)
{
	this->age = age;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Person :: Person(const Person& p)
{
	this->age = p.age;
	this->name = new char[strlen(p.name) + 1];
	strcpy(this->name, p.name);
}

Person :: ~Person()
{
	delete [] name;
}

class Student : public Person
{
	char* major;
public:
	Student(int age, char* name, char* major) : Person(age, name) 
	{
		this->major = new char[strlen(major) + 1];
		strcpy(this->major, major);
	}

	Student(const Student& s) : Person(s)
	{
		this->major = new char[strlen(s.major) + 1];
		strcpy(this->major, s.major);
	}

	~Student() 
	{
		delete [] major;
	}

	void ShowData() const
	{
		cout << "이름 : " << this->name << endl;
		cout << "나이: " << this->age << endl;
		cout << "전공: " << this->major << endl;
		cout << endl;
	}
};

int main()
{
	Student Hong1(20, "Hong Gil Dong", "Computer");
	Hong1.ShowData();

	Student Hong2=Hong1;
	Hong2.ShowData();

	return 0;
}