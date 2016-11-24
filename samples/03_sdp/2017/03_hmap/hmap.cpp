#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cassert>

using namespace std;

template <class KeyType>
using hashFnType = size_t (*) (const KeyType&, 
	     							 size_t);

template <class KeyType, class ValueType>
class HashMap
{
public:
	struct KeyValue
	{
		KeyType key;
		ValueType value;
		KeyValue (const KeyType& _k, const ValueType& _v):key(_k),value(_v){}
	};

	HashMap (size_t size, hashFnType<KeyType> f);

	ValueType& operator [] (const KeyType&);
	ValueType operator [] (const KeyType&) const;
	bool containsKey (const KeyType&) const;



private:
	hashFnType<KeyType> hashFunction;
	vector<list<KeyValue>> table;

};

template <class KeyType, class ValueType>
HashMap<KeyType,ValueType>::HashMap (size_t size, hashFnType<KeyType> f)
{
	hashFunction = f;
	table.assign (size,list<KeyValue>());
}

template <class KeyType, class ValueType>
ValueType& HashMap<KeyType,ValueType>::operator [] (const KeyType &key)
{
	//hashTable
	//hasFunction

	size_t index = hashFunction (key,table.size());

	for (KeyValue &pair : table[index])
	{
		if (pair.key == key)
			return pair.value;
	}

    table[index].push_back (KeyValue(key,ValueType()));
	return table[index].back().value;


}
template <class KeyType, class ValueType>
ValueType HashMap<KeyType,ValueType>::operator [] (const KeyType &key) const
{
	size_t index = hashFunction (key,table.size());

	for (KeyValue &pair : table[index])
	{
		if (pair.key == key)
			return pair.value;
	}
	
	assert (false);
    return ValueType();
}

template <class KeyType, class ValueType>
bool HashMap<KeyType,ValueType>::containsKey (const KeyType &key) const
{
	size_t index = hashFunction (key,table.size());

	for (const KeyValue &pair : table[index])
	{
		if (pair.key == key)
			return true;
	}

	return false;

}


