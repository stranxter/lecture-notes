#include "arrayiterator.h"
#include <cassert>

template <class ElemType>
ArrayIterator<ElemType>::ArrayIterator (ElemType *_a, size_t _s):arr(_a),size(_s),current(0)
{

}

template <class ElemType>
ElemType& ArrayIterator<ElemType>::getNext ()
{
  assert (current < size);
  return arr[current++];
}

template <class ElemType>
bool ArrayIterator<ElemType>::more ()
{
  return current < size;
}
