#include<iostream>
#include<string>
#include"employeeSalary.h"
using namespace std;

// setSalary assign a value to the salary member
void employeeSalary::setSalary(float s)
{
	salary = s;
}

// setHour assign a value to the hour member
void employeeSalary::setHour(int h)
{
	hour = h;
}

// getSalary returns the value in the salary member
float employeeSalary::getSalary()
{
	return salary;
}

// getHour returns the value in the hour member
int employeeSalary::getHour()
{
	return hour;
}

// setDailysalary calculate the salary and assign the value to the daily salary member
void employeeSalary::setDailySalary(float salary,int hour)
{
	dailySalary = salary * hour;
}

// getDailySalary returns the value in the dailySalary member
float employeeSalary::getDailySalary()
{
	return dailySalary;
}

// setWeeklySalary assign a value to the setweekly function
void employeeSalary::setWeeklySalary(float week)
{
	w.setWeekly(week);
}

//getWeeklySalary receive the value from the function
float employeeSalary::getWeeklySalary()
{
	w.getWeekly();
}
