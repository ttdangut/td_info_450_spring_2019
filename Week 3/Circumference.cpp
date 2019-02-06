/* Circumference.cpp

Write a program that asks the user for the radius of a circle and using a function, calculate the circumference of the circle.
You must use a const delcaration of PI in the global scope.
Requirement: The function must be match this signature: double calculateCircumference(double radius);

*/

#include "pch.h"
#include <iostream>
using namespace std;

// All function declaration

double calculateCircumference(double radius);
const float PI = 3.14159265358979323846;

int main()
{

	//Calling the variable

	double circle;
	double circumference;


	cout << "Please enter the radius of circle: "; 	//Inputting radius of circle from user
	cin >> circle;
	circumference = calculateCircumference(circle);

	cout << "" << endl; //Adding a space between

	cout << "The circumference of the circle: " << circle << " is " << circumference << endl;

	return 0; // End program

}

//Calculating circumference of circle when the radius is given

double calculateCircumference(double radius)
{

	double circumference = (2 * PI * radius); // PI = 3.14
	return circumference;

}


