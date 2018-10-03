#include "dllist.h"

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

}


template <class T>
DLList<T>& DLList<T>::operator= (const DLList<T> &other)
{

}

template <class T>
T& DLList<T>::operator [] (size_t index)
{
  //само за да се компилира
  return first->data;
}

template <class T>
void DLList<T>::push (const T &data)
{
//first сочи нещо

  first = new dllnode<T> (data,first,nullptr);
  first->next->prev = first;
}

template <class T>
T& DLList<T>::top ()
{
  //само за да се компилира
  return first->data;
}

template <class T>
void DLList<T>::pop ()
{

}
template <class T>
DLList<T>::~DLList ()
{

}
