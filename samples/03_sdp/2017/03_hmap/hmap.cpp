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
		
		Iterator (const vector<list<KeyValue>> &_table,bool=false);

		KeyType operator * ();
		Iterator& operator ++ ();
		bool operator != (typename HashMap<KeyType,ValueType>::Iterator &);

		private:

		void goToActualEntry();
		
		typename vector<list<KeyValue>>::const_iterator currentTableEntry;
		typename list<KeyValue>::const_iterator currentCollision;
		const vector<list<KeyValue>> &table;


	};


	Iterator begin() const;
	Iterator end() const;

	HashMap (size_t size, hashFnType<KeyType> f);

	ValueType& operator [] (const KeyType&);
	ValueType operator [] (const KeyType&) const;
	bool containsKey (const KeyType&) const;

	void resize (size_t size);
	size_t size () const;
	hashFnType<KeyType> getHashFunction () const;



private:
	hashFnType<KeyType> hashFunction;
	vector<list<KeyValue>> table;


};


template <class T>
vector<T> append (const vector<T> &v1,const vector<T> &v2)
{
	vector<T> result = v1;
	result.insert (result.end(),v2.begin(),v2.end());
	return result;
}

template <class KeyType, class ValueType>
HashMap<KeyType,vector<ValueType>> 
  operator * (const HashMap<KeyType,vector<ValueType>> &hm1,
  			  const HashMap<KeyType,vector<ValueType>> &hm2)
{

	HashMap<KeyType,vector<ValueType>> 
	  result(hm2.size(),hm2.getHashFunction());

	for (const KeyType &key : hm1)
	{
		//key е в сечението на ключовете
		if (hm2.containsKey (key))
		{
			result[key] = append (hm1[key], hm2[key]);
		}
	}

	return result;

}

template <class KeyType, class ValueType>
HashMap<KeyType,vector<ValueType>> 
  operator * (const HashMap<KeyType,ValueType> &hm1,
  			  const HashMap<KeyType,ValueType> &hm2)
{

	HashMap<KeyType,vector<ValueType>> 
	  result(hm2.size(),hm2.getHashFunction());

	for (const KeyType &key : hm1)
	{
		//key е в сечението на ключовете
		if (hm2.containsKey (key))
		{
			result[key].push_back(hm1[key]);
			result[key].push_back(hm2[key]);
		}
	}
	return result;
}

template <class KeyType, class ValueType>
hashFnType<KeyType> HashMap<KeyType,ValueType>::getHashFunction () const
{
	return hashFunction;
}

template <class KeyType, class ValueType>
size_t HashMap<KeyType,ValueType>::size () const
{
	return table.size();
}

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


	for (const KeyValue &pair : table[index])
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
     (const vector<list<typename HashMap<KeyType,ValueType>::KeyValue>> &_table,
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
typename HashMap<KeyType,ValueType>::Iterator& 
  HashMap<KeyType,ValueType>::Iterator::operator ++ ()
{
	++currentCollision;
	goToActualEntry();
	return *this;
}


template <class KeyType, class ValueType>
bool HashMap<KeyType,ValueType>::Iterator::operator != 
    (typename HashMap<KeyType,ValueType>::Iterator &other)
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
typename HashMap<KeyType,ValueType>::Iterator
   HashMap<KeyType,ValueType>::begin() const
{
	return HashMap<KeyType,ValueType>::Iterator (table);
}


template <class KeyType, class ValueType>
typename HashMap<KeyType,ValueType>::Iterator 
   HashMap<KeyType,ValueType>::end() const
{
  return HashMap<KeyType,ValueType>::Iterator (table,true);

}




