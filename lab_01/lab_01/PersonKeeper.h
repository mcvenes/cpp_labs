#pragma once

#include "Person.h"
#include "MyStack.h"

#include <iostream>
#include <fstream>
#include <string>

class PersonKeeper
{
public:
	static PersonKeeper& instance()
	{
		static PersonKeeper p;
		return p;
	}

	MyStack<Person> readPersons(const std::string& filePath) const;
	void writePersons(MyStack<Person> stack, std::fstream &stream);

private:
	PersonKeeper() {}
};

