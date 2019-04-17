// program 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
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


int main() {

	road_vehicle vechicle;
	node linked_list;
	string line;
	char str[255];
	ifstream myfile("output.txt");


	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//I'm not sure why it wont define getline 
			string car = line;
			int wheels;
			getline(file, line);
			stringstream cast(line);
			cast >> wheels;
			int passengers;
			getline(file, line);
			stringstream cast2(line);
			cast2 >> passengers;
			if (car == "truck")
			{
				int cargo;
				getline(file, line);
				stringstream cast3(line);
				cast3 >> cargo;
				head->insert(car, wheels, passengers, cargo, " ");
			}
			else
			{
				string type;
				getline(file, line);
				type = line;
				head->insert(car, wheels, passengers, 0, type);
			}
		}
		file.close();
		head->printAll();
	}
	else
	{
		cout << "File failed to open";
	}
}