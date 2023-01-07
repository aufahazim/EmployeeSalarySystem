#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include"employeeSalary.h"
using namespace std;

void readFile(string[],int[],int[],float[],float[],float[],int,int);

int main(){
	int employeeNumber;
	int hour;
	int id;
	int daysInWeek=7;
	int i;
	int j;
	int size = 3;
	int hourList[size];
	int idList[size];
	float salary;
	float dailySalary;
	float total[100];
	float salaryList[size];
	float dailySalaryList[size];
	float weekSalaryList[size];
	string name;
	string nameList[size];
	char choice;
	employeeSalary e[100];
	
	readFile(nameList, hourList, idList, salaryList, dailySalaryList,weekSalaryList, daysInWeek, size);
	
	cout << "This is the information of the employee from the file " << endl;
	for(i=0; i<size; i++)
	{
		cout << "Employee number " << (i+1) << endl;
		cout << "Name: ";
		cout << nameList[i] << endl;
		cout << "ID: ";
		cout << idList[i] << endl;
		cout << "________________________________________"<<endl; 
		for(j=0; j<daysInWeek; j++)
		{
		cout << setprecision(2) << fixed;
		cout << "Salary per hour for day " << (j+1) << ":RM ";
		cout << salaryList[j] << endl;
		cout << "Works hour for day " << (j+1) << ":";
		cout << hourList[j] << " hours" << endl;
		cout << "Total salary for day " << (j+1) << ":RM" ;
		cout << dailySalaryList[j] << endl; 
		cout << "________________________________________"<<endl;
		}
		cout << "Total salary for the week :RM "<< weekSalaryList[i] << endl;
		cout << endl;
	}
	
	cout << "The total initial salary is: " << e[100].add() << endl;
	cout << "Do you want to change the list of employees?(y/n)";
	do{
		cin >> choice;
	
	if(choice=='y')
	{
	cout << "Please enter the number of employee(limit=100): " << endl;
	do{
		cin >> employeeNumber;
		if(0>=employeeNumber || employeeNumber>100)
		{
			cout << "The number is invalid please try again:" << endl; 
		}
	}while(0>=employeeNumber || employeeNumber>100);

    ofstream outFile;
	outFile.open("EmployeeSalary.txt");
	for(i=0; i<employeeNumber; i++)
	{
		cout << "Employee number " << (i+1) << endl;
		cout << "Enter the name of the employee:";
		cin.ignore();
		getline(cin, name); 
		e[i].setemployeeName(name);
		cout << "Enter the ID of the employee:";
		cin >> id;
		e[i].setemployeeId(id);
		for(j=0; j<daysInWeek; j++)
		{ 
		cout << "Enter the salary per hour for day " << (j+1) << "(RM):";
	
		cin >> salary;
		while(0>=salary)
		{
			cout << "The number is invalid please try again:" << endl; 
			cin >> salary;
		}	
			
		
		e[j].setSalary(salary);
		
		cout << "Enter the hour works for day " << (j+1) << ":";
		
		do{
		cin >> hour;
		if(0>=hour || hour>=24)
		{
			cout << "The number is invalid please try again:" << endl; 
		}	
		}while(0>=hour || hour>=24);
		
		e[j].setHour(hour);
		
		e[j].setDailySalary(salary,hour);
		
		dailySalary = salary*hour;
		
		total[i] += e[j].getDailySalary();
		
		outFile << salary << " "<< hour << " " << dailySalary << " ";
		//week += (salary*hour);
		}
		//e[i].setWeeklySalary(week);
		outFile << name << "\t" << id << " " << total[i] << endl;
	}
	outFile.close();
	
	for(i=0; i<employeeNumber; i++)
	{
		cout << "Employee number " << (i+1) << endl;
		cout << "Name: ";
		cout << e[i].getemployeeName() << endl;
		cout << "ID: ";
		cout << e[i].getemployeeId() << endl;
		cout << "________________________________________"<<endl; 
		for(j=0; j<daysInWeek; j++)
		{
		cout << setprecision(2) << fixed;
		cout << "Salary per hour for day " << (j+1) << ":RM ";
		cout << e[j].getSalary() << endl;
		cout << "Works hour for day " << (j+1) << ":";
		cout << e[j].getHour() << " hours" << endl;
		cout << "Total salary for day " << (j+1) << ":RM" ;
		cout << e[j].getDailySalary() << endl; 
		cout << "________________________________________"<<endl;
		}
		cout << "Total salary for the week :RM "<< total[i] << endl;
		cout << endl;
		//cout << e[i].getWeeklySalary();
	}
	return 0;
    }
    else if(choice='n')
	{
		cout << "exit program" << endl;
		return 0;
	}
	else
	{
	cout << "invalid option please try again" << endl;
    }
    }while(choice!='y' || choice!='n');
    
	return 0;
}

void readFile(string nameList[],int hourList[],int idList[],float salaryList[],float dailySalaryList[],float weekSalaryList[],int daysInWeek,int size)
{
	ifstream inFile;
	
	inFile.open("EmployeeSalary.txt");
	
	while(inFile)
	{
		for(int count = 0; count < size; count++)
		{
			for(int count1 = 0; count1 < daysInWeek; count1++)
			{
				inFile >> salaryList[count1];
				inFile >> hourList[count1];
				inFile >> dailySalaryList[count1];
			}
			getline(inFile,nameList[count], '\t');
			inFile >> idList[count];
			inFile >> weekSalaryList[count];
			inFile.ignore();
		}
	}

	inFile.close();
}
