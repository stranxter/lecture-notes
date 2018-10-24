#ifndef __DYNARRAY_H
#define __DYNARRAY_H

#include <cstddef>

template <class T>
class DynArrayIterator;

template <class T>
class DynArray
{
public:
  DynArray (size_t initialSize=10);
  DynArray (const DynArray<T>&);

  T& operator [] (size_t index);

  DynArray<T>& operator = (const DynArray<T> &other);

  size_t getSize () const;

  size_t find (const T& x);

  DynArrayIterator<T> begin();
  DynArrayIterator<T> end();

  ~DynArray ();

  friend class DynArrayIterator<T>;

private:
  T* data;
  size_t size;

  void copy (const DynArray<T> &other);

};

template <class T>
class DynArrayIterator
{
public:
  DynArrayIterator (DynArray<T> &da, bool toEnd = false);
  T& operator * ();
  DynArrayIterator<T>& operator ++ ();

  bool operator != (const DynArrayIterator<T>&);

private:
  unsigned int currentElement;
  DynArray<T>& arr;
};


#endif
