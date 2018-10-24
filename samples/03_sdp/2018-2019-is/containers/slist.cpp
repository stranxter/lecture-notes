#include "slist.h"
#include <cassert>
#include <cmath>
#include <iostream>

template <class T>
slnode<T>::slnode (const T &_data, slnode *_next, slnode *_skip)
       :data(_data)
{
  next[0] = _next;
  next[1] = _skip;
}

template <class T>
SList<T>::SList ()
{
  first = last = nullptr;
  crrsize = 0;
  skipLength = 0;
}

template <class T>
SList<T>::SList (const SList<T> &other)
{
    copy (other);
}

template <class T>
SList<T>& SList<T>::operator= (const SList<T> &other)
{
  if (this != &other)
  {
    erase ();
    copy (other);
  }
  return *this;
}

template <class T>
void SList<T>::push (const T&x)
{
  first = new slnode<T> (x,first,nullptr);
  if (last == nullptr)
  {
    last = first;
  }

  crrsize++;
  if (((int)sqrt(crrsize)) > skipLength)
  {
    optimize();
  }


}
template <class T>
size_t SList<T>::size ()
{
  return crrsize;
}

template <class T>
SListIterator<T> SList<T>::begin()
{
  return SListIterator<T> (*this);
}
template <class T>
SListIterator<T> SList<T>::find(const T&)
{
  return end();
}
template <class T>
SListIterator<T> SList<T>::end()
{
  return SListIterator<T> (*this,true);

}
template <class T>
SList<T>::~SList ()
{
  erase ();
}

template <class T>
void SList<T>::copy (const SList<T> &other)
{

}

template <class T>
void SList<T>::erase ()
{
}

template <class T>
void SList<T>::optimize ()
{
  skipLength = sqrt (crrsize);

  slnode<T> *crr = first,
            *lastFoundSkipElement = first;
  size_t index = 0;

  while (crr != nullptr)
  {
    crr->next[1] = nullptr;
    if ((index > 0 && index % skipLength == 0) ||
        crr->next[0] == nullptr
       )
    {
      lastFoundSkipElement->next[1] = crr;
      lastFoundSkipElement = crr;
    }
    crr = crr->next[0];
    index++;
  }
}


template <class T>
SListIterator<T>::SListIterator (SList<T> &_list,bool end)
   :list (_list)
{
  if (end)
  {
    currentElement = nullptr;
  } else {
    currentElement = list.first;
  }
}

template <class T>
void SList<T>::printDotty (std::ostream &out)
{
  slnode<T> *crr = first;
  out << "digraph G{\n";

  while (crr != nullptr)
  {
    out << (long)crr << "[label=\"" << crr->data << "\"];\n";

    if (crr->next[0] != nullptr)
    {
        out << (long)crr
            << "->"
            << (long)(crr->next[0])
            << ";\n";
    }

    if (crr->next[1] != nullptr)
    {
        out << (long)crr
            << "->"
            << (long)(crr->next[1])
            << ";\n";
    }

    crr = crr->next[0];
  }

  out << "}";

}


template <class T>
T& SListIterator<T>::operator * ()
{
  assert (currentElement != nullptr);
  return currentElement->data;
}

template <class T>
SListIterator<T>& SListIterator<T>::operator ++ ()
{
  assert (currentElement != nullptr);
  currentElement = currentElement->next[0];
  return *this;
}

template <class T>
bool SListIterator<T>::operator != (const SListIterator<T> &other)
{
  return currentElement != other.currentElement;
}

template <class T>
bool SListIterator<T>::operator == (const SListIterator<T> &other)
{
  return currentElement == other.currentElement;
}
