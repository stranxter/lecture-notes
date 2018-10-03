#ifndef __DYNARRAY_H
#define __DYNARRAY_H

#include <cstddef>

template <class T>
class DynArray
{
public:
  DynArray (size_t initialSize=10);
  DynArray (const DynArray<T>&);

  T& operator [] (size_t index);

  DynArray<T>& operator = (const DynArray<T> &other);

  size_t getSize () const;

  ~DynArray ();
private:
  T* data;
  size_t size;

  void copy (const DynArray<T> &other);

};


#endif
