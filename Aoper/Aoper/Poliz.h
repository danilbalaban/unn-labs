/*
#pragma once
#include <string>
#include "Stack.h"
#include "Table.h"
class Poliz
{
private:
	std::string* mem;
	int size;
	int count;
	string* lex;
	int size_lex;
	int count_lex;
	Stack<TRecord>OPStack;
	Table TableOperation;
	Table* Table_Operand;
	void MadeTableOperation();
	void Work_Left();
	void Work_Right();
	void Work_Operation();
	void Work_Operand();
	void Work_End();
	void Made_Poliz();
	void StringtoWord(string str, string* _lex, int count_lex);
public:
	Poliz(string tmp = "");
	Poliz(const Poliz& tmp);
	~Poliz();
	Poliz& operator =(Poliz tmp);
	int getCount();
	string operator[](int k);
	string getPoliz();
	Table* getTableOperand();

	void MadeTableOperation()
	{
		TableOperation = Table(6);
		TableOperation.Add(TRecord("+", 1));
		TableOperation.Add(TRecord("-", 1));
		TableOperation.Add(TRecord("*", 2));
		TableOperation.Add(TRecord("/", 2));
		TableOperation.Add(TRecord("^", 2));
	}
	void Work_Left()
	{
		OPStack.add(TRecord("(", 0));
	}
	void Work_Right()
	{
		while ((OPStack.isEmpty() == 0) && (OPStack.top().getname() != "("))
		{
			mem[count++] = OPStack.get().getname();
		}
		if (OPStack.top().getname() == "(")
		{
			OPStack.get();
		}
	}
	void Work_Operand(string st)
	{
		mem[count++] = st;
		if ((st[0] >= '0') && (st[0] <= '9'))
		{
			Table_Operand(TRecord(st, int(st)));
		} 
		else {
			Table_Operand(TRecord(st, 0));
		}
	}
	void Work_End()
	{
		while (OPStack.isEmpty() == 0)
		{
			mem[count++] = OPStack.get().getname();
		}
	}
	void Made_Poliz(string str)
	{
		count = 0;
		for (int i = 0; i < lex.length(); i++)
		{
			if (lex[i] == "(")
			{
				Work_Left();
			}
			else {
				int l = TableOperation.Search(lex[i]);
				if (l > 0 && l <= 3)
				{
					Work_Operation(lex[i], l);
				}
				else {
					Work_Operand(lex[i]);
				}
			    }
		}
		Work_End();
	}
};
*/