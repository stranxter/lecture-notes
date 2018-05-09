#include <cassert>
#include <iostream>
#include <vector>

class IntSet
{
public:
  virtual bool member (int x) = 0;
};

class Interval : public IntSet
{
private:
  int start, end;
public:
  Interval (int _start, int _end):start(_start), end (_end)
  {
    assert (start <= end);
  }
  bool member (int x)
  {
    return (start <= x) && (x <= end);
  }

};

class EvenNumbers : public IntSet
{
public:
  bool member (int x)
  {
    return x % 2 == 0;
  }
};

class Container : public IntSet
{
private:
  int *elements;
  unsigned int capacity, currentSize;
public:
  Container (unsigned int _capacity)
  {
      capacity = _capacity;
      currentSize = 0;
      elements = new int [capacity];
  }
  bool add (int x)
  {
      if (!member(x) && currentSize < capacity)
      {
        elements[currentSize++] = x;
        return true;
      }
      return false;
  }
  bool member (int x)
  {
    for (int i = 0; i < currentSize; i++)
    {
      if (elements[i] == x)
      {
        return true;
      }
    }
    return false;
  }
  ~Container ()
  {
    delete elements;
  }
  Container (const Container &other)
  {
    copy (other);
  }
  Container& operator = (const Container &other)
  {
    if (this != &other)
    {
      delete elements;
      copy (other);
    }
    return *this;
  }
private:
  void copy (const Container &other)
  {
    capacity = other.capacity;
    currentSize = other.currentSize;
    elements = new int [capacity];
    for (int i = 0; i < capacity; i++)
    {
      elements[i] = other.elements[i];
    }
  }
};

class SetIntersection : public IntSet
{
/*
  i.add (&i1);
  i.add (&en);
*/
private:
  std::vector<IntSet*> mySets;
public:
  void add (IntSet *set)
  {
    mySets.push_back (set);
  }
  bool member (int x)
  {
    for (int i = 0; i < mySets.size(); i++)
    {
      if (!mySets[i]->member (x))
      {
        return false;
      }
    }
    return true;
  }

};



bool elementInAllSets (int element,
                       IntSet* sets[],
                       unsigned int nSets)
{
  for (int i = 0; i < nSets; i++)
  {
    if (!sets[i]->member (element))
    {
      return false;
    }
  }
  return true;
}

int main ()
{
  Interval i1 (0,100), i2 (99,200);

  assert (i1.member (50));
  assert (!i2.member (50));

  EvenNumbers en;

  assert (en.member (50));
  assert (!en.member (51));

  Container c1(5), c2 (3);

  c1.add (1);
  c1.add (2);
  c2.add (10);

  assert (c1.member (1));
  assert (!c1.member (10));
  assert (c2.member (10));
  assert (!c2.member (1));

  c2 = c1;
  c1.add (100);

  assert (c2.member (2));
  assert (!c2.member (100));

  c2 = c1;

  IntSet *sets[] = {&i1, &i2, &c1, &c2, &en};

  assert (elementInAllSets (100,sets,5));

  SetIntersection i;

  i.add (&i1);
  i.add (&en); //множеството на четните числа
               //в интервала между 0 и 100

  assert (i.member (50));
  assert (!i.member (102));
  assert (!i.member (51));
}
