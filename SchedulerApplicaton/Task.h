#include"Time.h"
#include"String.h"
#include"Date.h"
#ifndef TASK_H
#define TASK_H
class Task
{
	Date taskDate;
	Time taskTime;
	String taskMsg;
	String status;
	//~Task()
	//{}
	Task(const Task& t);
public:
	Task()
	{
	}
	Task(const Date& d, const Time& t, const String& m, const String& stat) :taskDate(d), taskTime(t), taskMsg(m), status(stat)
	{
	}
	void setTask(const Date& d, const Time& t, const String& m, const String& s);
	void updateDate(const Date& d);
	void updateTime(const Time& t);
	void updateMessage(const String& m);
	void updateStatus(const String& s);
	Date getDate()const;
	Time getTime()const;
	String getMsg()const;
	String getStatus()const;
};

#endif