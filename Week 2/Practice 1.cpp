// Practice 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int num;
	for (;;)
	{
		cout << "Please enter a positive number to find its value when squared. Enter 0 to quit:" << endl;
		cin >> num;
		
		cout << "" << endl;

		if (num >= 1)
		{
			cout << "Your value squared is" << endl;
			cout << num * num << endl << endl;
		}
	

		else if (num <= -1)
		{
			cout << "Please enter a positive value" << endl;
		}
		else if (num == 0)
		{
			break;
		}

	}

}

