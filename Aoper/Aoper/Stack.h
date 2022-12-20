#pragma once
#include <iostream>
template <class T>

class Stack
{
private:
	T* mem;
	int size;
	int count;
public:
	Stack(int _size = 0)
	{
		size = _size;
		count = 0;
		mem = new T[size];
		for (int i = 0; i < size; i++) {
			mem[i] = T(0);
		}
	}
	Stack(const Stack& tmp)
	{
		size = tmp.size;
		count = tmp.count;
		mem = new T[size];
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
	}
	~Stack()
	{
		if (size != 0) {
			delete[] mem;
		}
	}
	Stack<T>& operator=(const Stack<T>& tmp)
	{
		if (size != tmp.size)
		{
			if (size != 0)
			{
				delete[]mem;
			}

			size = tmp.size;

			mem = new T[size];
		}

		count = tmp.count;

		for (int i = 0; i < size; ++i) {
			mem[i] = tmp.mem[i];
		}

		return *this;
	}
public:
	void add(T tmp)
	{
		if (count < size) {
			mem[count++] = tmp;
		}
	}
	T get() {
		if (count > 0) {
			return mem[--count];
		}
	}
	T top() {
		if (count > 0) {
			return mem[count - 1];
		}
	}
	int isEmpty() {
		if (count == 0) {
			return 1; //Стек пуст
		}
		else {
			return 0; // Стек не пуст
		}
	}
	int isFull() {
		if (count == size) {
			return 1;//Стек полон
		}
		else {
			return 0;//Стек не полон
		}
	}
};