#pragma once
#include <string>
#include <string.h>

using namespace std;

class TBitField
{
private:
    unsigned int* mem;
    int size;
    //k - Номер эл-та юниверса, который хотим добавить universe > k >= 1

    int GetNumberMem(unsigned int k, unsigned int universe)
    {
        int l = -1;
        if (k >= 1 && k < universe)
            l = (k - 1) / (sizeof(int) * 8);
        return l;
    }

    int GetNumberBit(unsigned int k, unsigned int universe)
    {
        int l = -1;
        if (k >= 1 && k < universe)
            l = (k - 1) % (sizeof(int) * 8);
        return l;
    }

public:
    TBitField(int universe = 0)
    {
        size = universe / (sizeof(int) * 8) + 1;
        mem = new unsigned int[size];
        for (int i = 0; i < size; i++)
        {
            mem[i] = 0;
        }
    }

    TBitField(const TBitField& tmp)
    {
        size = tmp.size;
        mem = new unsigned int[size];
        for (int i = 0; i < size; i++)
            mem[i] = tmp.mem[i];
    }

    ~TBitField()
    {
        delete[] mem;
    }

    TBitField& operator=(TBitField tmp)
    {
        if (size != tmp.size)
        {
            if (size != 0)
                delete[] mem;
            size = tmp.size;
            mem = new unsigned int[size];
        }

        for (int i = 0; i < size; i++)
            mem[i] = tmp.mem[i];
        return *this;
    }

    void Add(unsigned int k, unsigned int universe)
    {
        int pos = GetNumberBit(k, universe);
        int m = GetNumberMem(k, universe);
        mem[m] = mem[m] | (1 << pos);
    }

    string TBitFieldToString(unsigned int universe)
    {
        string STR = "";
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < (sizeof(unsigned int) * 8); j++)
            {
                int k = i * (sizeof(unsigned int) * 8) + j + 1;
                if (k <= universe)
                {
                    if (mem[i] & (1 << j))
                    {
                        STR = STR + to_string(k) + " "; //к в строковой форме
                    }
                }
            }
        }
        //STR.pop_back();
        return STR;
    }

    void del(unsigned int k, unsigned int universe)
    {
        if (k > 0 && k <= universe)
        {
            int pos = GetNumberBit(k, universe);
            int m = GetNumberMem(k, universe);
            mem[m] = mem[m] & (~(1 << pos));
        }
    }

    TBitField operator & (TBitField tmp)
    {
        TBitField res;
        if (size == tmp.size)
        {
            res = TBitField(*this);
            for (int i = 0; i < size; i++)
                res.mem[i] = mem[i] & tmp.mem[i];
        }
        return res;
    }

    TBitField operator | (TBitField tmp)
    {
        TBitField res;
        if (size == tmp.size)
        {
            res = TBitField(*this);
            for (int i = 0; i < size; i++)
                res.mem[i] = mem[i] | tmp.mem[i];
        }
        return res;
    }
    TBitField operator ~ ()
    {
        TBitField res(*this);
        for (int i = 0; i < size; i++)
        {
            res.mem[i] = ~mem[i];
        }
        return res;
    }
};