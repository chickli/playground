/*
 * vtable.cpp
 *
 *  Created on: Aug 3, 2018
 *      Author: cli
 *
 *  The file shows how polymorphism is implemented in cpp using virtual table
 */

#include <iostream>

using namespace std;

static void showObject(void *this_)
{
  void **ugly = reinterpret_cast<void**>(this_);
  cout << "vptr pointed to " << ugly[0] << endl;
}


class Engine
{
public:
	Engine()
    {
		cout << "Constructing an engine" << endl;
		showObject(this);
		cout <<"vptr to the virtual table not reliable so far, don't call virtual method!" << endl;
    }

	virtual void start()
	{
		cout << "Abstract Engine can't start" << endl;
		showObject(this);
	}
};

class GasolineEngine : public Engine
{
public:
	GasolineEngine()
    {
		cout << "Constructing a gasoline engine" << endl;
		showObject(this);
		cout <<"vptr to the virtual table not reliable so far, don't call virtual method!" << endl;
    }

	virtual void start()
	{
		cout << "Starting gasoline engine... Started!" << endl;
		showObject(this);
	}
};

class DieselEngine : public Engine
{
public:
	DieselEngine()
    {
		cout << "Constructing a diesel engine" << endl;
		showObject(this);
		cout <<"vptr to the virtual table not reliable so far, don't call virtual method!" << endl;
    }

	virtual void start()
	{
		cout << "Starting diesel engine... Started!" << endl;
		showObject(this);
	}
};

int main(int argc, char** argv)
{
	cout << "\nWe're going to try a gasoline engine" << endl;
	Engine* engine = new GasolineEngine;
	engine->start();
	delete engine;

	cout << "\nWe're going to try a diesel engine" << endl;
	engine = new DieselEngine;
	engine->start();
	delete engine;

	/* the new gasoline engine instance shares the same vtable as the previous
	 * one, since they belong to the same type */
	cout << "\nWe're going to try a gasoline engine again" << endl;
	engine = new GasolineEngine;
	engine->start();
	delete engine;

    return 0;
}


