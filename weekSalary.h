#ifndef WEEKSALARY_H
#define WEEKSALARY_H

// weekSalary class Declaration
class weekSalary
{
	private:
		float totalWeekly;
		// private member
	public:
		weekSalary(){totalWeekly = 0.0;} // constructor
		~weekSalary(){totalWeekly = 0.0;}
		void setWeekly(float week){totalWeekly = week;}
		float getWeekly(){return totalWeekly;}
		friend class employeeSalary; // declare entire class friend class
		// public member             // as afriend of this class
};
#endif

