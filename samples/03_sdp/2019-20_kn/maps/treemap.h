#ifndef __TREEMAP_H
#define __TREEMAP_H

#include "../trees/botree.h"

template <class KeyType, class ValType>
class TreeMap
{
    private:
 
    struct KVPair
    {
        KeyType key;
        ValType val;
        KVPair ();
        KVPair (const KeyType&, const ValType&);
        //!!! сравняват само по ключ !!!
        bool operator == (const typename TreeMap<KeyType,ValType>::KVPair&) const;
        bool operator <= (const typename TreeMap<KeyType,ValType>::KVPair&) const;
    };
 
    BOTree<KVPair> pairs;

    public:

    class ConstIterator
    {

        public:

        KeyType operator *() const;
        ConstIterator& operator ++();
        bool operator == (const ConstIterator&) const;
        bool operator != (const ConstIterator&) const;

        ConstIterator (const BOTree<KVPair>&, bool=false);

        private:
            typename BOTree<KVPair>::ConstIterator treeit;
    };

    ValType& operator [] (const KeyType&);
    bool hasKey (const KeyType&) const;

    ConstIterator begin() const;
    ConstIterator end() const;


};

#endif

