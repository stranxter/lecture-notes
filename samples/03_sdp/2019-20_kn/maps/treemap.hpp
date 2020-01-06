#ifndef __TREEMAP_HPP
#define __TREEMAP_HPP

#include "treemap.h"
#include "../trees/botree.hpp"

template <class KeyType, class ValType>
KeyType TreeMap<KeyType,ValType>::ConstIterator::operator *() const
{
    return (*treeit).key;
}

template <class KeyType, class ValType>
typename TreeMap<KeyType,ValType>::ConstIterator& 
         TreeMap<KeyType,ValType>::ConstIterator::operator ++()
{
    ++treeit;
    return *this;
}

template <class KeyType, class ValType>
bool TreeMap<KeyType,ValType>::ConstIterator::
   operator == (const typename TreeMap<KeyType,ValType>::ConstIterator &it) const
{
    return treeit == it.treeit;
}


template <class KeyType, class ValType>
bool TreeMap<KeyType,ValType>::ConstIterator::
    operator != (const typename TreeMap<KeyType,ValType>::ConstIterator &it) const
{
    return treeit != it.treeit;
}

template <class KeyType, class ValType>
TreeMap<KeyType,ValType>::ConstIterator::
     ConstIterator (const BOTree<typename TreeMap<KeyType,ValType>::KVPair> &tree, bool end):treeit(tree.end())
{
    if (!end)
        treeit = tree.begin();
}

template <class KeyType, class ValType>
ValType& TreeMap<KeyType,ValType>::operator [] (const KeyType &key)
{
    typename TreeMap<KeyType,ValType>::KVPair pair (key,ValType()); 
    
    return pairs.findormake (pair).val;

}
  
template <class KeyType, class ValType>
bool TreeMap<KeyType,ValType>::hasKey (const KeyType &key) const
{
    typename TreeMap<KeyType,ValType>::KVPair search (key,ValType());
    return pairs.member (search);
}

template <class KeyType, class ValType>
typename TreeMap<KeyType,ValType>::ConstIterator
     TreeMap<KeyType,ValType>::begin() const
{
    return TreeMap<KeyType,ValType>::ConstIterator(pairs);
}

template <class KeyType, class ValType>
typename TreeMap<KeyType,ValType>::ConstIterator
     TreeMap<KeyType,ValType>::end() const
{
    return TreeMap<KeyType,ValType>::ConstIterator(pairs,true);

}

template <class KeyType, class ValType>
TreeMap<KeyType,ValType>::KVPair::KVPair ()
{}

template <class KeyType, class ValType>
TreeMap<KeyType,ValType>::KVPair::KVPair (const KeyType &k, const ValType &v):key(k),val(v)
{}

template <class KeyType, class ValType>
bool TreeMap<KeyType,ValType>::KVPair::
    operator <= (const typename TreeMap<KeyType,ValType>::KVPair &pair) const
{
    return key <= pair.key;
}    

template <class KeyType, class ValType>
bool TreeMap<KeyType,ValType>::KVPair::
    operator == (const typename TreeMap<KeyType,ValType>::KVPair &pair) const
{
    return key == pair.key;
}    

#endif