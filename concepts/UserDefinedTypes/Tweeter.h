#pragma once
#include "Person.h"
#include <string>

//declare class Tweeter and make it inherit from class Person
class Tweeter :
	public Person
{
private:
	std::string twitterhandle;
public:
	Tweeter(std::string first,
		std::string last,
		int age,
		std::string handle);
	//destructor
	~Tweeter(); 
};