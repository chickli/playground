/*
 * create.cpp
 *
 *  Created on: Aug 3, 2018
 *      Author: cli
 *
 *  The file shows how cpp instances are constructed in a hierarchical way
 */

#include <iostream>

using namespace std;

class Vehicle
{
public:
	Vehicle()
    {
		cout << "Constructing a vehicle" << endl;
    }
};

class Engine
{
public:
	Engine()
    {
		cout << "Constructing an engine" << endl;
    }
};

class GasolineEngine : public Engine
{
public:
	GasolineEngine()
    {
		cout << "Constructing a gasoline engine" << endl;
    }
};

class DieselEngine : public Engine
{
public:
	DieselEngine()
    {
		cout << "Constructing a diesel engine" << endl;
    }
};
class Wheel
{
public:
	Wheel()
    {
		cout << "Constructing a wheel" << endl;
	}
};

class Car : public Vehicle
{
public:
	Car()
    {
		cout << "Constructing a car" << endl;
    }

private:
	GasolineEngine engine;
	Wheel wheels[4];
};

class Truck : public Vehicle
{
public:
	Truck()
    {
		cout << "Constructing a truck" << endl;
    }

private:
	DieselEngine engine;
	Wheel wheels[6];
};

Truck truck;

int main(int argc, char** argv)
{
	cout << "We are going to construct a car" << endl;

    Car car;

    cout << "We have a car constructed" << endl;

    return 0;
}


