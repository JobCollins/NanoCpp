#include "Tweeter.h"
#include <iostream>

//initialize member variables in Tweeter class using
//the constructor in Tweeter.h
Tweeter::Tweeter(std::string first, std::string last, int age, std::string handle) :
	//Person(first, last, age) gives the first three member variables bc of inheritance
	Person(first, last, age), twitterhandle(handle) 
{
	std::cout << "constructing tweeter" << twitterhandle << std::endl;
}

Tweeter::~Tweeter()
{
	std::cout << "destructing tweeter" << twitterhandle << std::endl;
}