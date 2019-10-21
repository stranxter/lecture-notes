#include "slist.h"
#include <cassert>
#include <cmath>

template <class T>
SList<T>::SList(comparator<T> _comp) : count(0), first(nullptr), comp (_comp)
{

}

template <class T>
SList<T>::SList(const SList &sl)
{
    copy (sl);
}

template <class T>
SList<T>::~SList()
{
    deleteall ();
}

template <class T>
void SList<T>::insertSorted(const T &element)
{
  
  count++;

  Node *pred = locate(element);

  if (pred == nullptr)
  {
      first = new SList<T>::Node (element, first, nullptr);
      return;     
  }
  
  pred->next = new SList<T>::Node (element, pred->next,nullptr);
  
}

template <class T>
T& SList<T>::operator[](size_t index)
{
    SList<T>::Node *crr = first;
    while (index > 0 && crr != nullptr)
    {
        crr = crr->next;
        --index;
    }
    assert (crr != nullptr);

    return crr->data;
}

template <class T>
bool SList<T>::member(const T &x) const
{

    if (first==nullptr)
    {
        return false;
    }
    
    SList<T>::Node *crr = first;

    while (crr->skip != nullptr && comp (crr->skip->data,x))
    {
        crr = crr->skip;
    }

    while (crr != nullptr && crr->data != x)
    {
        crr = crr->next;
    }

    return crr != nullptr;

}

template <class T>
size_t SList<T>::size() const
{
    return count;
}

template <class T>
SList<T> &SList<T>::operator=(const SList<T> &sl)
{
    if (this != &sl)
    {
        deleteall ();
        copy (sl);
    }
    return *this;

}

template <class T>
SList<T>::Node::Node(const T &_d, SList<T>::Node *n, SList<T>::Node *s)
{
    data = _d;
    next = n;
    skip = s;
}

template <class T>
typename SList<T>::Node* SList<T>::locate(const T &x) const
{

    if (first == nullptr || !comp (first->data,x))
    {
        return nullptr;
    }

    SList<T>::Node *crr = first;
    while (crr->next != nullptr && comp (crr->next->data,x))
    {
        crr = crr->next;
    }

    return crr;

}

template <class T>
void SList<T>::deleteall()
{
    SList<T>::Node *save = first;
    while (first != nullptr)
    {
        save = first->next;
        delete first;
        first = save;
    }
}

template <class T>
void SList<T>::copy(const SList<T> &sl)
{
    SList<T>::Node *other = sl.first,
                   *lastCreated = nullptr;

    first = nullptr;
    count = 0;
    if (other == nullptr)
    {
        return;
    }

    first = new SList<T>::Node (other->data,nullptr,nullptr);
    lastCreated = first;
    other = other->next;
    count = 1;

    while (other != nullptr)
    {
        lastCreated->next = new SList<T>::Node (other->data,nullptr,nullptr);
        lastCreated = lastCreated->next;
        other = other->next;
        ++count;
    }
}

template <class T>
void SList<T>::speedup()
{
    /*
        Обхожда списъка, избира всеки ~sqrt(n) елемент и со свързва
        чрез указателя skip със елемента, който е отдалечен на sqrt(n) от дадения
    */

   SList<T>::Node *crr = first,
                  *lastShortcut = first;
   size_t count = 0; 
   
   while (crr != nullptr)
   {
       crr = crr->next;
       count++;

       if (count >= sqrt (size()))
       {
           lastShortcut->skip = crr;
           lastShortcut = crr;
           count = 0;
       }
   }
}
