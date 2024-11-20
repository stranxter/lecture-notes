#include "hasmap.h"

template<typename Key, typename Value>
HashMap<Key,Value>::HashMap(unsigned int capacity, unsigned int(*_hf)(const Key&)):hf(_hf)
{
    table.assign(capacity,nullptr);
}


template<typename Key, typename Value>
bool HashMap<Key,Value>::hasKey(const Key& k)
{
    unsigned int hash = hf(k) % table.size();
    if(table[hash] == nullptr)
    {
        return false;
    }

    typename HashMap<Key,Value>::row *current = table[hash];
    while(current != nullptr && current->key != key)
    {
        current = current->next;
    }

    return current != nullptr;
}
