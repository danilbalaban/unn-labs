#pragma once
#include <iostream>
#include <string>
using namespace std;

class TRecord
{
private:
	string name;
	int value;
public:
	TRecord(string _name = "", int _value = 0)
	{
		name = _name;
		value = _value;
	}
	TRecord(const TRecord& copy) {
		name = copy.name;
		value = copy.value;
	}

	~TRecord() {
	
	}

	void setvalue(int k) {
		value = k;
	}
	int getvalue() {
		return value;
	}
	string getname() {
		return name;
	}
};

