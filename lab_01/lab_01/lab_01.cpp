#include <iostream>
#include <string>

#include "MyStack.h"
#include "Person.h"
#include "PersonKeeper.h"


int main()
{
	MyStack<std::string> stack(3);

	std::cout << "Trying to insert 5 elements to stack with capacity " << stack.capacity() << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::string str = "test string N_" + std::to_string(i);

		try
		{
			stack.push(str);
			std::cout << "Insert value: \"" << str << "\" to stack done, current stack size : "
				<< stack.size() << " / " << stack.capacity() << std::endl;
		}
		catch (const Exc::EStackOverflow& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "Trying read 5 values from stack with capacity " << stack.capacity() << std::endl;
	for (int i = 0; i < 5; i++)
	{
		try
		{
			std::string str = stack.pop();
			std::cout << "Reading done, value: \"" << str << "\"" << std::endl;
		}
		catch (const Exc::EStackEmpty& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	MyStack<Person> personStack = PersonKeeper::instance().readPersons("C:\\1\\test.txt");

	std::fstream outStream;
	outStream.open("C:\\1\\out.txt", std::ios_base::out);
	if (!outStream.is_open())
	{
		std::cerr << "Failed to open out stream\n";
		return 1;
	}

	std::cout << "Trying to write persons to file\n";
	PersonKeeper::instance().writePersons(personStack, outStream);

	std::cout << "Done" << std::endl;

	return 0;
}