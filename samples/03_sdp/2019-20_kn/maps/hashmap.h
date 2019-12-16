#ifndef __HASHMAP_H
#define __HASHMAP_H

#include <cstdlib>

template <class KeyType, class ValType>
class HashMap
{

    private:

    struct HTElement
    {
        KeyType key;
        ValType val;
        HTElement* next;
        HTElement (const KeyType&, const ValType&, HTElement*);
        HTElement ();
    };

    public:

    class Iterator
    {
        public:

        KeyType operator *();
        Iterator& operator ++();
        bool operator == (const Iterator&);
        bool operator != (const Iterator&);

        Iterator (HashMap&, bool);

        private:
        HashMap &hm;
        HTElement *pair;
        int index;

        void findNextPair ();
    };

    using hashfn = size_t (*) (const KeyType&, size_t);

    HashMap (hashfn,size_t);
    ValType& operator [] (const KeyType&);
    bool hasKey (const KeyType&);

    Iterator begin ();
    Iterator end();

    private:

    HTElement* findKVPair (size_t index, const KeyType&key);

    HTElement **table;
    hashfn h;
    size_t size;
};

#endif