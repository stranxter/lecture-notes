#ifndef __DLLIST_H
#define __DLLIST_H

#include <cstddef>

template <class T>
struct dllnode
{
  T data;
  dllnode *next,*prev;
  dllnode (const T&, dllnode*, dllnode*);
};

template <class T>
class DLListIterator;

template <class T>
class DLList
{
public:
  DLList ();
  DLList (const DLList<T> &other);
  DLList& operator= (const DLList<T> &other);

  T& operator [] (size_t index);

  void push (const T&);
  T& top ();
  void pop ();

  size_t size ();

  DLListIterator<T> begin();
  DLListIterator<T> end();

  friend class DLListIterator<T>;

  ~DLList ();

private:
  dllnode<T> *first, *last;
  size_t crrsize;

  //----- ITERATION OPTIMIZATION -----
  dllnode <T> *lastFound;
  size_t lastFoundIndex;
  //----------------------------------

  void copy (const DLList<T> &other);
  void erase ();
};


template <class T>
class DLListIterator
{
public:
  DLListIterator (DLList<T>&,bool=false);
  T& operator * ();
  DLListIterator<T>& operator ++ ();
  DLListIterator<T>& operator -- ();

  bool operator != (const DLListIterator<T>&);

private:
  DLList<T> &list;
  dllnode<T> *currentElement;
};



#endif
