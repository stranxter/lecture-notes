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

  ~DLList ();

private:
  dllnode<T> *first;

  void copy (const DLList<T> &other);
  void erase ();
};

#endif
