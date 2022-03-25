#include <iostream>
#include <string>

#include "MyStack.h"


int main()
{
	std::cout << "Hello World!\n";

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

	return 0;
}