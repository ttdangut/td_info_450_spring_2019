// program1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



//Define parent class VECHILE 
	class road_vehicle
	{
		int wheels;
		int passengers;
		string vehicle;
		string cartype;


	public:
		void set_wheels(int num) {
			wheels = num;
		}
		int get_wheels() {
			return wheels;
		}
		void set_passengers(int num) {
			passengers = num;
		}
		int get_passengers() {
			return passengers;
		}
		void set_vehicle(string str)
		{
				vehicle = str;
		}
		string get_vehicle()
		{
			return vehicle;
		}
		string get_str()
		{
			return cartype;
		}

	};


	//Define class child TRUCK
	class truck : public road_vehicle
	{
		int cargo;
	public:
		void set_cargo(int size) {
			cargo = size;
		}
		int get_cargo() {
			return cargo;
		}
	};


	//Define class child AUTOMOBILE
	enum type { car, van, wagon };
	class automobile : public road_vehicle
	{
		enum type car_type;
	public:
		void set_type(type t) { car_type = t; }
		enum type get_type() { return car_type; }

	};

	// Node linked list declare
	class node
	{
	public:
		road_vehicle data;
		node *next;
		node()
		{
			next = NULL;
		}
		void insert(road_vehicle data);
		void print_data();
	};

	ostream &operator<<(ostream &stream, road_vehicle data)
	{
		stream << data.get_vehicle() << endl;
		stream << data.get_wheels() << endl;
		stream << data.get_passengers() << endl;
		stream << data.get_str() << endl;
		return stream;
	}
	void node::print_data() {
		cout << data << endl;

		if (next != NULL) { return next->print_data(); }

	}
	void node::insert(road_vehicle v)
	{
		if (next == NULL) {
			next = new node;
			next->data = v;
		}
		else {
			next->insert(v);
		}
	}


int main()

//Inserter to output
{
	ofstream out;
	out.open("output.txt");
	if (!out)
	{
		cout << "Cannot open file." << endl;
		return 1;
	}
	if (!out.is_open())
	{
		cout << "File is not open." << endl;
		return 2;
	}

	{
		//Declaration 
		int wheels;
		int passengers;
		string vehicleType;
		string Type2;
		int addMoreVehicles = 1;
		node linked_list;
		road_vehicle vehicle;
		char *myvalue = (char *)malloc(255);

		while (addMoreVehicles == 1)
		{
			cout << "Is this an automobile or a truck? Enter automobile or truck?" << endl;
			cin >> vehicleType;
			out << "Vehicle";

			// If statement is true "truck" output truck information 
			if (vehicleType == "truck")
			{
				cout << "How many wheels does this vehicle have?" << endl;
				cin >> wheels;
				out << "Wheels";
				out << wheels;

				cout << "How many passengers can this vehicle?" << endl;
				cin >> passengers;
				out << "Passengers";
				out << passengers;

				cout << "How much cargo (in pounds) can this vehicle hold?" << endl;
				int cargo = 0;
				cin >> cargo;
				out << "Cargo(lbs)";
				out << cargo;
			}

			// If statement is automobile, output automobile information.
			else if (vehicleType == "automobile")
			{

				cout << "How many wheels does this vehicle have?" << endl;
				cin >> wheels;
				out << "Wheels";
				out << wheels;

				cout << "How many passengers can this vehicle?" << endl;
				cin >> passengers;
				out << "passengers";
				out << passengers;

				cout << "What type of automobile is this? Enter van, car or wagon" << endl;
				cin >> Type2;
				out << "Automobile type";
				out << Type2;
			}
			else 
			{
				cout << "What did you type? Try again" << endl;
				cin >> Type2;
			}

			out << vehicle;
			linked_list.insert(vehicle);

			cout << "Would you like to enter another vehicle? Enter yes or no" << endl;
				cin.ignore();
				cin.getline(myvalue, 255);
			

			if (!strcmp(myvalue, "no"))
			{
				addMoreVehicles = 0;
			}
		linked_list.print_data();
		}
	}


return 0;

}


			


				

			
	

		
