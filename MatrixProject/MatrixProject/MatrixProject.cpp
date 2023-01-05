
#include <iostream>
#include <clocale>
#include "Matrix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;

	cout << "Введите размер матриц: " << endl;
	cin >> n;

	Matrix<int> a(n);

	cout << "Введите матрицу: " << endl;

	cin >> a;

	cout << "Матрица A : " << endl << a << endl;
	
	return 0;
}