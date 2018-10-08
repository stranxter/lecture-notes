#include "dllist.h"
#include <cassert>

template <class T>
dllnode<T>::dllnode (const T &_data, dllnode *_next, dllnode *_prev)
    :data(_data),next(_next),prev(_prev)
{}

template <class T>
DLList<T>::DLList ()
{
    first = nullptr;
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

}


template <class T>
DLList<T>& DLList<T>::operator= (const DLList<T> &other)
{
  if (this != &other)
  {
    erase();
    copy (other);
  }
  return *this;
}

template <class T>
T& DLList<T>::operator [] (size_t index)
{
  assert (first != nullptr);
  //само за да се компилира
  return first->data;
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
}
template <class T>
DLList<T>::~DLList ()
{
  erase();
}
