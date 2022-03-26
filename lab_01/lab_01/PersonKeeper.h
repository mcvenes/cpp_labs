#pragma once

#include "Person.h"
#include "MyStack.h"

#include <iostream>
#include <fstream>
#include <string>

// ����� ��� ������ � ������ ������ �� �������� �������
class PersonKeeper
{
public:
	// ����������� ����� ��� ��������� � ������������� ���������� ������ (singletone)
	static PersonKeeper& instance()
	{
		static PersonKeeper p;
		return p;
	}

	// ����� ������ ������ �� ����� filePath
	// ���������� ���� �������� ������ Person
	MyStack<Person> readPersons(const std::string& filePath, int maxSize) const;

	// ����� ������ ����� ������ � �����
	// stack �������� ��� �����, �.�. � ���� ������ ������������ ������ �� ������ ��������
	void writePersons(MyStack<Person> stack, std::fstream &stream);

private:
	// ��������� �����������, �.�. singletone
	PersonKeeper() {}
};

