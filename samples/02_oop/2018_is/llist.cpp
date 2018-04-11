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
  LList ():first (nullptr){}

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
    box<T> *crr = first;

    while (crr != nullptr && pos > 0)
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

  template <class W>
  friend std::ostream& operator << (std::ostream& out, const LList<W> &l);

private:
  box<T> *first;
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

  l.insertAt (3, 100);

  std::cout << l;
}
