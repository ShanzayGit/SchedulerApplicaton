#include "MyString.h"
#ifndef DATE_H
#define DATE_H
class Date
{
	int day;
	int month;
	int year;
	static const int daysInMonth[13];
	static const char monthFull[13][20];
	static const char monthShort[13][4];
	bool isLeapYear()const;
public:
	Date();
	Date(int, int, int);
	bool setDate(int, int, int);
	bool setDay(int);
	bool setMonth(int);
	bool setYear(int);
	int getMonth()const;
	int getDay()const;
	int getYear()const;
	void printFormat1()const;//  12/25/2012
	void printFormat2()const;//  december 25,2021
	void printFormat3()const;//  25-dec-2012
	void incYear(int = 1);
	void incMonth(int = 1);
	void incDay(int = 1);
	String getDateInFormat1()const;
	String getDateInFormat2()const;
	String getDateInFormat3()const;
};
#endif