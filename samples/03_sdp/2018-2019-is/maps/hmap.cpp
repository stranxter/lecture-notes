#ifndef __HMAP_CPP
#define __HMAP_CPP

#include "hmap.h"
#include <cassert>

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

#endif
