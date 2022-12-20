#pragma once
#include "TRecord.h"
using namespace std;

class Table
{
private:
	TRecord* mem;
	int count;
	int size;

public:
	Table(int _size = 0) 
	{
		size = _size;
		count = 0;

		mem = new TRecord[size];

		for (int i = 0; i < size; i++)
			mem[i] = TRecord("", 0);
	};

	Table(const Table& copy) 
	{
		size = copy.size;
		count = copy.count;

		mem = new TRecord[size];

		for (int i = 0; i < size; i++)
		{
			mem[i] = copy.mem[i];
		}
	};
	~Table() 
	{
		if (size != 0)
		{
			delete[] mem;
		}
	};

	Table& operator=(Table copy) 
	{
		if (size != copy.size)
		{
			if (size > 0)
			{
				delete[] mem;
			}

			size = copy.size;

			mem = new TRecord[size];
		}

		count = copy.count;

		for (int i = 0; i < size; i++)
		{
			mem[i] = copy.mem[i];
		}

		return (*this);
	};

	TRecord operator[](int k) 
	{
		if ((k >= 0) && (k <= count))
		{
			return mem[k];
		}

		return TRecord("", 0);
	};

	void Add(TRecord tmp)
	{
		int l = getnumber(tmp.getname());

		if (l == -1) {
			mem[count++] = tmp;
		}
		else {
			mem[l] = tmp;
			++count;
		}
	};
	void Del(TRecord tmp) 
	{
		int l = getnumber(tmp.getname());

		if (l >= 0) {
			mem[l] = mem[--count];
		}
	};

	int Search(string key)
	{
		int l = getnumber(key);

		if (l >= 0)
		{
			return mem[l].getvalue();
		}

		return -1;
	};
	int IsEmpty() 
	{
		if (count == 0) {
			return 1; //Пуст
		}
		else {
			return 0;//Не пуст
		}
	};
	int IsFull() 
	{
		if (count == size)
		{
			return 1;
		}				//ПОЛОН
		else
		{
			return 0;
		}				//не полон
	};
	int getcount() 
	{ 
		return count; 
	};
private:
	int getnumber(string key)
	{
		int l = -1;
		int i = 0;

		while ((l == -1) && (i < count))
		{
			if (key == mem[i].getname())
			{
				l = i;
			}
			i++;
		}
		return l;
	};
};
