// Program 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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


void road_vehicle::printAll() {

	road_vehicle *temp = next;

	while (temp != NULL) {
		cout << "{\"road_vehicle\": \"" << temp->vehicle << "\",";
		cout << "\"Wheels\": " << temp->wheels << ",";
		cout << "\"Passengers\": " << temp->passengers << ",";

		if (temp->vehicle == "Automobile") 
		{
			cout << "\"Type\": " << temp->CarType << "\"}\n";
		}
		else 
		{
			cout << "\"Cargo\": " << temp->cargo << "}\n";
		}
		temp = temp->next;
	}
}

int main() {
	string newVehicle;
	string line;
	road_vehicle *head = new road_vehicle(" ", 0, 0, 0, " ");

	ifstream file("output.txt");

	if (file.is_open()) {
		while (getline(file, line)) {
			string car = line;

			//Wheel variable
			int wheels;
			getline(file, line);
			stringstream cast(line);
			cast >> wheels;

			//Passenger variable
			int passengers;
			getline(file, line);
			stringstream cast2(line);
			cast2 >> passengers;

			// If statement is true, it will output truck variable
			if (car == "truck") {
				int cargo;
				getline(file, line);
				stringstream cast3(line);
				cast3 >> cargo;
				head->insert(car, wheels, passengers, cargo, " ");

			}
			else {
				string autotype;
				getline(file, line);
				autotype = line;
				head->insert(car, wheels, passengers, 0, autotype);
			}
		}
		file.close();
		head->printAll();
	}
	else 
	{
		cout << "File cannot open" << endl;
	}
}