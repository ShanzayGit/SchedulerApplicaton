#define _CRT_SECURE_NO_WARNINGS
#include"MyTime.h"
#include"MyString.h"
#include"Date.h"
#include"Task.h"
#include"Scheduler.h"
#include<iostream>
#include<ctime>
using namespace std;
const Date Schedular::systemDate = Schedular::getCurrentDate();
Date Schedular::getCurrentDate()
{
	// Get current system time
	time_t now = time(0);

	// Convert to local time
	tm* local_time = std::localtime(&now);

	// Print the current date (Year-Month-Day)
	int year = (1900 + local_time->tm_year);  // tm_year is years since 1900
	int month = (1 + local_time->tm_mon);  // tm_mon is months since January (0-11)
	int day = local_time->tm_mday;  // tm_mday is the day of the month
	Date d{ month,day,year };
	return d;
}
Schedular::Schedular()
{
	capacity = 0;
	noOfTasks = 0;
	taskList = nullptr;
}
Schedular::Schedular(int size)
{
	capacity = size;
	noOfTasks = 0;
	taskList = new Task[size];
}
void Schedular::addTask(const Task& t)
{
	if (capacity > noOfTasks)
		taskList[noOfTasks].setTask(t.getDate(), t.getTime(), t.getMsg(), t.getStatus());
	else
	{
		reSize(capacity + 2);
		taskList[noOfTasks].setTask(t.getDate(), t.getTime(), t.getMsg(), t.getStatus());
	}
	noOfTasks++;
}
void Schedular::updateTaskTime(const Time& t, const Time& newT)
{
	int h = t.getHour();
	int m = t.getMinute();
	int s = t.getSecond();
	int i = 0;
	bool isTaskAvail = false;

	while (i < noOfTasks)
	{
		int hSrc = taskList[i].getTime().getHour();
		int mSrc = taskList[i].getTime().getMinute();
		int sSrc = taskList[i].getTime().getSecond();
		if (mSrc == m && hSrc == h && sSrc == s)
		{
			taskList[i].updateTime(newT);
			isTaskAvail = true;
		}
		i++;
	}
	if (!isTaskAvail)
		cout << "No Time Matches the Search!!";
}
void Schedular::updateTaskDate(const Date& d, const Date& newD)
{
	int month = d.getMonth();
	int year = d.getYear();
	int day = d.getDay();
	int i = 0;
	bool isTaskAvail = false;

	while (i < noOfTasks)
	{
		int monthSrc = taskList[i].getDate().getMonth();
		int daySrc = taskList[i].getDate().getDay();
		int yearSrc = taskList[i].getDate().getYear();
		if (monthSrc == month && daySrc == day && yearSrc == year)
		{
			taskList[i].updateDate(newD);
			isTaskAvail = true;

		}
		i++;
	}
	if (!isTaskAvail)
		cout << "No Date matches the Search!!";
}
void Schedular::updateTaskMsg(const String& m, const String& newM)
{
	int i = 0;
	bool isTaskAvail = false;

	while (i < noOfTasks)
	{
		if (taskList[i].getMsg() == m)
		{
			taskList[i].updateMessage(newM);
			isTaskAvail = true;

		}
		i++;
	}
	if (!isTaskAvail)
		cout << " No Task Matches the Search!!";
}
void Schedular::updateTaskStatus(const String& m, const String& s)
{

	int i = 0;
	bool isTaskAvail = false;

	while (i < noOfTasks)
	{
		if (taskList[i].getMsg() == m)
		{
			taskList[i].updateStatus(s);
			isTaskAvail = true;

		}
		i++;
	}
	if (!isTaskAvail)
		cout << " No Task Matches the Search!!";
}
void Schedular::displayTask(const Date& d)const
{
	int month = d.getMonth();
	int year = d.getYear();
	int day = d.getDay();
	int i = 0;
	bool isTaskAvail = false;

	while (i < noOfTasks)
	{
		int monthSrc = taskList[i].getDate().getMonth();
		int daySrc = taskList[i].getDate().getDay();
		int yearSrc = taskList[i].getDate().getYear();
		if (monthSrc == month && daySrc == day && yearSrc == year)
		{
			cout << "Your Task is :";
			cout << taskList[i].getMsg();
			cout << " \nYour Task Status is :";
			cout << taskList[i].getStatus();
			cout << '\n';
			cout << "Time of task :";
			taskList[i].getTime().printTwelveHourFormat();
			isTaskAvail = true;

		}
		i++;
	}
	if (!isTaskAvail)
		cout << "No Task Matches your Search!!";
}
int Schedular::DateMatchIndex(const Date& d)const
{
	int month = d.getMonth();
	int year = d.getYear();
	int day = d.getDay();
	int i = 0;

	while (i < noOfTasks)
	{
		int monthSrc = taskList[i].getDate().getMonth();
		int daySrc = taskList[i].getDate().getDay();
		int yearSrc = taskList[i].getDate().getYear();
		if (monthSrc == month && daySrc == day && yearSrc == year)
			return i;
	}
	if (i == noOfTasks)
		return -1;
}
void Schedular::DisplayTodaysTask()const
{
	int month = systemDate.getMonth();
	int year = systemDate.getYear();
	int day = systemDate.getDay();
	int i = 0;
	bool isTaskAvail = false;
	while (i < noOfTasks)
	{
		int monthSrc = taskList[i].getDate().getMonth();
		int daySrc = taskList[i].getDate().getDay();
		int yearSrc = taskList[i].getDate().getYear();
		if (monthSrc == month && daySrc == day && yearSrc == year)
		{
			cout << "Taday's Scheduled task is :" << taskList[i].getMsg();
			cout << '\n' << "Status for today's Task :" << taskList[i].getStatus();
			cout << "\nTime of Today's task :";
			taskList[i].getTime().printTwelveHourFormat();
			isTaskAvail = true;
		}
		i++;

	}

	if (!isTaskAvail)
		cout << " No Task Scheduled for Today!!";

}

