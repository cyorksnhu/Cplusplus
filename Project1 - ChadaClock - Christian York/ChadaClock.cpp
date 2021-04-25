#include "ChadaClock.h"
#include <iostream>
using namespace std;
class Clock
{
	int hour12 = 0;//for 12 hour clock
	int hour24 = 0;//for 24 hour clock
	int minute = 0;
	int seconds = 0;

	enum AMPM {//enum to track AM and PM in 12 hour clock
		AM, PM
	} ampm;

	void addHour()
	{
		if (hour12 == 11) {
			hour12 = 12;
			if (ampm == PM) {
				ampm = AM;
			}
			else {
				ampm = PM;
			}
		}
		else {
			if (hour12 == 12) {
				hour12 = 1;
			}
			else {
				hour12 += 1;
			}
		}
		if (hour24 == 23)
		{
			hour24 = 0;
		}
		else {
			hour24 += 1;
		}
	}

	void addMinute()
	{
		if (minute == 59) {
			minute = 0;
			addHour();
		}
		else {
			minute += 1;
		}
	}

	void addSecond()
	{
		if (seconds == 59) {
			seconds = 0;
			addMinute();
		}
		else {
			seconds += 1;
		}
	}

	void displayTime()
	{
		cout << "***************************\t***************************" << endl;
		cout << "*\t12-Hour Clock\t* *\t24-Hour Clock\t*" << endl;
		cout << "*";
		if (hour12 < 10)
			cout << "0";
		cout << hour12 << ":";
		if (minute < 10)
			cout << "0";
		cout << minute << ":";
		if (seconds < 10)
			cout << "0";
		cout << seconds;
		if (ampm == AM)
			cout << " AM";
		else
		{
			cout << " PM";
			cout << "\t* *\t";
		}
		if (hour24 < 10)
			cout << "0";
		cout << hour24 << ":";
		if (minute < 10)
			cout << "0";
		cout << minute << ":";
		if (seconds < 10)
			cout << "0";
		cout << seconds;
		cout << "\t*" << endl;
		cout << "***************************\t***************************" << endl;
	}

	int main() {

		while (true)
		{
			cout << "***************************\n";
			cout << "* 1 - Add One Hour *\n";
			cout << "* 2 - Add One Minute *\n";
			cout << "* 3 - Add One Second *\n";
			cout << "* 4 - Exit Program *\n";
			cout << "***************************\n";
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
				addHour();
				displayTime();
				break;
			case 2:
				addMinute();
				displayTime();
				break;
			case 3:
				addSecond();
				displayTime();
				break;
			case 4:
				cout << "Thank You!";
				exit(1);
				break;
			default:
				cout << "Invalid choice!\n";
				break;
			}
		}
	}
};