#include"MyTime.h"
#include "MyString.h"
#include"Date.h"
#include"Task.h"
#ifndef SCHEDULAR_H
#define SCHEDULAR_H
class Schedular
{
	Task* taskList;
	int noOfTasks;
	int capacity;
	static const Date systemDate;
	int DateMatchIndex(const Date& d)const;
public:
	Schedular();
	Schedular(int);
	void updateTaskTime(const Date& d, const String& s, const Time& newT);
	void updateTaskDate(const String& s, const Date& oldD,const Date& newD);
	void updateTaskMsg(const Date& d,const String& m, const String& newM);
	void updateTaskStatus(const Date &d ,const String& m, const String& s);
	static Date getCurrentDate();
	void addTask(const Task&);
	void displayTask(const Date& d = systemDate)const;
	void DisplayTodaysTask()const;
	void displayTodoTasks()const;
	void displayAllTasks()const;
	void displayInProgressTasks()const;
	void displayDoneTasks()const;
	void reSize(int);
	int getCapacity()
	{
		return capacity;
	}
	int getTasks()
	{
		return noOfTasks;
	}
};
#endif