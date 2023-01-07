#ifndef EMPLOYEESALARY_H
#define EMPLOYEESALARY_H
#include<string>
#include "employee.h"
#include "weekSalary.h"

// Derived Class Declaration
// employeeSalary class Declaration
class employeeSalary:public Employee
{
	private:
		int hour;  // the employee working hour for a day
		float salary; // the salary for an hour for the worker
		float dailySalary; // the total salary for a day
		weekSalary w;  // the total salary for the week
		// private member
	public:
		employeeSalary(){hour=0;salary=0.0;dailySalary=0.0;} // constructor
		~employeeSalary(){hour=0;salary=0.0;dailySalary=0.0;}
		void setSalary(float);
		void setHour(int);
		float getSalary();
		int getHour();
		void setDailySalary(float,int);
		float getDailySalary();
		float add(){
			weekSalary s;
			return s.totalWeekly + dailySalary;
		};
		void setWeeklySalary(float);
		float getWeeklySalary();
		// public member
};
#endif

