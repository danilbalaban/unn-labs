#pragma once
#include "TBitField.h"

class TSet
{
private:
    int universe;
    TBitField TB;
public:
    TSet(int _universe = 0)
    {
        universe = _universe;
        TB = TBitField(universe);
    }
    TSet(const TSet& tmp)
    {
        universe = tmp.universe;
        TB = tmp.TB;
    }
    TSet& operator=(TSet tmp)
    {
        if (universe != tmp.universe)
        {
            universe = tmp.universe;
        }
        TB = tmp.TB;
        return(*this);
    }
    ~TSet()
    {

    }

    void Add(int k)
    {
        TB.Add(k, universe);
    }

    void del(int k)
    {
        TB.del(k, universe);
    }

    string TSetToString()
    {
        return TB.TBitFieldToString(universe);
    }

    TSet operator&(TSet tmp)
    {
        TSet res;

        if (universe == tmp.universe)
        {
            res = TSet(*this);
            res.TB = TB & tmp.TB;
        }
        return res;
    }

    TSet operator|(TSet tmp)
    {
        TSet res;
        if (universe == tmp.universe)
        {
            res = TSet(*this);
            res.TB = TB | tmp.TB;
        }
        return res;
    }

    TSet operator~()
    {
        TSet res(*this);
        res.TB = ~TB;
        return res;
    }
};