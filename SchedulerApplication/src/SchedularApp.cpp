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
	cout << "Enter your choice:\n1... To Add a Task\n2... To Update Task Time\n3... To Update Task Date\n4... To Update Task Message \n5... To Update Task Status\n6... To Display All Todo Tasks\n7... To Display All InProgress Tasks\n8... To Display All Done Tasks\n9... To Display All Tasks";
	cout << "\n10.. To Display a Secific Task \n11.. To Displaye Today's Tasks\n0... To Exit\n";
	cin >> choice;
	while (choice != 0)
	{

		if (choice == 1)
		{
			Date d;
			Time t;
			Task task;
			int month, day, year; bool vd = 1,ts=1;
			while (vd)
			{
				cout << "\nEnter date you want to update (MM:DD:YY)";
				cin >> month >> day >> year;
				if (d.setDate(month, day, year))
					vd = 0;
				else
					cout << "\nInvalid date month , year or day!! Try Again !!";
			}
			int hour, sec, min;
			while(ts)
			{
				cout << "\nEnter time (HOUR:MIN:SEC) : ";
				cin >> hour >> min >> sec;
				if(t.setTime(hour, min, sec))
					ts = 0;
				else
				{
					cout << "\nInvalid Time !! Enter again!!";
				}
			} 
			cin.ignore();
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
			Date oldDate;
			Time newTime;
			int oldM, oldY, oldD;
			bool vd = 1,ts=1;
			while (vd)
			{
				cout << "\nEnter date of task you want to update (MM:DD:YY)";
				cin >> oldM >> oldD >> oldY;
				if (oldDate.setDate(oldM, oldD, oldY))
					vd = 0;
				else
					cout << "Invalid date month , year or day!! Try Again !!";
			}
			cin.ignore();
			String msg;
			cout << "Enter task for which you want to change Time : ";
			cin >> msg;
			int  newH, newM, newS;	
			while (ts)
			{
				cout << "\nEnter time (HOUR:MIN:SEC) : ";
				cin >> newH >> newM >> newS;
				if (newTime.setTime(newH, newM,newS))
					ts = 0;
				else
				{
					cout << "\nInvalid Time !! Enter again!!";
				}
			}
			s.updateTaskTime(oldDate ,msg, newTime);
		}
		else if (choice == 3)
		{
			String msg;
			cout << "Enter task for which you want to change Time : ";
			cin.ignore();
			cin >> msg;
			Date oldDate, newDate;
			int oldM, oldY, oldD, newM, newD, newY;
			bool vd = 1;
			while (vd)
			{
				cout << "\nEnter date you want to update (MM:DD:YY)";
				cin >> oldM >> oldD >> oldY;
				if (oldDate.setDate(oldM, oldD, oldY))
					vd = 0;
				else
					cout << "Invalid date month , year or day!! Try Again !!";
			}
			bool vnd = 1;
			while (vnd)
			{
				cout << "\nEnter new date (MM:DD:YY)";
				cin >> newM >> newD >> newY;
				if (oldDate.setDate(newM, newD, newY))
					vnd = 0;
				else
					cout << "Invalid date month , year or day!! Try Again !!";
			}			
			s.updateTaskDate(msg,oldDate, newDate);
		}
		else if (choice == 4)
		{
			Date oldDate;
			int oldM, oldY, oldD;
			bool vd = 1;
			while (vd)
			{
				cout << "\nEnter date you want to update (MM:DD:YY)";
				cin >> oldM >> oldD >> oldY;
				if (oldDate.setDate(oldM, oldD, oldY))
					vd = 0;
				else
					cout << "Invalid date month , year or day!! Try Again !!";
			}
			String oldMsg, newMsg;
			cout << "\nEnter task message you want to update :";
			cin.ignore();
			cin >> oldMsg;
			cout << "\nEnter new task message  :";
			cin >> newMsg;
			s.updateTaskMsg(oldDate,oldMsg, newMsg);
		}
		else if (choice == 5)
		{

			Date oldDate;
			int oldM, oldY, oldD; 
			bool vd = 1;
			while (vd)
			{
				cout << "\nEnter date you want to update (MM:DD:YY)";
				cin >> oldM >> oldD >> oldY;
				if (oldDate.setDate(oldM, oldD, oldY))
					vd = 0;
				else
					cout << "Invalid date month , year or day!! Try Again !!";
			}
			String msg, status;
			cout << "\nEnter Task whose Status you Want to Update : ";
			cin >> msg;
			cout << "\nEnter Status : ";
			cin >> status;
			s.updateTaskStatus(oldDate,msg, status);
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
			int m, d, y; bool vd = 1;
			while (vd)
			{
				cout << "\nEnter date you want to update (MM:DD:YY)";
				cin >> m >>d >> y;
				if (date.setDate(m, d, y))
					vd = 0;
				else
					cout << "Invalid date month , year or day!! Try Again !!";
			}
			s.displayTask(date);
		}
		else if (choice == 11)
		{
			s.DisplayTodaysTask();
		}
		else
			cout << "\nEnter an appropriate choice!!";
		cout << "\n\nEnter your choice:\n1... To Add a Task\n2... To Update Task Time\n3... To Update Task Date\n4... To Update Task Message \n5... To Update Task Status\n6... To Display All Todo Tasks\n7... To Display All InProgress Tasks\n8... To Display All Done Tasks\n9... To Display All Tasks";
		cout << "\n10.. To Display a Secific Task \n11.. To Displaye Today's Tasks\n0... To Exit\n";
		cin >> choice;
		cout << "\n";
	}
}