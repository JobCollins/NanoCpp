#include "Person.h"

int main()
{
	//construct objects of the class Person
	Person p1("Job", "Dulo", 27);
	Person p2("Kate", "Gregory", 31);
	string name = p1.getName();
	int age = p1.getAge();

	cout << "Person 1 name is " << name << endl;
	cout << "Person 1 age is " << age << endl;
	return 0;
}