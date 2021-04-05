//#include "Person.h"
#include "Tweeter.h"
#include "status.h"
#include <iostream>

using namespace std;

int main()
{
	//construct objects of the class Person
	Person p1("Job", "Dulo", 27);
	Person p2("Kate", "Gregory", 31);
	string name = p1.getName();
	int age = p1.getAge();

	//cout << "Person 1 name is " << name << endl;
	//cout << "Person 1 age is " << age << endl;

	//construct a tweeter istance
	{
		Tweeter t1("John", "Doe", 24, "@jdoe");
		string name2 = t1.getName(); //getName() inherited from Person

	} //signifies end of the Tweeter scope

	cout << "after innermost block" << endl;

	//assign old enum
	Status s = Pending;
	s = Approved;

	//assign scoped enum use fully qualified name
	FileError fe = FileError::notfound;
	fe = FileError::ok;
	
	return 0;
}