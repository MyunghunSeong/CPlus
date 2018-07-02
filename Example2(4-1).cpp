#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time(int val);
	Time(int val1, int val2);
	Time(int val1, int val2, int val3);
	~Time() {}
	void ShowTime();
	void ShowTimeinSec();
};

Time::Time(int val)
{
	hour = val;
	minute = 0;
	second = 0;
}

Time::Time(int val1, int val2)
{
	hour = val1;
	minute = val2;
	second = 0;
}

Time::Time(int val1, int val2, int val3)
{
	hour = val1;
	minute = val2;
	second = val3;
}

void Time::ShowTime()
{
	cout << "[" << hour << "시 " << minute << "분 " <<  second << "초]" << endl;
}

void Time::ShowTimeinSec()
{
	int allSec = (hour * 3600) + (minute * 60) + second;
	cout << allSec << "초" << endl;
}

int main()
{
	Time time1(10);
	Time time2(10,20);
	Time time3(10,20,30);

	time2.ShowTime();
	time2.ShowTimeinSec();

	return 0;
}
