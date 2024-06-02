#pragma once
#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED
#include <vector>
class CSet
{
private:
    std::vector<int> els;
    unsigned size;
public:
    CSet() : size(0) { }

    void print();
    void include(int el);
    void exclude(int el);
    bool contains(int el) const;
    const friend CSet operator+(const CSet& set1, const CSet& set2);
    const friend CSet operator-(const CSet& set1, const CSet& set2);
    const friend CSet operator*(const CSet& set1, const CSet& set2);
    int operator[](unsigned index);
    inline unsigned length() const { return size; }

};
#endif // SET_H_INCLUDED