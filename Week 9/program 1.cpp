// program 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class road_vehicle {


private:

	int wheels;
	int passengers;
	int cargo;
	string vehicle;
	string CarType;
	road_vehicle*next;

public:
	void insert(string vehicle, int wheels, int passengers, int cargo, string CarType);
	road_vehicle(string vehicle, int wheels, int passengers, int cargo, string CarType);
	void printAll();
};

road_vehicle::road_vehicle(string Vehicle, int Wheels, int Passengers, int Cargo, string CarType)
{
	vehicle = Vehicle;
	wheels = Wheels;
	passengers = Passengers;
	cargo = Cargo;
	CarType = CarType;
	next = NULL;
}

void road_vehicle::insert(string vehicle, int wheels, int passengers, int cargo, string CarType)
{
	if (next != NULL)
	{
		next->insert(vehicle, wheels, passengers, cargo, CarType);
	}
	else
	{

		next = new road_vehicle(vehicle, wheels, passengers, cargo, CarType);
	}

}

void road_vehicle::printAll()
{
	ofstream output;
	output.open("output.txt");


	if (output.is_open()) {
		road_vehicle*temp = next;
		while (temp != NULL)
		{
			cout << "Vehicle: " << temp->vehicle << "\n";
			output << temp->vehicle + "\n";
			output << "\n";

			cout << "Wheels: " << temp->wheels << "\n";
			output << temp->wheels;
			output << "\n";

			cout << "Passengers: " << temp->passengers << "\n";
			output << temp->passengers;
			output << "\n";


			if (temp->vehicle == "automobile")
			{
				cout << "Type: " << temp->CarType << "\n";
				output << temp->CarType + "\n";
				output << "\n";
			}
			else
			{
				cout << "Cargo: " << temp->cargo << "\n";
				output << temp->cargo;
				output << "\n";
			}

			temp = temp->next;
			cout << "\n" << endl;
		}
		output.close();
	}
	else
	{
		cout << "File failed to open " << "\n";
	}
}

int main()
{
	string newVechicle;
	road_vehicle*head = new road_vehicle(" ", 0, 0, 0, " ");

	while (true) {
		string vehicle;
		cout << "Is this an automobile or a truck? Enter 'automobile' or 'truck'" << endl;
		cin >> vehicle;
		cout << "\n";

		int wheels;
		cout << "How many wheels does this vehicle have? " << endl;
		cin >> wheels;
		cout << "\n";

		int passengers;
		cout << "How many passengers can this vehicle hold? " << endl;
		cin >> passengers;
		cout << "\n";

		//If statement is true "truck" output truck information
		if (vehicle == "truck")
		{
			int cargo;
			cout << "How much cargo (in pounds) can this vehicle hold? " << endl;
			cin >> cargo;
			cout << "\n";
			head->insert(vehicle, wheels, passengers, cargo, " ");
		}
		else
		{
			string AutoType;
			cout << "What type of automobile is this? Enter van, car, or wagon" << endl;
			cin >> AutoType;
			cout << "\n";
			head->insert(vehicle, wheels, passengers, 0, AutoType);
		}

		cout << "Would you like to enter another vehicle? yes or no" << endl;
		cin >> newVechicle;
		cout << "\n";

		if (newVechicle == "no") {
			break;
		}
	}
	head->printAll();
}

