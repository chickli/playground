/*
 * shared.cpp
 *
 *  Created on: Aug 4, 2018
 *      Author: cli
 *
 *  The file shows how shared pointer works
 */

#include <iostream>
#include <memory>

using namespace std;

class Object
{
public:
	Object()
	{
		cout << "Constructing Object" << endl;
	}

	virtual ~Object()
	{
		cout << "Destructing Object" << endl;
	}
};

void mkSharedObject()
{
	cout << "\nWe're going to make a shared Object" << endl;
	shared_ptr<Object> sp = make_shared<Object>();
}

void shareObject()
{
	cout << "\nWe're going to create an Object and share it" << endl;
	Object* p = new Object;
	shared_ptr<Object> sp(p);
}

void shareMore()
{
	cout << "\nWe're going to create an Object and give it to more than one shared pointer" << endl;
	Object* p = new Object;
	cout << "assign Object pointer to sp1" << endl;
	shared_ptr<Object> sp1(p);
	cout << "Object use count is " << sp1.use_count() << " now" << endl;
	cout << "assign Object pointer to sp2" << endl;
	shared_ptr<Object> sp2(p); /* sp2 doesn't know the fact that p has already been assigned to sp1 */
	cout << "Object use count is " << sp2.use_count() << " now" << endl;
	cout << "assign Object pointer to sp3" << endl;
	shared_ptr<Object> sp3 = sp2;
	cout << "Object use count is " << sp3.use_count() << " now" << endl;
}

int main(int argc, char** argv)
{
    /* use make_shared to create shared object */
	mkSharedObject();

	/* share an existing object from a Object pointer */
	shareObject();

	/* sharing an existing object with multiple shared pointer will mess up the control block
	 * inside the shared_ptr */
	shareMore();

	return 0;
}


