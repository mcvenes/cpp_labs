#pragma once

#include "EStack.h"


// Шаблонный класс MyStack, в котором вместо Т может быть какой-то тип: int, double ...
template <typename T>
class MyStack {
public:
	// конструктор
	MyStack(size_t size)
		: maxSize(size)
		, currentSize(0)
	{
		data = new T[size]; //выделяем память под данные 
	};

	// В десттрукторе освобождаем память
	~MyStack() {
		delete[] data;
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

	// Метод добавления в конец
	void push(const T& value) {
		if (isFull()) {
			// Если currentSize == maxSize, значит мы заполнили все имеющиеся ячейки - переполнение
			throw Exc::EStackOverflow("Size limit of MyStack is reached!");
		}

		data[currentSize] = value;
		++currentSize;
	}

	// Метод удаления из конца
	const T& pop() {
		if (isEmpty()) {
			// Если так, то стек пуст и бросаемм исключение
			throw Exc::EStackEmpty("This instance of MyStack is empty!");
		}

		--currentSize;
		return data[currentSize];
	}

private:
	T* data; // указатель на данные в куче

	size_t maxSize; // храним максимально допустимый размер
	size_t currentSize; // индекс элемента за последним на данный момент
};
