#include <string>
#include <iostream>

using namespace std;

class Person
{
private:
	string firstname;
	string lastname;
	int personage;

public:
	//make a constructor to make objects
	Person(string first, string last, int age);
	string getName();
	int getAge();
};

