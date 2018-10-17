#include "dllist.h"
#include <cassert>
#include <iostream>

template <class T>
dllnode<T>::dllnode (const T &_data, dllnode *_next, dllnode *_prev)
    :data(_data),next(_next),prev(_prev)
{}

template <class T>
DLList<T>::DLList ()
{
    first = nullptr;
    crrsize = 0;
    lastFoundIndex = -1;
    lastFound = nullptr;
    last = nullptr;
}

template <class T>
DLList<T>::DLList (const DLList<T> &other)
{
  copy (other);
}

template <class T>
void DLList<T>::copy (const DLList<T> &other)
{
  if (other.first == nullptr)
  {
    first = nullptr;
    last = nullptr;
    return;
  }
  first = new dllnode<T> (other.first->data,nullptr,nullptr);

  dllnode<T> *lastcreated = first;
  dllnode<T> *nexttocopy = other.first->next;

  while (nexttocopy != nullptr)
  {
    lastcreated->next = new dllnode<T> (nexttocopy->data,nullptr,lastcreated);
    lastcreated = lastcreated->next;
    nexttocopy = nexttocopy->next;
  }

  crrsize = other.crrsize;
  last = lastcreated;

  /*RESTART ITERATION*/
  lastFoundIndex = -1;
  lastFound = nullptr;

}

template <class T>
void DLList<T>::erase ()
{
  dllnode<T> *next;
  while (first != nullptr)
  {
    next = first->next;
    delete first;
    first = next;
  }

  crrsize = 0;
  last = nullptr;
  /*RESTART ITERATION*/
  lastFoundIndex = -1;
  lastFound = nullptr;

}


template <class T>
DLList<T>& DLList<T>::operator= (const DLList<T> &other)
{
  if (this != &other)
  {
    erase();
    copy (other);
    /*RESTART ITERATION*/
    lastFoundIndex = -1;
    lastFound = nullptr;
  }
  return *this;
}

template <class T>
T& DLList<T>::operator [] (size_t index)
{
  assert (first != nullptr);
  //само за да се компилира

  if (lastFoundIndex != -1 &&
      lastFoundIndex == index-1)
  {
      assert (lastFound != nullptr);
      lastFound = lastFound->next;
  } else if (lastFoundIndex != -1 &&
             lastFoundIndex == index+1)
  {
      assert (lastFound != nullptr);
      lastFound = lastFound->prev;
  } else {
    lastFound = first;
    while (lastFound != nullptr && index > 0)
    {
      lastFound = lastFound->next;
      index--;
    }
  }

  //ИЗКЛЮЧЕНА ОПТИМИЗИАЦИЯ!
  //lastFoundIndex = index;
  assert (lastFound != nullptr);
  return lastFound->data;
}

template <class T>
void DLList<T>::push (const T &data)
{
//first сочи нещо

  first = new dllnode<T> (data,first,nullptr);
  if (first->next != nullptr)
  {
    first->next->prev = first;
  }

  crrsize++;
  if (last == nullptr)
  {
    last = first;
  }
  /*RESTART ITERATION*/
  lastFoundIndex = -1;
  lastFound = nullptr;

}

template <class T>
T& DLList<T>::top ()
{
  assert (first != nullptr);
  //само за да се компилира
  return first->data;
}

template <class T>
void DLList<T>::pop ()
{
  assert (first != nullptr);
  dllnode<T> *next = first->next;
  delete first;
  first = next;
  crrsize--;
  if (first == nullptr)
  {
    last = nullptr;
  }
  /*RESTART ITERATION*/
  lastFoundIndex = -1;
  lastFound = nullptr;

}
template <class T>
DLList<T>::~DLList ()
{
  erase();
}

template <class T>
size_t DLList<T>::size ()
{
  return crrsize;
}

template <class T>
DLListIterator<T> DLList<T>::begin()
{
  return DLListIterator<T> (*this);
}

template <class T>
DLListIterator<T> DLList<T>::end()
{
  return DLListIterator<T> (*this,true);
}



template <class T>
DLListIterator<T>::DLListIterator
    (DLList<T> &l, bool toEnd):list (l)
{
  if (!toEnd)
  {
    currentElement = list.first;
  } else {
    currentElement = nullptr;
  }
}

template <class T>
T& DLListIterator<T>::operator * ()
{
  assert (currentElement != nullptr);
  return currentElement->data;
}

template <class T>
DLListIterator<T>& DLListIterator<T>::operator ++ ()
{
  assert (currentElement != nullptr);
  currentElement = currentElement->next;
  return *this;
}

template <class T>
DLListIterator<T>& DLListIterator<T>::operator -- ()
{
  if (currentElement != nullptr)
  {
    currentElement = currentElement->prev;
  } else {
    currentElement = list.last;
  }
  assert (currentElement != nullptr);

  return *this;
}


template <class T>
bool DLListIterator<T>::operator != (const DLListIterator<T> &other)
{
  return currentElement != other.currentElement;
}
