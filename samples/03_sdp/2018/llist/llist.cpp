#include "llist.h"

template <class ElemType>
LList<ElemType>::LList():first(nullptr)
{
}

template <class ElemType>
LList<ElemType>::LList (const LList<ElemType>&other):first(nullptr)
{
  copy (other);
}

template <class ElemType>
void LList<ElemType>::push (const ElemType &x)
{
  first = new Node<ElemType> (x,first);
}

template <class ElemType>
const ElemType& LList<ElemType>::peek() const
{
  return first->data;
}

template <class ElemType>
bool LList<ElemType>::pop ()
{
  if (first == nullptr)
    return false;

  Node<ElemType>* tmp = first;
  first = first->next;
  delete tmp;

  return true;
}

template <class ElemType>
Node<ElemType> *LList<ElemType>::locate (unsigned int index) const

{
  Node<ElemType> *tmp = first;

  while (tmp != nullptr && index > 0)
  {
    tmp = tmp->next;
    index--;
  }

  return tmp;
}


template <class ElemType>
bool LList<ElemType>::remove (unsigned int index)
{
  if (index == 0)
    return pop();

  Node<ElemType> *tmp = locate (index-1);
  if (tmp == nullptr || tmp->next == nullptr)
    return false;

  Node<ElemType> *save = tmp->next;
  tmp->next = tmp->next->next;
  delete save;

  return false;
}

template <class ElemType>
bool LList<ElemType>::addAt (unsigned int index, const ElemType &x)
{
  if (index == 0)
  {
    push (x);
    return true;
  }

  Node<ElemType> *tmp = locate (index-1);
  if (tmp == nullptr)
    return false;

  tmp->next = new Node<ElemType> (x,tmp->next);
  return true;
}

template <class ElemType>
bool LList<ElemType>::empty () const
{
  return first == nullptr;
}

template <class ElemType>
void LList<ElemType>::pushBack (const ElemType &x)
{
  if (first == nullptr)
  {
    push (x);
    return;
  }

  Node<ElemType> *tmp = first;
  while (tmp->next != nullptr){
    tmp = tmp->next;
  }
  tmp->next = new Node<ElemType> (x,nullptr);
}


template <class ElemType>
const ElemType& LList<ElemType>::operator [] (unsigned int index) const
{
  Node<ElemType> *tmp = locate (index);
  assert (tmp != nullptr);
  return tmp->data;
}

template <class ElemType>
Node<ElemType>::Node (const ElemType &_d, Node<ElemType> *_n):data(_d),next(_n)
{

}

template <class ElemType>
LList<ElemType>& LList<ElemType>::operator = (const LList<ElemType> &other)
{
  if (this != &other)
  {
    clear();
    copy (other);
  }
  return *this;
}


template <class ElemType>
void LList<ElemType>::copy (const LList<ElemType> &other)
{
  first = nullptr;
  if (other.first == nullptr)
    return;

  first = new Node<ElemType> (other.first->data,nullptr);

  Node<ElemType> *mylast = first,
       *othernext = other.first->next;

  while (othernext != nullptr)
  {
    mylast->next = new Node<ElemType>(othernext->data, nullptr);
    mylast = mylast->next;
    othernext = othernext->next;
  }

}

template <class ElemType>
void LList<ElemType>::clear()
{
  while (pop()){}
}

template <class ElemType>
LList<ElemType>::~LList()
{
    clear();
}

template <class ElemType>
bool ListIterator<ElemType>::more ()
{
  return nextToBeAccessed != nullptr;
}

template <class ElemType>
ElemType& ListIterator<ElemType>::getNext ()
{

  assert (nextToBeAccessed != nullptr);
  ElemType& save = nextToBeAccessed->data;
  nextToBeAccessed = nextToBeAccessed->next;
  return save;
}
template <class ElemType>
ListIterator<ElemType>::ListIterator (Node<ElemType> *first)
{
  nextToBeAccessed = first;
}


template <class ElemType>
ListIterator<ElemType> LList<ElemType>::begin()
{
  ListIterator<ElemType> li (first);
  return li;
}
