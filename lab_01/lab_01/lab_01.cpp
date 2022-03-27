#include <iostream>
#include <string>

#include "MyStack.h"
#include "Person.h"
#include "PersonKeeper.h"


int main(int argc, char** argv)
{
    // Проверяем, что кол-во аргументов равно 3: имя программы + путь к файлу для чтения + путь к файлу с результатом
    if (argc != 3)
    {
        std::cerr << "Usage: lab01.exe <path to input file> <path to output file>" << std::endl;
        std::cerr << "For example, lab01.exe C:\\1\\test.txt C:\\1\\result.txt" << std::endl;
        return 1;
    }

    const std::string inputFilePath = argv[1];
    const std::string outputFilePath = argv[2];

	// ---- лаб.1 - часть 1 ------------------------

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


	// ---- лаб.1 - часть 2 ------------------------

	MyStack<Person> personStack = PersonKeeper::instance().readPersons(inputFilePath, 100);

	std::fstream outStream;
	outStream.open(outputFilePath, std::ios_base::out);
	if (!outStream.is_open())
	{
		std::cerr << "Failed to open output file " << outputFilePath << std::endl;
		return 1;
	}

	std::cout << "Trying to write persons to file\n";
	PersonKeeper::instance().writePersons(personStack, outStream);

	std::cout << "Done" << std::endl;

	return 0;
}