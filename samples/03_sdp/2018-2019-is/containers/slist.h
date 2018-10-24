#ifndef __SLIST_H
#define __SLIST_H

#include <cstddef>
#include <iostream>

template <class T>
struct slnode
{
  T data;
  slnode *next[2];
  slnode (const T&, slnode*, slnode*);
};

template <class T>
class SListIterator;

template <class T>
class SList
{
public:
  SList ();
  SList (const SList<T> &other);
  SList& operator= (const SList<T> &other);

  void push (const T&);

  size_t size ();

  SListIterator<T> begin();
  SListIterator<T> find(const T&);
  SListIterator<T> end();

  friend class SListIterator<T>;

  void printDotty (std::ostream&);

  ~SList ();

private:
  slnode<T> *first, *last;
  size_t crrsize;
  size_t skipLength;

  void copy (const SList<T> &other);
  void erase ();

  void optimize ();
};


template <class T>
class SListIterator
{
public:
  SListIterator (SList<T>&,bool=false);
  T& operator * ();
  SListIterator<T>& operator ++ ();

  bool operator != (const SListIterator<T>&);
  bool operator == (const SListIterator<T>&);

private:
  SList<T> &list;
  slnode<T> *currentElement;
};



#endif
