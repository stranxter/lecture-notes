#ifndef __HASHMAP_CPP
#define __HASHMAP_CPP

#include "hashmap.h"
#include <cassert>

template<class Keys, class Values>
HashMap<Keys,Values>::HashMap (size_t _size, std::function<size_t(const Keys&)> _h):size(_size),h(_h)
{
    table = new Entry*[size];
    for (int i = 0; i < size; ++i)
    {
        table[i] = nullptr;
    }
}

template<class Keys, class Values>
typename HashMap<Keys,Values>::Entry *HashMap<Keys,Values>::locate(size_t index, const Keys &key) const
{
    HashMap<Keys,Values>::Entry *current =  table[index];
    while (current != nullptr && current->key != key)
    {
        current = current->next;    
    }
    return current;
}

template<class Keys, class Values>
Values HashMap<Keys,Values>::operator[](const Keys &key) const
{

    typename HashMap<Keys,Values>::Entry *current =  locate(h(key)%size,key);
    assert (current != nullptr);

    return current->value;

}

template<class Keys, class Values>
Values& HashMap<Keys,Values>::operator[](const Keys &key)
{
    size_t index = h(key)%size;
    
    typename HashMap<Keys,Values>::Entry *current = locate(index,key);

    if (current == nullptr)
    {
        current = table[index] = new HashMap<Keys,Values>::Entry {key,Values(),table[index]};
    }

    return current->value;
    
}

template<class Keys, class Values>
bool HashMap<Keys,Values>::hasKey (const Keys &key) const
{
    return locate(h(key)%size,key) != nullptr;
}

template<class Keys, class Values>
HashMap<Keys,Values>::Iterator::Iterator(Entry **_table, size_t _size):table(_table), size(_size)
{
    currentRow = 0;
    currentColumn = nullptr;

    if (table == nullptr)
    {
        return;
    }

    currentColumn = table[currentRow];
    while (currentRow < size && currentColumn == nullptr)
    {
        ++currentRow;
        currentColumn = table[currentRow];
    }
}

template<class Keys, class Values>
Keys HashMap<Keys,Values>::Iterator::operator *()
{
    assert(currentColumn != nullptr);
    return currentColumn->key;
}

template<class Keys, class Values>
typename HashMap<Keys,Values>::Iterator& HashMap<Keys,Values>::Iterator::operator ++()
{
    assert(currentColumn != nullptr);
    currentColumn = currentColumn->next;

    if(currentColumn == nullptr)
    {
        ++currentRow;
        while (currentRow < size && currentColumn == nullptr)
        {
            currentColumn = table[currentRow];
            ++currentRow;
            
        }        
    }
    return *this;
}

template<class Keys, class Values>
bool HashMap<Keys,Values>::Iterator::operator != (const typename HashMap<Keys,Values>::Iterator &other) const
{
    return currentColumn != other.currentColumn;
}

template<class Keys, class Values>
typename HashMap<Keys,Values>::Iterator HashMap<Keys,Values>::begin() const
{
    return typename HashMap<Keys,Values>::Iterator(table,size);
}

template<class Keys, class Values>
typename HashMap<Keys,Values>::Iterator HashMap<Keys,Values>::end() const
{
    return typename HashMap<Keys,Values>::Iterator(nullptr,size);
}

#endif