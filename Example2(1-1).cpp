#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char name[20];
	char phone[20];

	cout << "Input Name: ";
	cin >> name;

	cout << "Input Phone: ";
	cin >> phone;
	
	cout << "Name : "<< name << endl;
	cout << "Phone : " << phone << endl;

	return 0;
}