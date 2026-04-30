#include"MyTime.h"
#include"MyString.h"
#include"Date.h"
#include"Task.h"
#include"Scheduler.h"
#include"SchedulerApp.h"
#include<iostream>
#include<ctime>
using namespace std;
void SchedularApp::startApp()
{
	Schedular s;
	int choice;
	cout << "\nEnter your choice:\n1... To Add a Task\n2... To Update Task Time\n3... To Update Task Date\n4... To Update Task Message \n5... To Update Task Status\n6... To Display All Todo Tasks\n7... To Display All InProgress Tasks\n8... To Display All Done Tasks\n9... To Display All Tasks";
	cout << "\n10.. To Display a Secific Task \n11.. To Displaye Today's Tasks\n0... To Exit\n";
	cin >> choice;
	while (choice != 0)
	{

		if (choice == 1)
		{
			Date d;
			Time t;
			Task task;
			int month, day, year;
			cout << "\nEnter date (MM:DD:YYYY)  : ";
			cin >> month >> day >> year;
			d.setDate(month, day, year);
			int hour, sec, min;
			cout << "\nEnter time (HOUR:MIN:SEC) : ";
			cin >> hour >> min >> sec;
			cin.ignore();
			t.setTime(hour, min, sec);
			String msg, st;
			cout << "\nEnter your task message : ";
			cin >> msg;
			cout << "\nEnter your Task Status (Todo/InProgress/Done) : ";
			cin >> st;
			task.setTask(d, t, msg, st);
			s.addTask(task);
		}
		else if (choice == 2)
		{
			Time oldTime, newTime;
			int oldH, newH, oldM, newM, oldS, newS;
			cout << "\nEnter time you want to update:(HOUR:MIN:SEC)";
			cin >> oldH >> oldM >> oldS;
			oldTime.setTime(oldH, oldM, oldS);
			cout << "\nEnter new time :(HOUR:MIN:SEC)";
			cin >> newH >> newM >> newS;
			newTime.setTime(newH, newM, newS);
			s.updateTaskTime(oldTime, newTime);
		}
		else if (choice == 3)
		{
			Date oldDate, newDate;
			int oldM, oldY, oldD, newM, newD, newY;
			cout << "\nEnter date you want to update (MM:DD:YY)";
			cin >> oldM >> oldD >> oldY;
			oldDate.setDate(oldM, oldD, oldY);
			cout << "\nEnter new date (MM:DD:YY)";
			cin >> newM >> newD >> newY;
			newDate.setDate(newM, newD, newY);
			s.updateTaskDate(oldDate, newDate);
		}
		else if (choice == 4)
		{
			String oldMsg, newMsg;
			cout << "\nEnter task message you want to update :";
			cin.ignore();
			cin >> oldMsg;
			cout << "\nEnter new task message  :";
			cin >> newMsg;
			s.updateTaskMsg(oldMsg, newMsg);
		}
		else if (choice == 5)
		{
			String msg, status;
			cout << "\nEnter Task whose Status you Want to Update : ";
			cin >> msg;
			cout << "\nEnter Status : ";
			cin >> status;
			s.updateTaskStatus(msg, status);
		}
		else if (choice == 6)
		{
			s.displayTodoTasks();
		}
		else if (choice == 7)
		{
			s.displayDoneTasks();
		}
		else if (choice == 8)
		{
			s.displayDoneTasks();
		}
		else if (choice == 9)
		{
			s.displayAllTasks();
		}
		else if (choice == 10)
		{
			Date date;
			int m, d, y;
			cout << "\nEnter date to display task:(MM:DD:YY)";
			cin >> m >> d >> y;
			date.setDate(m, d, y);
			s.displayTask(date);
		}
		else if (choice == 11)
		{
			s.DisplayTodaysTask();
		}
		else
			cout << "\nEnter an appropriate choice!!";
		cout << "\nEnter your choice:\n1... To Add a Task\n2... To Update Task Time\n3... To Update Task Date\n4... To Update Task Message \n5... To Update Task Status\n6... To Display All Todo Tasks\n7... To Display All InProgress Tasks\n8... To Display All Done Tasks\n9... To Display All Tasks";
		cout << "\n10.. To Display a Secific Task \n11.. To Displaye Today's Tasks\n0... To Exit\n";
		cin >> choice;
	}
}