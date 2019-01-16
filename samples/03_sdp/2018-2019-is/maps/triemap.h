#ifndef __TRIE_H
#define __TRIE_H

#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stack>

template <class ValType>
struct TrieNode
{
  ValType *value;
  std::map<char,TrieNode<ValType>*> children;

  TrieNode (ValType *_v):value(_v){}

};

template <class ValType>
struct StackNode
{
  std::string partialKey;
  TrieNode<ValType> *currentSubtree;
  typename std::map<char,TrieNode<ValType>*>::const_iterator currentChild;
  StackNode (const std::string &key,
             TrieNode<ValType> *crr,
             typename std::map<char,TrieNode<ValType>*>::const_iterator it)
                :partialKey (key), currentSubtree(crr), currentChild (it){}
  bool operator == (const StackNode<ValType> &other);

};

template <class ValType>
class TrieMapIterator
{
public:
  TrieMapIterator (TrieNode<ValType> *trieRoot, bool isEnd);

  std::string operator * ();
  TrieMapIterator<ValType>& operator ++ ();

  bool operator == (const TrieMapIterator&);
  bool operator != (const TrieMapIterator&);

private:

  std::stack<StackNode<ValType>> itStack;
  /* Проверява дали е настъпило условието, при
     което обхождането трябва да "пропусне" изпълнението на
     програмата да продължи.
  */
  bool yieldCondition ();
  bool end ();

};


template <class ValType>
class TrieMap
{
public:
  TrieMap ();

  void update (const std::string&, const ValType&);
  bool hasKey (const std::string&) const;
  ValType get (const std::string&) const;
  void remove (const std::string&);

  void printDotty (std::ostream&);

  void printAllKeys ();

  TrieMapIterator<ValType> begin ();
  TrieMapIterator<ValType> end();

private:

    TrieNode<ValType>* traceOrCreatePath (const char* key,
                                          TrieNode<ValType> *current,
                                          const ValType &val);


    void printDottyHelper (std::ostream&,TrieNode<ValType>*);
    TrieNode<ValType>* locate (const char*, TrieNode<ValType>*) const;

    void printAllKeysHelper (TrieNode<ValType>*, std::string);


    TrieNode<ValType> *root;

};

#endif