void Schedular::displayTodoTasks()const
{
	int i = 0;
	bool isTaskAvail = false;

	const String m = "Todo";
	while (i < noOfTasks)
	{
		if ((taskList[i].getStatus() == m))
		{
			cout << "\n Task Scheduled for date : ";
			taskList[i].getDate().printFormat1();
			cout << "\n Time : ";
			taskList[i].getTime().printTwelveHourFormat();
			cout << "\n Task : " << taskList[i].getMsg();
			isTaskAvail = true;

		}
		i++;

	}

	if (!isTaskAvail)
		cout << " No  Todo Task Scheduled !";

}
void Schedular::displayAllTasks()const
{
	int i = 0;
	bool isTaskAvail = false;

	while (i < noOfTasks)
	{
		cout << "\nTask Scheduled for date : ";
		taskList[i].getDate().printFormat1();
		cout << "\n Time : ";
		taskList[i].getTime().printTwelveHourFormat();
		cout << "\n Task : " << taskList[i].getMsg();
		cout << "\n Status : " << taskList[i].getStatus();
		i++;
		isTaskAvail = true;

	}

	if (!isTaskAvail)
		cout << " No Task  !";
}
void Schedular::displayInProgressTasks()const
{
	int i = 0;
	bool isTaskAvail = false;

	while (i < noOfTasks)
	{
		if (taskList[i].getStatus() == "InProgress")
		{
			cout << " Task Scheduled for date : ";
			taskList[i].getDate().printFormat1();
			cout << "\n Time : ";
			taskList[i].getTime().printTwelveHourFormat();
			cout << "\n Task : " << taskList[i].getMsg();
			isTaskAvail = true;

		}
		i++;

	}

	if (!isTaskAvail)
		cout << " No  InProgress Task Scheduled !";
}
void Schedular::displayDoneTasks()const
{
	int i = 0;
	bool isTaskAvail = false;

	while (i < noOfTasks)
	{
		if (taskList[i].getStatus() == "Done")
		{
			cout << " Task Scheduled for date : ";
			taskList[i].getDate().printFormat1();
			cout << "\n Time : ";
			taskList[i].getTime().printTwelveHourFormat();
			cout << "\n Task : " << taskList[i].getMsg();
			isTaskAvail = true;

		}
		i++;

	}

	if (!isTaskAvail)
		cout << " No Done Tasks !";
}
void Schedular::reSize(int cap)
{
	int i = 0;
	Task* temp = new Task[cap];
	while (i < cap && i < capacity)
	{
		temp[i].setTask(taskList[i].getDate(), taskList[i].getTime(), taskList[i].getMsg(), taskList[i].getStatus());
		i++;
	}
	delete[]taskList;
	taskList = temp;
	capacity = cap;
	noOfTasks = i;
}