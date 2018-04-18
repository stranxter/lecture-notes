#include <iostream>
#include <cassert>

template <class T>
struct box
{
    T data;
    box<T> *next;
    box (const T& _d,box<T> *_n):data(_d),next(_n){}
};

template <class T>
class LList
{
public:
  LList ():first (nullptr),lastIndexedPosition(-2){}

private:
  void copyFrom (const box<T> *othercrr)
  {
    if (othercrr == nullptr)
    {
      first = nullptr;
      return;
    }

    box<T> *mycrr = nullptr;

    first = new box<T> (othercrr->data,nullptr);
    mycrr = first;
    othercrr = othercrr->next;

    while (othercrr != nullptr)
    {
      mycrr->next = new box<T> (othercrr->data,nullptr);
      mycrr = mycrr->next;
      othercrr = othercrr->next;
    }

  }

  void destroyList ()
  {
    /*while (first != nullptr)
    {
      pop();
    }*/
    box<T> *crr = first, *save;
    while (crr != nullptr)
    {
      save = crr;
      crr = crr->next;
      delete save;
    }
    first = nullptr;
  }
public:

  T& operator [] (unsigned int pos)
  {
    if (pos == lastIndexedPosition+1)
    {
      lastIndexedPosition = pos;
      lastIndexedElement = lastIndexedElement->next;
      return lastIndexedElement->data;
    }
    box<T> *crr = first;
    for (unsigned int i = 0; i < pos; i++)
    {
      assert (crr != nullptr);
      crr = crr->next;
    }
    assert (crr != nullptr);

    lastIndexedPosition = pos;
    lastIndexedElement = crr;
    return crr->data;

  }

  LList (const LList<T>& other):lastIndexedPosition(-2)
  {
    //other.first
    //first
    copyFrom (other.first);

  }

  LList<T>& operator = (const LList<T> &other)
  {
    if (this != &other)
    {
      destroyList ();
      copyFrom (other.first);
    }
    return *this;
  }

  ~LList ()
  {
    destroyList();
  }

  void push (const T& d)
  {
      first = new box<T> (d, first);
  }

  bool member (const T& x)
  {
    box<T> *crr = first;

    while (crr != nullptr && x != crr->data)
    {
      crr = crr->next;
    }
    //crr == nullptr OR x == crr->data
    return crr != nullptr;

  }

  unsigned int count (const T& x)
  {
    box<T> *crr = first;
    unsigned int result = 0;

    while (crr != nullptr)
    {
      if (x == crr->data)
      {
        result++;
      }
      crr = crr->next;
    }
    //crr == nullptr OR x == crr->data
    return result;

  }

  bool insertAt (unsigned int pos, const T& x)
  {

    if (pos == 0)
    {
      push (x);
      return true;
    }

    box<T> *crr = first;

    while (crr != nullptr && pos > 1)
    {
      crr = crr->next;
      pos--;
    }
    if (crr == nullptr)
    {
      return false;
    }
    crr->next = new box<T> (x,crr->next);

    return true;
  }

  void pop ()
  {
    if (first == nullptr)
    {
      return;
    }
    box<T> *save = first;
    first = first->next;
    delete save;
  }

  template <class W>
  friend std::ostream& operator << (std::ostream& out, const LList<W> &l);

private:
  box<T> *first;
  unsigned int lastIndexedPosition;
  box<T> *lastIndexedElement;
};
template <class T>
std::ostream& operator << (std::ostream& out, const LList<T> &l)
{
    out << "{";
    box<T> *crr = l.first;
    while (crr != nullptr)
    {
      out << crr->data << " ";
      crr = crr->next;
      /*if (crr != nullptr)
      {
        crr = crr->next;
      }*/
    }
    out << "}";

    return out;
}

int main ()
{
  LList<int> l;

  l.push (2);
  l.push (0);
  l.push (1);
  l.push (2);
  l.push (3);
  l.push (4);
  l.push (2);

  assert (l.member(3));
  assert (!l.member(5));
  assert (l.count(2) == 3);
  assert (l.count(5) == 0);
  assert (l.count(4) == 1);

  l.insertAt (0, 100);
  l.insertAt (1, 200);

  assert (l.member(100));
  l.pop();
  assert (!l.member(100));


  LList<int> l2 (l);

  l.insertAt (1,99);
  assert (l.member(99));
  assert (!l2.member(99));

  l = l2;
  std::cout << l << std::endl;
  std::cout << l2 << std::endl;
  l.insertAt (1,99);
  assert (l.member(99));
  assert (!l2.member(99));

  assert (l2[2] == 4);
  l2[2] = 5;
  assert (l2[2] == 5);
  std::cout << l2 << std::endl;

  for (int i = 0; i < 5; i++)
  {
    std::cout <<  l[i] << ",";
  }

}
