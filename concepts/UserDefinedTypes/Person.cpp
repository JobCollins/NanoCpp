#include <string>
#include "Person.h"


using namespace std;

//object that has copy of member variables from the class Person
//initialize each member variables
Person::Person(string first, string last, int age): firstname(first), lastname(last), personage(age)
{
	cout << "constructing " << firstname << " " << lastname << endl;
}

string Person::getName()
{
	return firstname + " " + lastname;
}

int Person::getAge()
{
	return personage;

}