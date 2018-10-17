#include "dynarray.h"
#include <cassert>

template <class T>
DynArray<T>::DynArray (size_t initialSize)
{
  size = initialSize;
  data = new T [size];
}

template <class T>
DynArray<T>::DynArray (const DynArray<T> &other)
{
  /* Логика на конструктора по подр.
  data = other.data;
  size = other.size;
  */
  copy (other);
}

template <class T>
DynArray<T>& DynArray<T>::operator = (const DynArray<T> &other)
{
  if (this != &other)
  {
    delete []data;
    copy (other);
  }
  return *this;
}


template <class T>
T& DynArray<T>::operator [] (size_t index)
{
  if (index >= size)
  {
    //data <- стари (текущи)данни

    T *save = data;

    data = new T[index+1];

    for (size_t count = 0; count < size; count++)
    {
       data[count] = save[count];
    }
    size = index + 1;
    delete []save;
  }

  return data[index];
}

template <class T>
size_t DynArray<T>::getSize () const
{
  return size;
}

template <class T>
DynArray<T>::~DynArray ()
{
  delete []data;
}

template <class T>
void DynArray<T>::copy (const DynArray<T> &other)
{
  data = new T [other.size];
  size = other.size;

  for (size_t count = 0; count < size; count++)
  {
      data[count] = other.data[count];
  }
}

template <class T>
DynArrayIterator<T> DynArray<T>::begin()
{
  return DynArrayIterator<T> (*this);
}

template <class T>
DynArrayIterator<T> DynArray<T>::end()
{
  return DynArrayIterator<T> (*this, true);
}


template <class T>
DynArrayIterator<T>::DynArrayIterator
     (DynArray<T> &da, bool toEnd):arr(da)
{
  if (toEnd)
  {
    currentElement = -1;
  } else {
    currentElement = 0;
  }
}

template <class T>
T& DynArrayIterator<T>::operator * ()
{
  assert (currentElement >= 0 && currentElement <= arr.getSize());
  return arr[currentElement];
}

template <class T>
DynArrayIterator<T>& DynArrayIterator<T>::operator ++ ()
{
  assert (currentElement >= 0 && currentElement < arr.getSize());
  currentElement++;
  if (currentElement == arr.getSize())
  {
    currentElement = -1;
  }
  return *this;
}

template <class T>
bool DynArrayIterator<T>::operator != (const DynArrayIterator<T> &other)
{
  return arr.data != other.arr.data ||
         currentElement != other.currentElement;
}
