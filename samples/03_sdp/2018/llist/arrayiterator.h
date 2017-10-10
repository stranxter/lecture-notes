#ifndef __ARRAYITERATOR_H
#define __ARRAYITERATOR_H


#include "baseiterator.h"
#include <cstdlib>

template <class ElemType>
class ArrayIterator : public BaseIterator<ElemType>
{
public:

  ArrayIterator (ElemType*, size_t);
  ElemType& getNext ();
  bool more ();

private:
  ElemType *arr;
  size_t size;
  size_t current;
};

#endif
