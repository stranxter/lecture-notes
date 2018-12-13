#ifndef __HMAP_CPP
#define __HMAP_CPP

#include "hmap.h"
#include <cassert>
#include <iostream>

template <class KeyType, class ValType>
HashMap<KeyType,ValType>::HashMap (size_t ts, hashFn<KeyType> hf)
  :hashfn(hf),tsize (ts)
{
  table = new TableElement<KeyType,ValType>* [tsize];
  for (size_t i = 0; i < tsize; i++)
  {
    table[i] = nullptr;
  }
}

template <class KeyType, class ValType>
void HashMap<KeyType,ValType>::update (const KeyType &key, const ValType &value)
{
  TableElement<KeyType,ValType> *el  = locate (key);
  if (el != nullptr)
  {
    el->value = value;
  } else {
    size_t hcode = hashfn (key,tsize);
    table[hcode]
        = new TableElement<KeyType,ValType> (key,value,table[hcode]);
  }
}

template <class KeyType, class ValType>
TableElement<KeyType,ValType>*
   HashMap<KeyType,ValType>::locate (const KeyType &key) const
{
  size_t hcode = hashfn (key,tsize);

  TableElement<KeyType,ValType> *crr = table[hcode];
  while (crr != nullptr && crr->key != key)
  {
    crr = crr->next;
  }
  return crr;
}

template <class KeyType, class ValType>
bool HashMap<KeyType,ValType>::hasKey (const KeyType &key) const
{
  return locate(key) != nullptr;
}
template <class KeyType, class ValType>
ValType HashMap<KeyType,ValType>::get (const KeyType &key) const
{
  TableElement<KeyType,ValType> *el  = locate (key);
  assert (el != nullptr);

  return el->value;
}

template <class KeyType, class ValType>
void HashMap<KeyType,ValType>::remove (const KeyType &key)
{
  size_t hcode = hashfn (key,tsize);

  TableElement<KeyType,ValType> *crr = table[hcode];

  assert (crr != nullptr);

  while (crr->next != nullptr && crr->next->key != key)
  {
    crr = crr->next;
  }

  assert (crr->next != nullptr);

  TableElement<KeyType,ValType> *save = crr->next;
  crr->next = crr->next->next;
  delete save;

}

template <class KeyType, class ValType>
HashMapIterator<KeyType,ValType> HashMap<KeyType,ValType>::begin ()
{
  return HashMapIterator<KeyType,ValType> (table,tsize);
}

template <class KeyType, class ValType>
HashMapIterator<KeyType,ValType> HashMap<KeyType,ValType>::end ()
{
  return HashMapIterator<KeyType,ValType> (table,tsize,true);
}

template <class KeyType, class ValType>
HashMapIterator<KeyType, ValType>::HashMapIterator
   (TableElement<KeyType,ValType> **_table, size_t _tsize, bool end)
{
  tsize = _tsize;
  table = _table;
  if (end)
  {
    elementIndex = _tsize;
    element = nullptr;
  } else {
    elementIndex = 0;
    element = table[0];
    findNextKeyValuePair ();
  }
}

template <class KeyType, class ValType>
void HashMapIterator<KeyType, ValType>::findNextKeyValuePair ()
{
  if (element != nullptr)
  {
    return;
  }

  while (element == nullptr && elementIndex < tsize)
  {
    elementIndex++;
    if (elementIndex < tsize)
    {
        element = table[elementIndex];
    }
  }
}

template <class KeyType, class ValType>
KeyType HashMapIterator<KeyType, ValType>::operator * ()
{
    assert (elementIndex < tsize);

    return element->key;
}

template <class KeyType, class ValType>
HashMapIterator<KeyType,ValType>&
    HashMapIterator<KeyType, ValType>::operator ++ ()
{
  element = element->next;
  findNextKeyValuePair();
  return *this;
}

template <class KeyType, class ValType>
bool HashMapIterator<KeyType, ValType>::operator ==
    (const HashMapIterator<KeyType,ValType> &other) const
{
    return table == other.table &&
           elementIndex == other.elementIndex &&
           element == other.element;
}

template <class KeyType, class ValType>
bool HashMapIterator<KeyType, ValType>::operator !=
    (const HashMapIterator<KeyType,ValType> &other) const
{

  return table != other.table ||
         elementIndex != other.elementIndex ||
         element != other.element;
}


#endif
