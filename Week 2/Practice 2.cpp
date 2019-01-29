// Practice 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	int count = 0;
	int num;

	for (;;)
	{
		cout << "Please enter a number to find out if it is prime" << endl;
		cin >> num;

		if (num == 0)
		{
			break;
		}
		else
		{
			for (i = 2; i < num; i++)
				if (num % i == 0)
					count++;
		}
		if (count > 1)
		{
			cout << "This is NOT A PRIME NUMBER" << endl;
		}
		else
		{
			cout << "This is a PRIME NUMBER" << endl;
		
		}
		cout << "" << endl;
	}

}
