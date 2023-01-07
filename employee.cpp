#include "employee.h"
#include<iostream> 
#include<string>

using namespace std;

// setemployeeName assign a string to the employeeName member
void Employee::setemployeeName(string name)
{
	employeeName = name;
}

// setemployeeId assign a value to the employeeId member
void Employee::setemployeeId(int a)
{
	employeeId = a;
}

// getemployeeName returns the string into employeeName member
string Employee::getemployeeName() const
{
	return employeeName;
}

// getemployeeId returns the value into the employeeId member
int Employee::getemployeeId() const
{
	return employeeId;
}

