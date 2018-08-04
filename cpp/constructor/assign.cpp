/*
 * assign.cpp
 *
 *  Created on: Aug 3, 2018
 *      Author: cli
 *
 *  The file shows assignment happens across objects
 */

#include <iostream>

using namespace std;

class Complex
{
public:
	Complex()
    : i(0.0), j(0.0)
    {
		cout << "Complex constructed: " << i << "+" << j << "j" << endl;
    }

	Complex(double a, double b)
	: i(a), j(b)
	{
		cout << "Complex constructed: " << i << "+" << j << "j" << endl;
	}

	virtual ~Complex()
	{
		cout << "Complex " << i << "+" << j << "j" << " destructed."<< endl;
	}

	/**
	 * Copy constructor is called when a new object is created, even if it is
	 * with a "="
	 */
#if _WITH_COPY_
	Complex(const Complex& copy)
	{
		i = copy.i;
		j = copy.j;

		cout << "Complex constructed from copy: " << i << "+" << j << "j" << endl;
	}
#endif

	/**
	 *  Assignment happens when a existing object is going to be changed from
	 * the other one
	 */
#if _WITH_ASSIGN_
	const Complex& operator=(const Complex& copy)
	{
		i = copy.i;
		j = copy.j;

		cout << "Complex assigned from copy: " << i << "+" << j << "j" << endl;
	}
#endif

private:
	double i;
	double j;
};

int main(int argc, char** argv)
{
	cout << "\nconstruct a complex a:" << endl;
	Complex a(1.0, 1.0);

	cout << "\nconstruct a complex b from a" << endl;
	Complex b = a;

	cout << "\nconstruct a complex c:" << endl;
	Complex c(7.3, 6.1);

	cout << "\nassign complex c to b" << endl;
	b = c;

	cout << "\nwe're all set" << endl;

	return 0;
}
