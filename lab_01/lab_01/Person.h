#pragma once

#include <string>


// класс для хранения ФИО персон
class Person
{
private:
	std::string last_name;
	std::string middle_name;
	std::string first_name;

public:
	Person() {}
	Person(const Person& p)
		: first_name(p.first_name)
		, middle_name(p.middle_name)
		, last_name(p.last_name)
	{}

	const std::string& getLastName() const { return last_name; }
	const std::string& getMiddleName() const { return middle_name; }
	const std::string& getFirstName() const { return first_name; }

	void setLastName(const std::string& ln) { last_name = ln; }
	void setMiddleName(const std::string& mn) { middle_name = mn; }
	void setFirstName(const std::string& fn) { first_name = fn; };
};

