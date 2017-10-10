#ifndef __BASEITERATOR_H
#define __BASEITERATOR_H

template <class ElemType>
class BaseIterator
{
public:
  virtual ElemType& getNext () = 0;
  virtual bool more () = 0;
};


#endif
