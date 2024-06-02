#include <iostream>
#include "set.h"
void CSet::print()
{
    std::cout << '[';
    for (int el : els) std::cout << el << ',';
    std::cout << ']';
}
void CSet::include(int el)
{
    els.push_back(el);
    size++;
}
void CSet::exclude(int el)
{
    for (int i = 0; i < size; i++)
    {
        if (els[i] == el)
        {
            els.erase(els.begin() + i);
            size--;
        }
    }
}

bool CSet::contains(int el) const
{
    for (int x : els)
    {
        if (x == el) return true;
    }
    return false;
}

int CSet::operator[](unsigned index)
{
    return els.at(index);
}

const CSet operator+(const CSet& set1, const CSet& set2)
{
    CSet result_set;
    for (int x : set1.els)
    {
        if (!result_set.contains(x)) result_set.include(x);
    }
    for (int x : set2.els)
    {
        if (!result_set.contains(x)) result_set.include(x);
    }
    return result_set;
}

const CSet operator-(const CSet& set1, const CSet& set2)
{
    CSet result_set;
    for (int x : set1.els)
    {
        if (!set2.contains(x)) result_set.include(x);
    }
    return result_set;
}

const CSet operator*(const CSet& set1, const CSet& set2)
{
    CSet result_set;
    for (int x : set1.els)
    {
        if (set2.contains(x)) result_set.include(x);
    }
    return result_set;
}
