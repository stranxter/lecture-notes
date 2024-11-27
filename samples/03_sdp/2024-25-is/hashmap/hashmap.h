#pragma once

#include <vector>

template<typename Key, typename Value>
class HashMap
{
    public:
    HashMap(unsigned int(*_hf)(const Key&), unsigned int capacity = 255);
    bool hasKey(const Key& k) const;

    void add(const Key&, const Value&);

    private:

    struct row
    {
        Key key;
        Value vealue;
        row *next;
    };
    std::vector<row*> table;
    unsigned int(*hf)(const Key&);
};
