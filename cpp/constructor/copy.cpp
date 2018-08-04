/*
 * copy.cpp
 *
 *  Created on: Aug 3, 2018
 *      Author: cli
 *
 *  The file shows how cpp instances are constructed from exisiting ones
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

	Vehicle(const Vehicle& copy)
	{
		cout << "Constructing vehicle from a copy" << endl;
	}
};

class Engine
{
public:
	Engine()
    {
		cout << "Constructing an engine" << endl;
    }

	Engine(const Engine& copy)
	{
		cout << "Constructing engine from a copy" << endl;
	}
};

class GasolineEngine : public Engine
{
public:
	GasolineEngine()
    {
		cout << "Constructing a gasoline engine" << endl;
    }

	GasolineEngine(const GasolineEngine& copy)
	{
		cout << "Constructing gasoline engine from a copy" << endl;
	}
};

class DieselEngine : public Engine
{
public:
	DieselEngine()
    {
		cout << "Constructing a diesel engine" << endl;
    }

	DieselEngine(const DieselEngine& copy)
	{
		cout << "Constructing diesel engine from a copy" << endl;
	}
};
class Wheel
{
public:
	Wheel()
    {
		cout << "Constructing a wheel" << endl;
	}

	Wheel(const Wheel& copy)
	{
		cout << "Constructing wheel from a copy" << endl;
	}
};

class Car : public Vehicle
{
public:
	Car()
    {
		cout << "Constructing a car" << endl;
    }

	Car(const Car& copy)
#if _ALLOW_BACKTRACE_COPY_
	:Vehicle(copy)
#endif
	{
		cout << "Constructing car from a copy" << endl;
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

	Truck(const Truck& copy)
#if _ALLOW_BACKTRACE_COPY_
	:Vehicle(copy)
#endif
    {
		cout << "Constructing truck from a copy" << endl;
    }

private:
	DieselEngine engine;
	Wheel wheels[6];
};

Vehicle vehicle;

static Truck createTruck(const Truck truck);

int main(int argc, char** argv)
{
    /*
	 * creating a sub class instance from a base class instance is NOT allowed without
	 * an explicit type casting copy constructor being defined */
#if _ALLOW_ERRORS_
	cout << "We are going to construct car from a vehicle" << endl;
    Car car = vehicle;
    cout << "We have a car constructed" << endl;
#endif

    cout << "\nWe are going to construct a truck" << endl;
    Truck truck;
    cout << "We have a truck constructed" << endl;

    /* copy constructor of base class will be invoked when an instance of base
     * class is created from a copy (a truck instance here)
     */
    cout << "\nWe are going to construct vehicle from a truck" << endl;
    Vehicle vehicle = truck;
    cout << "We have a vehicle constructed" << endl;

    /* copy constructor of base class won't be invoked by default when a sub class
     * instance is created from a copy.
     * it is recommended to invoke base constructor of sub class in the copy constructor
     * of sub class explicitly to allow copy happen all the way down the construct hierarchy
     */
    cout << "\nWe are going to construct truck from a truck" << endl;
    Truck truck2 = truck;
    cout << "We have another truck constructed" << endl;

    cout << "\nWe are going to construct truck using a function" << endl;
    Truck truck3 = createTruck(truck);
    cout << "We have another truck constructed" << endl;
    return 0;
}

/*
 * When the function is called, copy constructor of class Truck will be called twice
 * during parameter transfer and value return respectively
 */
Truck createTruck(const Truck truck)
{
	return truck;
}


