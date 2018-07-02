#include <iostream>
#include <typeinfo>
using namespace std;

//Employee 클래스
class Employee
{
	char* name;
public:
	Employee() : name(NULL) {}
	Employee(char* name);
	char* GetName();
	virtual int GetPay()=0;
};

Employee :: Employee(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

char* Employee :: GetName()
{
	return name;
}

//Permenent 클래스
class Permenent : public Employee
{
	int salary;
public:
	Permenent() : salary(0) {}
	Permenent(char* name, int salary) : Employee(name)
	{
		this->salary = salary;
	}
	int GetPay();
};

int Permenent :: GetPay()
{
	return salary;
}

//PartTime 클래스
class PartTime : public Employee
{
	int time;
	int pay;
public:
	PartTime() : time(0), pay(0) {}
	PartTime(char* name, int time, int pay) : Employee(name)
	{
		this->time = time;
		this->pay = pay;
	}
	int GetPay();
};

int PartTime :: GetPay() 
{
	return time * pay;
}

//Departmemt 클래스
class Department
{
	Employee* empList[100];
	int index;
	char* type;
public:
	Department() : index(0), type(NULL) {};
	~Department() {delete [] type;}
	void AddEmployee(Employee* emp);
	void ShowList();
};

void Department :: AddEmployee(Employee* emp)
{
	type = new char[strlen(typeid(emp).name()) + 1];
	strcpy(type, typeid(emp).name());
	empList[index++] = emp;
}

void Department :: ShowList()
{
	for(int i = 0; i < index; i++)
	{
		cout << "Type : " << type << endl;
		cout << "Name : " << empList[i]->GetName() << endl;
		cout << "Salary : " << empList[i]->GetPay() << endl;
		cout << endl;
	}
}

//SalesPerson 클래스
class SalesPerson : public Employee
{
	int PayCount;
	int Cost;
	int pay;
public:
	SalesPerson() : PayCount(0), Cost(0) {};
	SalesPerson(char* name, int pay, int PayCount, int Cost) : Employee(name)
	{
		this->pay = pay;
		this->Cost = Cost;
		this->PayCount = PayCount;
	}
	int GetPay();
};

int SalesPerson :: GetPay()
{
	return (PayCount * Cost) * 0.15 + pay;
}

int main()
{
	Department depart;

	depart.AddEmployee(new Permenent("KIM", 1000000));
	depart.AddEmployee(new Permenent("LEE", 1200000));

	depart.AddEmployee(new PartTime("Seong", 5, 10000));
	depart.AddEmployee(new PartTime("Yoon", 5, 8000));

	depart.AddEmployee(new SalesPerson("Park", 1000000, 3, 500000));
	depart.AddEmployee(new SalesPerson("Gong", 1200000, 10, 1000000));

	depart.ShowList();

	return 0;
}