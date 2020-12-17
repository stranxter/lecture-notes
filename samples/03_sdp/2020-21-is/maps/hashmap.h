#ifndef __HASHMAP_H
#define __HASHMAP_H

#include <functional>

template <class Keys, class Values>
class HashMap
{
    public:
    HashMap (size_t, std::function<size_t(const Keys&)>);

    Values operator[](const Keys&) const;
    Values& operator[](const Keys&);

    bool hasKey (const Keys&) const;

    private:
    struct Entry
    {
        Keys key;
        Values value;
        Entry *next;
    };

    public:

    class Iterator
    {
        public:
        Iterator(Entry**, size_t);
        
        Keys operator *();
        Iterator& operator ++();
        bool operator != (const Iterator&) const;

        private:
        size_t currentRow;
        Entry *currentColumn;
        Entry **table;
        size_t size;
    };

    Iterator begin() const;
    Iterator end() const;

    private:

    Entry **table;
    size_t size;
    std::function<size_t(const Keys&)> h;

    Entry *locate(size_t, const Keys&) const;

};


#endif