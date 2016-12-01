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

	//итератор за итериране по ключовете
	class Iterator
	{
		public:
		
		Iterator (vector<list<KeyValue>> &_table,bool=false);

		KeyType operator * ();
		Iterator& operator ++ ();
		bool operator != (typename HashMap<KeyType,ValueType>::Iterator &);

		private:

		void goToActualEntry();
		
		typename vector<list<KeyValue>>::iterator currentTableEntry;
		typename list<KeyValue>::iterator currentCollision;
		vector<list<KeyValue>> &table;


	};


	Iterator begin();
	Iterator end();

	HashMap (size_t size, hashFnType<KeyType> f);

	ValueType& operator [] (const KeyType&);
	ValueType operator [] (const KeyType&) const;
	bool containsKey (const KeyType&) const;

	void resize (size_t size);

private:
	hashFnType<KeyType> hashFunction;
	vector<list<KeyValue>> table;

};


template <class KeyType, class ValueType>
using HMIterator 
   = typename HashMap<KeyType,ValueType>::Iterator;


template <class KeyType, class ValueType>
void HashMap<KeyType,ValueType>::resize (size_t size)
{
	assert (size > 0);
	if (size == table.size())
		return;

	vector<list<KeyValue>> newTable;
	newTable.assign (size,list<KeyValue>());

	for (KeyType key : *this)
	{
		newTable[hashFunction(key,size)]
		   .push_back (KeyValue(key,(*this)[key]));
	}

	table = newTable;
	//	std::move (table,newTable); или нещо подобно


}


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
	assert (index < table.size());

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
	assert (index < table.size());


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
	assert (index < table.size());

	for (const KeyValue &pair : table[index])
	{
		if (pair.key == key)
			return true;
	}

	return false;

}

template <class KeyType, class ValueType>
HashMap<KeyType,ValueType>::Iterator::Iterator 
     (vector<list<typename HashMap<KeyType,ValueType>::KeyValue>> &_table,
     	bool goToEnd)
       :table(_table)
{
	currentTableEntry = _table.begin();
	currentCollision = (*currentTableEntry).begin();
	
	if (goToEnd)
	{
		currentTableEntry = table.end();
	} else 
	{

		goToActualEntry();

	}
}

template <class KeyType, class ValueType>
void HashMap<KeyType,ValueType>::Iterator::goToActualEntry()
{

	/* Кога спираме:
		1. currentTableEntry == table.end() 
		  (няма къде повече да търсим)
		2. currentCollision != (*currentTableEntry).end() 
		  (сме намерили каквото търсим)
	*/


	while (currentTableEntry != table.end() &&
		   currentCollision == (*currentTableEntry).end())
	{
		++currentTableEntry;
		if (currentTableEntry != table.end())
			currentCollision = (*currentTableEntry).begin();

	}

}


template <class KeyType, class ValueType>
KeyType HashMap<KeyType,ValueType>::Iterator::operator * ()
{
	assert (currentTableEntry != table.end());

	return (*currentCollision).key;
}


template <class KeyType, class ValueType>
HMIterator<KeyType,ValueType>& 
  HashMap<KeyType,ValueType>::Iterator::operator ++ ()
{
	++currentCollision;
	goToActualEntry();
	return *this;
}


template <class KeyType, class ValueType>
bool HashMap<KeyType,ValueType>::Iterator::operator != 
    (HMIterator<KeyType,ValueType> &other)
{
		

	if (currentTableEntry != other.currentTableEntry)
		return true;

	if (currentTableEntry == table.end())
	   return false;

	return currentCollision != other.currentCollision;


/*	return (currentTableEntry == table.end()) !=
	       (other.currentTableEntry == other.table.end());

*/
}

template <class KeyType, class ValueType>
HMIterator<KeyType,ValueType> 
   HashMap<KeyType,ValueType>::begin()
{
	return HashMap<KeyType,ValueType>::Iterator (table);
}


template <class KeyType, class ValueType>
HMIterator<KeyType,ValueType> 
   HashMap<KeyType,ValueType>::end()
{
  return HMIterator<KeyType,ValueType> (table,true);

}




