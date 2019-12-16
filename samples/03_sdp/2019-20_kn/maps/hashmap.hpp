#ifndef __HASHMAP_HPP
#define __HASHMAP_HPP

#include "hashmap.h"
#include <cassert>
#include <iostream>

template <class KeyType, class ValType>
HashMap<KeyType,ValType>::HTElement::
    HTElement (const KeyType &_key, 
               const ValType &_val,
               typename HashMap<KeyType,ValType>::HTElement *_next)
  :key(_key), val (_val), next (_next)
{

}

template <class KeyType, class ValType>
HashMap<KeyType,ValType>::HTElement::HTElement ():next(nullptr)
{
    
}

template <class KeyType, class ValType>
HashMap<KeyType,ValType>::HashMap (hashfn _h, size_t _size):h(_h), size(_size)
{
    table = new HTElement*[size];
    for (size_t i = 0; i < size; i++)
    {
        table[i] = nullptr;
    }
}

template <class KeyType, class ValType>
ValType& HashMap<KeyType,ValType>::operator [] (const KeyType &key)
{
    size_t index = h (key,size);
    assert (index < size);

    typename HashMap<KeyType,ValType>::HTElement *pair = findKVPair (index,key);

    if (pair == nullptr)
    {
        pair = table[index] 
             = new typename HashMap<KeyType,ValType>::HTElement (key,ValType(),table[index]);
    }
    
    return pair->val;
}

template <class KeyType, class ValType>
typename HashMap<KeyType,ValType>::HTElement* 
   HashMap<KeyType,ValType>::findKVPair (size_t index, const KeyType&key)
{
    typename HashMap<KeyType,ValType>::HTElement *pair = table[index];
    while (pair != nullptr && pair->key != key)
    {
        pair = pair->next;
    }

    return pair;
}


template <class KeyType, class ValType>
bool HashMap<KeyType,ValType>::hasKey (const KeyType &key)
{
    return findKVPair(h(key,size),key) != nullptr;
}

template <class KeyType, class ValType>
KeyType HashMap<KeyType,ValType>::Iterator::operator *()
{
    assert (pair != nullptr);
    return pair->key;
}
template <class KeyType, class ValType>
typename HashMap<KeyType,ValType>::Iterator& 
     HashMap<KeyType,ValType>::Iterator::operator ++()
{
    findNextPair();
    return *this;
}

template <class KeyType, class ValType>
void HashMap<KeyType,ValType>::Iterator::findNextPair ()
{
    if (pair != nullptr)
    {
        pair = pair->next;
    }
    if (pair != nullptr)
    {
        return;
    }

    ++index;
    while (index < hm.size && hm.table[index] == nullptr)
    {
       ++index;
    }
    if (index < hm.size)
    {
        pair = hm.table[index];
    }
}

template <class KeyType, class ValType>
bool HashMap<KeyType,ValType>::Iterator
    ::operator == (const typename HashMap<KeyType,ValType>::Iterator &it)
{
    return index == it.index && pair == it.pair;
}

template <class KeyType, class ValType>
bool HashMap<KeyType,ValType>::Iterator
    ::operator != (const typename HashMap<KeyType,ValType>::Iterator &it)
{
    return index != it.index || pair != it.pair;
}

template <class KeyType, class ValType>
HashMap<KeyType,ValType>::Iterator::Iterator (HashMap<KeyType,ValType> &_hm, bool end):hm(_hm)

{
    if (end)
    {
        index = hm.size;
        pair = nullptr;
    } else {
    
        index = 0;
        pair = hm.table[0];
        if (pair != nullptr)
            findNextPair();
    }
}


template <class KeyType, class ValType>
typename HashMap<KeyType,ValType>::Iterator HashMap<KeyType, ValType>::begin ()
{
   return Iterator (*this,false);
}
template <class KeyType, class ValType>
typename HashMap<KeyType,ValType>::Iterator HashMap<KeyType, ValType>::end()
{
   return Iterator (*this,true);
}


#endif