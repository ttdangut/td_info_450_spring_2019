/* program1.cpp

Write a program that reads a set of 10 whole numbers from the user into an array.

Once read in, it calculates the mean and the standard deviation of the numbers then displays the results to the console.

1. Find the mean (the simple average of the numbers)
2. Then, for each number, subtract the mean and square the result.
3. Then, work out the mean of those squared differences.
4. Take the square root of that

*/

#include "pch.h"
#include <iostream>
using namespace std;

	
int main()
{
	cout << "Please enter 10 numbers to retrieve the mean and standard deviation" << endl; //display introduction

	cout << "" << endl; // space

	// declaring a variable
	const int largesize = 10;
	int i;
	int rainbow[10];
	int sum = 0;
	double STD_DV = 0;


	for (i = 0; i < largesize; i++) { // moves the number to the next spot in the array
		cin >> rainbow[i]; // enters the value into the position
		sum += rainbow[i]; // total of the sum

	}
	double mean = sum / 10; // calculate mean
	for (int i = 0; i < 10; ++i) { // cycles the position in the arra

		STD_DV	+= pow(rainbow[i] - mean, 2); // calculates the standard deviation before square rooting and dividing it

	}

	STD_DV = sqrt(STD_DV / 10); // Final standard deviation

	cout << "" << endl; //space 

cout << "The mean of the numbers is " << mean << endl;
cout << "The standard deviation of the numbers is " << STD_DV << endl;

}