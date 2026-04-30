#ifndef TIME_H
#define TIME_H
class Time
{
	int hours;
	int minutes;
	int seconds;
	bool isValidTime(int h, int m, int s)const;
public:
	Time();
	Time(int, int, int);
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
	int getHour()const;
	int getSecond()const;
	int getMinute()const;
	bool setTime(int h, int m, int s);
	void incSec(int increament = 1);
	void incMin(int increament = 1);
	void incHour(int increament = 1);
	void printTwentyFoursHourFormat()const;
	void printTwelveHourFormat()const;
};
#endif