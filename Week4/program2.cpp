/* program2.cpp 

 Write a program that inputs the names of the students in the class.(to a max of 30 names)
 Store them in a 2-dimensional array
 Then outputs the class list to the console when the user enters an empty string by pressing enter.

*/
#include "pch.h"
#include <iostream>
using namespace std;


// Function main begins here.
int main()
{

	char StudentInClass[30][20]

	for (int s = 0; s < 30; s++)
	{
		cout << "Please enter a student name in the class: \n";
		cin.getline(StudentInClass[s], 30);
	}

	cout << "List of students name:" << endl;
	for (int s = 0; s < 30; s++)

	{

		{
			cout << StudentInClass[s] << endl;
		}
	}
	return 0;
}
