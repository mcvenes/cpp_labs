#pragma once

#include "EStack.h"


// ��������� ����� MyStack, � ������� ������ � ����� ���� �����-�� ���: int, double ...
template <typename T>
class MyStack {
public:
	// �����������
	explicit MyStack(size_t size)
		: maxSize(size)
		, currentSize(0)
	{
		data = new T[size]; //�������� ������ ��� ������ 
	};

	// � ������������ ����������� ������
	~MyStack() {
		// do nothing
	}

	bool isFull() const
	{
		return (currentSize == maxSize);
	}

	bool isEmpty() const
	{
		return (currentSize == 0);
	}

	size_t size() const {
		return currentSize;
	}

	size_t capacity() const {
		return maxSize;
	}

	// ����� ���������� � �����
	void push(const T& value) {
		if (isFull()) {
			// ���� currentSize == maxSize, ������ �� ��������� ��� ��������� ������ - ������������
			throw Exc::EStackOverflow("Size limit of MyStack is reached!");
		}

		data[currentSize] = value;
		++currentSize;
	}

	// ����� �������� �� �����
	const T& pop() {
		if (isEmpty()) {
			// ���� ���, �� ���� ���� � �������� ����������
			throw Exc::EStackEmpty("This instance of MyStack is empty!");
		}

		--currentSize;
		return data[currentSize];
	}

private:
	T* data; // ��������� �� ������ � ����

	size_t maxSize; // ������ ����������� ���������� ������
	size_t currentSize; // ������ �������� �� ��������� �� ������ ������
};
