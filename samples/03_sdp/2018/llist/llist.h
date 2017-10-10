#ifndef __LIST_H
#define __LIST_H

#include "baseiterator.h"

template <class ElemType>
struct Node
{
  Node<ElemType> *next;
  ElemType data;
  Node (const ElemType&, Node<ElemType>*);
};

template <class ElemType>
class ListIterator : public BaseIterator<ElemType>
{
public:
  ListIterator(Node<ElemType>*);
  ElemType& getNext ();
  bool more ();
private:
  Node<ElemType> *nextToBeAccessed;
};

template <class ElemType>
class LList
{
public:
  LList();
  LList (const LList<ElemType>&);

  void push (const ElemType&);
  const ElemType& peek() const;
  bool pop ();
  bool remove (unsigned int);
  bool addAt (unsigned int, const ElemType&);
  bool empty () const;
  void pushBack (const ElemType&);

  const ElemType& operator [] (unsigned int) const;
  LList<ElemType>& operator = (const LList<ElemType>&);

  ListIterator<ElemType> begin();

  ~LList();

private:


  void copy (const LList <ElemType>&);
  void clear();
  Node<ElemType> *locate (unsigned int) const;

  Node<ElemType> *first;
};




#endif
