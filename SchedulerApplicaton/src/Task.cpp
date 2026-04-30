#include"MyTime.h"
#include "MyString.h"
#include"Date.h"
#include"Task.h"
#include<iostream>
using namespace std;
void Task::setTask(const Date& d, const Time& t, const String& m, const String& s)
{
	taskTime = t;
	taskDate = d;
	updateMessage(m);
	status = s;
}
void Task::updateDate(const Date& d)
{
	taskDate = d;
}
void Task::updateTime(const Time& t)
{
	taskTime = t;
}
void Task::updateMessage(const String& m)
{
	taskMsg = m;
}
void Task::updateStatus(const String& s)
{
	status = s;
}
Date Task::getDate()const
{
	return taskDate;
}
Time Task::getTime()const
{
	return taskTime;
}
String Task::getMsg()const
{
	return taskMsg;
}
String Task::getStatus()const
{
	return status;
}