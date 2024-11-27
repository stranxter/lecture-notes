#include "hashmap.h"

template<typename Key, typename Value>
HashMap<Key,Value>::HashMap(unsigned int(*_hf)(const Key&),unsigned int capacity):hf(_hf)
{
    table.assign(capacity,nullptr);
}


template<typename Key, typename Value>
bool HashMap<Key,Value>::hasKey(const Key& key) const
{
    unsigned int hash = hf(key) % table.size();
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

template<typename Key, typename Value>
void HashMap<Key,Value>::add(const Key& key, const Value& val)
{

}