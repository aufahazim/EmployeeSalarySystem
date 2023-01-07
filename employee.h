#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

using namespace std;

// Employee class Declaration
class Employee  {
	
	protected:
	string employeeName; // The employee's name
	int employeeId;      // The employee's ID
	// Private section
	public:
		Employee(){employeeName = "";employeeId = 0;} // constructor
		~Employee(){employeeName = "";employeeId = 0;}
		void setemployeeName(string);
		void setemployeeId(int);
		int getemployeeId() const;
		string getemployeeName() const;
		//public section
};

#endif
