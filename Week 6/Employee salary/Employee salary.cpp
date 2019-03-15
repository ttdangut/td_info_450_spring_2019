/* Employee salary.cpp : 

1. Write a class Employee that has some private data members:
	first name
	last name
	employee type, an indicator (true/false),
	true, the compensation is entered as an hourly amount
	false, the compensation is entered as an annual amount
	compensation
2. Member functions that allow the user to enter this information and display it
3. Write a main function that allows a user to enter data for 3 employees then prints it.
4. For employee type the program should check for the value HOURLY or EXEMPT, and re-prompt on others
5. When entering the employee information, prompt in the order the items are listed above.
6. Output, print out in this format:
	'Last Name', 'First Name': $'Annual Compensation'\n
	There are 2,000 work hours in a year

*/

#include "pch.h"
#include <iostream>

using namespace std;


class EmployeeEntry
{

private:
	char first_name[255]; // First Name
	char last_name[255]; // Last Name 
	bool employee_type; // True for hourly and false for annual salary
	int compensation; //   Payment

public:
	void set_first_name(const char* in_name) { strcpy_s(first_name, in_name); }
	void set_last_name(const char* in_name) { strcpy_s(last_name, in_name); }
	void set_employee_type(bool t) { (employee_type = t); }
	void set_compensation(int t)

	{
		if (employee_type) { t = t * 2000; compensation = t; }
		compensation = t;
	}

	void printEntry()
	{
		{
			if (last_name)

				cout << last_name << ";";
			cout << first_name << " ";
			cout << ".......";
			cout << "$" << compensation << endl;
		}
	};

	int main()
	{
		EmployeeEntry entries[3];
		for (int x = 0; x < 3; x++)
		{
			// entry number starting at 0
			cout << "Entry: " << x << endl;
			char *myvalue = (char *)malloc(225);

			// Entering first name
			cout << "Please enter employee's first name: ";
			cin.getline(myvalue, 255);
			entries[x].set_first_name(myvalue);

			// Entering first name
			cout << "Please enter employee's last name: ";
			cin.getline(myvalue, 255);
			entries[x].set_last_name(myvalue);

			// Entering employee type
			cout << "Please enter employee type if they are exempt (a) or hourly (b)" << endl;
			cin.getline(myvalue, 255);
			entries[x].set_employee_type(myvalue);

			// Entering anual salary
			cout << "please enter anual salary" << endl;
			cin.ignore();

			// I got two error when I tried to build the solution with LNK 2019 and LNK 1120. I tried to resolve it for an hour or so but no luck. That's the only error I got. 
		}
		for (int x = 0; x < 3; x++)
		{
			entries[x].printEntry();
		}
	}
};
