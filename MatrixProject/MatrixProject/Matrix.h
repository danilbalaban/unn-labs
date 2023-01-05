#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Matrix
{
private:
	T** mem;
	int size;

public:
	Matrix(int _size = 0)
	{
		size = _size;
		mem = new T * [size];

		for (int i = 0; i < size; i++)
		{
			mem[i] = new T[size - i];

			for (int j = 0; j < size - i; j++)
				mem[i][j] = 0;
		}
	}

	Matrix(const Matrix& tmp)
	{
		size = tmp.size;
		mem = new T * [size];

		for (int i = 0; i < size; i++)
			mem[i] = new T[size - i];

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size - i; j++)
				mem[i][j] = tmp.mem[i][j];
	}

	~Matrix()
	{
		for (int i = 0; i < size; i++)
			delete[] mem[i];
		delete[] mem;
	}

	void getData() // метод вывода значений матрицы в консоль
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - i; j++)
			{
				cout << mem[i][j] << " ";
			}
			cout << endl;
		}
	}

	Matrix<T>& operator=(const Matrix& tmp)
	{
		if (size != tmp.size)
		{
			for (int i = 0; i < size; i++)
				delete[] mem[i];
			delete[] mem;

			size = tmp.size;

			mem = new T * [size];

			for (int i = 0; i < size; i++)
				mem[i] = new T[size - i];
		}
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size - i; j++)
				mem[i][j] = tmp.mem[i][j];

		return *this;
	}

	T* operator[](int i)
	{
		return this->mem[i];
	}

	int getSize() 
	{
		return this->size;
	}

	template<typename T>
	friend std::ostream& operator << (std::ostream& out, const Matrix<T>& matrix);

	template<typename T>
	friend std::istream& operator >> (std::istream& in, Matrix<T>& matrix);
};

template<typename T>
std::ostream& operator << (std::ostream& out, const Matrix<T>& matrix)
{
	for (int i = 0; i < matrix.size; i++)
	{
		for (int j = 0; j < matrix.size; j++)
		{
			if (j >= i)
				out << matrix.mem[i][j - i] << "  ";
			else
				out << "0  ";
		}
		out << endl;
	}

	return out;
}

template<typename T>
std::istream& operator >> (std::istream& in, Matrix<T>& matrix)
{
	for (int i = 0; i < matrix.size; i++)
		for (int j = 0; j < matrix.size - i; j++)
			in >> matrix[i][j];

	return in;
}