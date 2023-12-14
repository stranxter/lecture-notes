#include "hasht.h"
#include <cassert>


template <typename Key, typename Value>
HashTable<Key,Value>::HashTable(size_t _size, std::function<size_t(const Key&)> _h):size(_size),h(_h)
{
    table = new elem*[size];
    for(int i = 0; i < size; ++i)
    {
        table[i] = nullptr;
    }

}

template <typename Key, typename Value>
Value& HashTable<Key,Value>::operator[](const Key& key)
{
    typename HashTable<Key,Value>::elem* current = table[h(key)%size];

    if(current == nullptr)
    {
        current = new typename HashTable<Key,Value>::elem{key,Value(),nullptr};
        table[h(key)%size] = current;
    } else 
    {
        while (current->next != nullptr && current->key != key)
        {
            current = current->next;
        }

        if(current->key != key)
        {
            current->next = new typename HashTable<Key,Value>::elem{key,Value(),nullptr};
            current = current->next;
        }
    }

    //current сочи намереният елемент или нов елемент,
    //създаден за ключа key

    return current->value; 
}

template <typename Key, typename Value>
Value HashTable<Key,Value>::get(const Key& key) const
{
    typename HashTable<Key,Value>::elem* kvpair = locate(key);
    if(kvpair == nullptr)
    {
        throw std::out_of_range("Key not found!");
    }
    return kvpair->value;
}

template <typename Key, typename Value>
bool HashTable<Key,Value>::exists(const Key& key) const
{
    return locate(key) != nullptr;
}

template <typename Key, typename Value>
typename HashTable<Key,Value>::elem* HashTable<Key,Value>::locate(const Key& key) const
{
    typename HashTable<Key,Value>::elem* current = table[h(key)%size];
    while (current != nullptr && current->key != key)
    {
        current = current->next;
    }
    return current;
}

template <typename Key, typename Value>
typename HashTable<Key,Value>::KeyIterator HashTable<Key,Value>::begin() const
{
    return HashTable<Key,Value>::KeyIterator(table,table+size);
}

template <typename Key, typename Value>
typename HashTable<Key,Value>::KeyIterator HashTable<Key,Value>::end() const
{
    return HashTable<Key,Value>::KeyIterator(table+size,table+size);
}


template<typename Key, typename Value>
HashTable<Key,Value>::KeyIterator::KeyIterator(typename HashTable<Key,Value>::elem** _table_start,
                                               typename HashTable<Key,Value>::elem** _table_end)
    :table_row_current(_table_start), table_end(_table_end),current(nullptr)
{

    while(table_row_current != table_end &&  *table_row_current == nullptr)
    {
        ++table_row_current;
    }
    if(table_row_current != table_end)
    {
        current = *table_row_current;    
    }
}

template<typename Key, typename Value>
Key HashTable<Key,Value>::KeyIterator::operator*() const
{
    assert(current != nullptr);

    return current->key;
}

template<typename Key, typename Value>
typename HashTable<Key,Value>::KeyIterator& HashTable<Key,Value>::KeyIterator::operator++()
{
    assert(current != nullptr);
    current = current->next;
    if(current != nullptr)
    {
        return *this;
    }
    ++table_row_current;
    while(table_row_current != table_end &&  *table_row_current == nullptr)
    {
        ++table_row_current;
    }
    if(table_row_current != table_end)
    {
        current = *table_row_current;
    }
    return *this;
}

template<typename Key, typename Value>
bool HashTable<Key,Value>::KeyIterator::operator != (const typename HashTable<Key,Value>::KeyIterator &other)
{
    return (table_row_current != other.table_row_current) || (current != other.current);
}





/*template <typename Key, typename Value>
void HashTable<Key,Value>::resize(size_t newsize)
{
    typename HashTable<Key,Value>::elem** new_table
           = new typename HashTable<Key,Value>::elem*[newsize];

         
}*/
