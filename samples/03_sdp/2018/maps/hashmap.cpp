#ifndef __HASHMAP__
#define __HASHMAP__

#include <vector>

template <class KeyType>
using HashFunction = unsigned int (*)(const KeyType&, unsigned int);

template <class KeyType, class ValueType>
class HashMap
{
public:
  HashMap (unsigned _n, HashFunction<KeyType> _h);
  ~HashMap ();
  HashMap (const HashMap<KeyType,ValueType>&);
  HashMap<KeyType,ValueType>& operator = (const HashMap<KeyType,ValueType> &);

  ValueType& operator [] (const KeyType&);
  const ValueType& operator [] (const KeyType&) const;

  bool hasKey (const KeyType &) const;

  bool operator == (const HashMap<KeyType,ValueType>&) const;
  bool operator != (const HashMap<KeyType,ValueType>&) const;

  void resize (unsigned int);


private:

  struct kvpair
  {
    kvpair (KeyType _k, ValueType _v):key(_k), value (_v){}
    KeyType key;
    ValueType value;
  };

  int locate (const KeyType&, unsigned int) const;

  unsigned int size, count;
  HashFunction<KeyType> h;
  std::vector<std::vector<kvpair>> *buckets;
};

template <class KeyType, class ValueType>
HashMap<KeyType,ValueType>
      ::HashMap (unsigned _n,
                 HashFunction<KeyType> _h):size(_n), h(_h)
{
  count = 0;
  buckets = new std::vector<std::vector<kvpair>>;
  std::vector<kvpair> emptyBucket;
  buckets->assign (size,emptyBucket);
}

template <class KeyType, class ValueType>
HashMap<KeyType,ValueType>::~HashMap ()
{
  delete buckets;
}
template <class KeyType, class ValueType>
HashMap<KeyType,ValueType>::HashMap (const HashMap<KeyType,ValueType> &other)
{
  size = other.size;
  count = other.count;
  buckets = new std::vector<std::vector<kvpair>>;
  *buckets = *other.buckets;
}

template <class KeyType, class ValueType>
HashMap<KeyType,ValueType>&
   HashMap<KeyType,ValueType>::operator =
      (const HashMap<KeyType,ValueType> &other)
{
  if (this != &other)
  {
    delete buckets;
    buckets = new std::vector<std::vector<kvpair>>;
    *buckets = other.buckets;
    size = other.size;
    count = other.count;
  }
  return *this;
}

template <class KeyType, class ValueType>
int HashMap<KeyType,ValueType>::locate (const KeyType& key, unsigned int ix) const
{
  for (int i = 0; i < (*buckets)[ix].size(); i++)
  {
    if ((*buckets)[ix][i].key == key)
    {
      return i;
    }
  }
  return -1;
}


template <class KeyType, class ValueType>
ValueType& HashMap<KeyType,ValueType>::operator [] (const KeyType &key)
{
  unsigned int ix = h (key, size);// % size;
  assert (ix < size);

  unsigned int n = locate (key,ix);

  if (n == -1)
  {
    (*buckets)[ix].push_back (kvpair(key,ValueType()));
    n = (*buckets)[ix].size()-1;
    count++;
  }

  return (*buckets)[ix][n].value;

}

template <class KeyType, class ValueType>
const ValueType& HashMap<KeyType,ValueType>::operator [] (const KeyType &key) const
{
  unsigned int ix = h (key, size);// % size;
  assert (ix < size);

  unsigned int n = locate (key,ix);
  assert (n >= 0);

  return (*buckets)[ix][n].value;

}

template <class KeyType, class ValueType>
bool HashMap<KeyType,ValueType>::operator == (const HashMap<KeyType,ValueType> &other) const
{

  for (int ibucket = 0; ibucket < buckets->size(); ibucket++)
  {
    const std::vector<kvpair> &bucket = (*buckets)[ibucket];
    for (int el = 0; el < bucket.size(); el++)
    {
      const KeyType &key = bucket[el].key;
      const ValueType & value = bucket[el].value;
      if (other.hasKey (key) && other[key] != value)
      {
        return false;
      }
    }
  }

  return count == other.count;
}

template <class KeyType, class ValueType>
bool HashMap<KeyType,ValueType>::hasKey (const KeyType &key) const
{
    unsigned ix = h (key,size);
    return locate (key,ix) >= 0;
}

template <class KeyType, class ValueType>
bool HashMap<KeyType,ValueType>::operator != (const HashMap<KeyType,ValueType> &other) const
{
  return !(*this == other);
}

template <class KeyType, class ValueType>
void HashMap<KeyType,ValueType>::resize (unsigned int newSize)
{
  HashMap<KeyType,ValueType> newMap (size,h);

  for (int ibucket = 0; ibucket < buckets->size(); ibucket++)
  {
    const std::vector<kvpair> &bucket = *buckets[ibucket];
    for (int el = 0; el < bucket.size(); el++)
    {
      const KeyType &key = bucket[el].key;
      const ValueType & value = bucket[el].value;
      newMap[key] = value;
    }
  }

  size = newSize;

  std::vector<std::vector<kvpair>> *save = buckets;
  buckets = newMap.buckets;
  newMap.buckets = save;

}


#endif
