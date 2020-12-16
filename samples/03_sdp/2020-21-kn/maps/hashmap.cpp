#ifndef __HASMAP_CPP
#define __HASMAP_CPP

#include <cassert>

#include "hashmap.h"


template <class Keys, class Values>
HashMap<Keys,Values>::HashMap (size_t _size, std::function<size_t(const Keys&)> _h):size(_size),h(_h)
{
  table = new HashMap<Keys,Values>::Entry*[size];
  for (int i = 0; i < size; ++i)
  {
      table[i] = nullptr;
  }  
}

template <class Keys, class Values>
typename HashMap<Keys,Values>::Entry* HashMap<Keys,Values>::locate (size_t index, const Keys &key) const
{
    typename HashMap<Keys,Values>::Entry *current = table[index];
    while (current != nullptr && current->key != key)
    {
        current = current->next;
    }

    return current;
}

template <class Keys, class Values>
Values HashMap<Keys,Values>::operator [](const Keys &key) const
{
    size_t index = h(key) % size;
    
    HashMap<Keys,Values>::Entry *kvpair = locate (index,key);
    assert (kvpair != nullptr);

    return kvpair->value;
}

template <class Keys, class Values>
Values& HashMap<Keys,Values>::operator [](const Keys &key)
{
    size_t index = h(key) % size;
    
    HashMap<Keys,Values>::Entry *kvpair = locate (index,key);

    if (kvpair != nullptr)
    {
        return kvpair->value;
    } else 
    {
        table[index] = new HashMap<Keys,Values>::Entry {key,Values(),table[index]};
        return table[index]->value;
    }
}

template <class Keys, class Values>
bool HashMap<Keys,Values>::hasKey(const Keys &key) const
{
    size_t index = h(key) % size;
    HashMap<Keys,Values>::Entry *kvpair = locate (index,key);

    return kvpair != nullptr;
}

template <class Keys, class Values>
HashMap<Keys,Values>::Iterator::Iterator (HashMap<Keys,Values>::Entry** _table, size_t _size):table(_table), size(_size)
{
    currentRow = 0;
    currentColumn = nullptr;

    if (table == nullptr)
    {
        return;
    }

    size_t i = 0;
    while (i < size && table[i] == nullptr)
    {
        ++i;
    }

    if (i < size)
    {
        currentRow = i;
        currentColumn = table[i];
    } 

}

template <class Keys, class Values>
Keys HashMap<Keys,Values>::Iterator::operator*() const
{
    assert (currentColumn != nullptr);
    return currentColumn->key;
}

template <class Keys, class Values>
typename HashMap<Keys,Values>::Iterator& HashMap<Keys,Values>::Iterator::operator++()
{
    assert (currentColumn != nullptr);
    currentColumn = currentColumn->next;
    
    if (currentColumn == nullptr)
    {   
        ++currentRow;
        while (currentRow < size && table[currentRow] == nullptr)
        {
            ++currentRow;
        }
        if (currentRow < size)
        {
            currentColumn = table[currentRow];
        }
    }
    return *this;
}

template <class Keys, class Values>
bool HashMap<Keys,Values>::Iterator::operator !=(const typename HashMap<Keys,Values>::Iterator &other) const
{
    return currentColumn != other.currentColumn;
}

template <class Keys, class Values>
typename HashMap<Keys,Values>::Iterator HashMap<Keys,Values>::begin() const
{
    return HashMap<Keys,Values>::Iterator(table, size);
}

template <class Keys, class Values>
typename HashMap<Keys,Values>::Iterator HashMap<Keys,Values>::end() const
{
    return HashMap<Keys,Values>::Iterator(nullptr, size);
}



#endif