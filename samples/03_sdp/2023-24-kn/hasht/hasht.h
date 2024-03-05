#pragma once
#include <functional>


template <typename Key, typename Value>
class HashTable
{
    public:
    HashTable(size_t size, std::function<size_t(const Key&)> h);

    Value& operator[](const Key&);
    Value get(const Key&) const;
    bool exists(const Key&) const;

    //void resize(size_t newsize);

    private:
    struct elem
    {
        Key key;
        Value value;
        elem* next;
    };

    elem** table;
    size_t size;
    std::function<size_t(const Key&)> h;

    elem* locate(const Key&) const;

    public:
    class KeyIterator
    {
        public:
        KeyIterator(elem**,elem**);
        Key operator*() const;
        KeyIterator& operator++();
        bool operator != (const KeyIterator&);

        private:
        elem **table_row_current, **table_end;      
        elem *current;


    };

    KeyIterator begin() const;
    KeyIterator end() const;




};