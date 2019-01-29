// Pracetice 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int yr;

	for (;;)
	{
		cout << "Please enter a year to determine if it is a leap year! ";
		cin >> yr;
		
		cout << "" << endl;

		if (yr % 100 != 0)
		{

			cout << "It has determine it is a leap year" << endl;

		}
		else if (yr % 4 == 0 && yr % 100 == 0 && yr % 400 == 0)
		{

			cout << "It determines it is a leap year" << endl;
		
		}
		else if (yr % 400 != 0)
		{

			cout << "Its not a leap year" << endl;

		}
		else if (yr % 400 == 0)
		{

			cout << "Its is not a leap year" << endl;
		}
		cout << "" << endl;
	}
	return 0;
}
