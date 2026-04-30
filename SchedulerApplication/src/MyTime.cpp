#include<iostream>
#include"MyTime.h"
using namespace std;
Time::Time()
{
	hours = minutes = seconds = 0;
}
Time::Time(int h, int m, int s) :Time()
{
	setTime(h, m, s);
}
bool Time::isValidTime(int h, int m, int s)const
{
	if (h < 24 && h >= 0)
	{
		if (m < 60 && m >= 0 && s >= 0 && s < 60)
		{
			return true;
		}
		return false;
	}
	return false;
}
void Time::setHour(int h)
{
	if (h >= 0 && h < 24)
	{
		hours = h;
	}
}
void Time::setMinute(int m)
{
	if (m >= 0 && m < 60)
	{
		minutes = m;
	}
}
void Time::setSecond(int s)
{
	if (s >= 0 && s < 60)
	{
		seconds = s;
	}
}
int Time::getHour()const
{
	return hours;
}
int Time::getSecond()const
{
	return seconds;
}
int Time::getMinute()const
{
	return minutes;
}
bool Time::setTime(int h, int m, int s)
{
	if (isValidTime(h, m, s))
	{
		hours = h;
		minutes = m;
		seconds = s;
		return 1;
	}
	return 0;
}
void Time::incSec(int increament)
{
	int previousSecond = seconds + increament;
	seconds = previousSecond % 60;
	incMin(previousSecond / 60);
}
void Time::incMin(int increament)
{
	int previousMin = minutes + increament;
	minutes = previousMin % 60;
	incHour(previousMin / 60);

}
void Time::incHour(int increament)
{
	int previousHour = hours + increament;
	hours = previousHour % 24;
}
void Time::printTwentyFoursHourFormat()const
{
	if (hours < 10)
		cout << 0 << hours;
	else
	{
		cout << hours % 24;
		if (hours % 24 == 0)
			cout << 0;
	}
	cout << " : ";
	if (minutes < 10)
		cout << 0 << minutes;
	else
		cout << minutes;
	cout << " : ";
	if (seconds < 10)
		cout << 0 << seconds;
	else
		cout << seconds;
	if (hours >= 0 && hours < 12)
		cout << " AM";
	else
		cout << " PM";
}
void Time::printTwelveHourFormat()const
{
	if (hours < 10)
		cout << 0 << hours;
	else
	{
		cout << hours % 12;
		if (hours % 12 == 0)
			cout << 0;
	}
	cout << " : ";
	if (minutes < 10)
		cout << 0 << minutes;
	else
		cout << minutes;
	cout << " : ";
	if (seconds < 10)
		cout << 0 << seconds;
	else
		cout << seconds;
	if (hours >= 0 && hours < 12)
		cout << " AM";
	else
		cout << " PM";
}