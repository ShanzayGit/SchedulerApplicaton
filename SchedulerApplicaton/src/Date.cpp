
#include<iostream>
#include "MyString.h"
#include"Date.h"
#include<iomanip>
using namespace std;
const int Date::daysInMonth[13] = { 0,31,28,31,30,31,30,31,30,31,30,31,30 };
const char Date::monthFull[13][20] = { "0","January ","February ","March ","April ","May ","June ","July ","August ","September ","Octuber ","November ","December " };
const char Date::monthShort[13][4] = { "0","Jan","feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
bool Date::isLeapYear()const
{
    {
        if (((year % 4 == 0) && (year % 100 != 0) && (year % 400 != 0)) || ((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0)))
            return true;
        else
            return false;
    }
}
Date::Date() :day(14), month(10), year(2019)
{
}
Date::Date(int m, int d, int y) :Date()
{
    setDate(m, d, y);
}
void Date::setDate(int m, int d, int y)
{
    setYear(y);
    setMonth(m);
    setDay(d);
}
void Date::setDay(int d)
{
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (d > 0 && d <= 30)
            day = d;
        else
            exit(0);
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (d > 0 && d <= 31)
            day = d;
        else
            exit(0);
    }
    else
    {
        if (isLeapYear())
        {
            if (d > 0 && d <= 29)
                day = d;
            else
                exit(0);
        }
        else
        {
            if (d > 0 && d <= 28)
                day = d;
            else
                exit(0);
        }
    }
}
void Date::setMonth(int m)
{
    if (m > 0 && m <= 12)
        month = m;
}
void Date::setYear(int y)
{
    if (y >= 1500 && y <= 3000)
        year = y;
}
int Date::getMonth()const
{
    return month;
}
int Date::getDay()const
{
    return day;
}
int Date::getYear()const
{
    return year;
}
void Date::printFormat1()const//  12/25/2012
{
    cout << setw(2) << setfill('0') << getMonth() << "/" << setw(2) << day << "/" << year;
}
void Date::printFormat2()const//  december 25,2021
{
    cout << monthFull[month] << setfill('0') << " " << setw(2) << day << "," << year;
}
void Date::printFormat3()const//  25-dec-2012
{
    cout << setw(2) << setfill('0') << day << "-" << monthShort[month] << "-" << year;
}
void Date::incYear(int inc)
{
    year = year + inc;
}
void Date::incMonth(int inc)
{
    month = month + inc;
    int incr = month % 12;
    int incrYear = month / 12;
    if (incr > 0)
    {
        incYear(incrYear);
        month = incr;
    }
}
void Date::incDay(int inc)
{
    int temp = day + inc;
    while (temp > 0)
    {
        if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            day = day + 1;
            int incrMonth = day / 30;
            int incr = day % 30;
            if (incr > 0)
            {
                incMonth(incrMonth);
                day = incr;
            }
        }
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            day = day + 1;
            int incrMonth = day / 31;
            int incr = day % 31;
            if (incr > 0)
            {
                incMonth(incrMonth);
                day = incr;
            }
        }
        else
        {
            if (isLeapYear())
            {
                day = day + 1;
                int incrMonth = day / 29;
                int incr = day % 29;
                if (incr > 0)
                {
                    incMonth(incrMonth);
                    day = incr;
                }
            }
            else
            {
                day = day + 1;
                int incrMonth = day / 28;
                int incr = day % 28;
                if (incr > 0)
                {
                    incMonth(incrMonth);
                    day = incr;
                }
            }
        }
        temp--;
    }
}
String Date::getDateInFormat1()const
{
    String x{  }, z{ '/' }, mon{}, y{};
    x = (long long int)day;
    mon = (long long int)month;
    y = (long long int)year;
    x.insert(2, z);
    x += mon;
    String r{ x };
    r.insert(r.getLength(), z);
    r += y;
    return r;

}
String Date::getDateInFormat2()const
{
    String x{ monthFull[month] }, d{}, y{}, pun{ ',' }, space{ ' ' };
    d = (long long int)day;
    y = (long long int)year;
    x += d;
    String r{ x };
    /*d.setNumber(day);
    y.setNumber(year);
    String r{ x.concatenate(d) };*/
    r.insert(r.getLength(), pun);
    r.insert(r.getLength(), space);
    r += y;
    return r;
    /*  return r.concatenate(y);*/
}
String Date::getDateInFormat3()const
{
    String x{}, pun{ '-' }, y{}, m{ monthShort[month] };
    y = (long long int)year;
    x = (long long int)day;
    /*y.setNumber(year);
    x.setNumber(day);*/
    x.insert(x.getLength(), pun);
    x.insert(x.getLength(), m);
    x.insert(x.getLength(), pun);
    x.insert(x.getLength(), y);
    return x;
}