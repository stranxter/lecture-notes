#pragma once

#include <vector>

template<typename Key, typename Value>
class HashMap
{
    public:
    HashMap(unsigned int capacity = 255, unsigned int(*_hf)(const Key&));
    bool hasKey(const Key& k);

    private:

    struct row
    {
        Key key;
        Value vealue;
        row *next;
    };
    std::vector<row*> table;
    usnigned int(*hf)(const Key&)
};
