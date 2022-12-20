#include <iostream>
#include <clocale>
#include "Table.h"
#include "TRecord.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	Table A(3);
	Table B(3);

	TRecord r1("r1", 1);
	TRecord r2("r2", 2);
	TRecord r3("r3", 3);
	
	if (A.IsEmpty() == 1)
	{
		cout << "A ����" << endl;
	}
	else {
		cout << "A �� ����" << endl;
	};
	if (B.IsEmpty() == 1)
	{
		cout << "B ����" << endl;
	}
	else {
		cout << "B �� ����" << endl;
	};


	//����������

	A.Add(r1);
	A.Add(r2);
	A.Add(r3);

	Table F(A);
	cout << "����� F" << endl;
	for (int i = 0; i < F.getcount(); i++) {
		cout << F[i].getname() << " " << F[i].getvalue() << endl;
	}

	cout << "���������� ���������" << endl;
	cout << "�����:" << endl;
	for (int i = 0; i < A.getcount(); i++) {
		cout << A[i].getname() << " " << A[i].getvalue() << endl;
	}
	cout << endl;


	cout << "R1 �� �������:" << A.Search("r1") << endl;
	cout << "R1 �� �������:" << A.Search("r2") << endl;
	cout << "R3 �� �������:" << A.Search("r3") << endl;

	cout << endl;
	
	//��������

	A.Del(r1);
	
	cout << "A ����� �������� r1" << endl;
	for (int i = 0; i < A.getcount(); i++) {
		cout << A[i].getname() << " " << A[i].getvalue() << endl;
	}


	//�������������
	B = A;
	cout << "� ����� ������������" << endl;

	for (int i = 0; i < B.getcount(); i++) {
		int k = B[i].getvalue();
		string st = B[i].getname();

		cout << B[i].getname() << " " << B[i].getvalue() << endl;
	}


	cout << "R2 �� �������:" << B.Search("r2") << endl;

}