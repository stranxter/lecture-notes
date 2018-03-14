#include <iostream>
#include <cassert>

template <class T>
class Array
{
public:

  Array ()
  {/* Този метод ще бъде изпълнен автоматично
    при декларация на обект по следния начин:
    Array<X> a;
    */
    _size = 0;
    buffer = nullptr;
  }

  void insert (T x)
  {
    /*
      buffer: указател към буфер в паметта (в хийпа),
      съдържащ текущите елементи на масива. Заделен
      от предишни обръщения към методи на Array
      _size: брой на елементите в buffer
    */

    T* newBuffer = new T[_size+1];

    /*
      newBuffer: указател към НОВ буфер в паметта с
      размер _size+1. Стийностите на елементите на
      newBuffer са неинициализирани.
    */
    for (int i = 0; i < _size; i++)
    {
      newBuffer[i] = buffer[i];
    }
    newBuffer[_size] = x;

    if (_size > 0)
    {
      delete []buffer;
    }

    buffer = newBuffer;
    _size++;
  }
  int size ()
  {
    return _size;
  }

  T& operator [] (int index)
  //std::cout << a[0]; | a.operator[] (0)
  //a[0] = 10;
  {
    assert (index >= 0);
    assert (index < _size);

    return buffer[index];
  }

  void print ()
  {
    std::cout << "[";
    for (int i = 0; i < _size; i++)
    {
      std::cout << buffer[i] << " ";
    }
    std::cout << "]";
  }

  void operator = (Array<T> other)
  {
    /*
      buffer: указател към буфер в паметта (в хийпа),
      съдържащ текущите елементи на масива. Заделен
      от предишни обръщения към методи на Array
      _size: брой на елементите в buffer
    */

    if (buffer != other.buffer)
    {
      delete []buffer;
      buffer = new T[other._size];
      _size = other._size;

      for (int i = 0; i < _size; i++)
      {
        buffer[i] = other.buffer[i];
      }
    }
  }

  bool operator != (Array<T> other)
  {
    return !(*this == other);
  }

  bool operator == (Array<T> other)
  {
    if (_size != other._size)
    {
      return false;
    }
    for (int i = 0; i < _size; i++)
    {
      if (buffer[i] != other.buffer[i])
      {
        return false;
      }
    }
    return true;
  }

  T* buffer;
  int _size;
};


int main ()
{

  //Array<int> a = {1,2,3,4,5,6};
  Array<int> a;

  a.insert (1);
  a.insert (2);
  a.insert (3);
  a.insert (4);
  a.insert (5);
  a.insert (6);

  assert (a.size () == 6);

  a.print();

  assert (a[0] == 1);
  assert (a[5] == 6);


  Array<int> b;

  //...

  b = a;

  assert (a[0] == b[0] &&
          a[5] == b[5] &&
          a.size() == b.size());

  b.insert (10);
  assert (b.size () == a.size() + 1);

  b.print();

  b = a;
  assert (a == b);

  b.insert (10);
  assert (a != b);
  assert (b.size () == a.size() + 1);

  b = a;
  a[0] = 10;
  assert (a[0] == 10);
  assert (b[0] == 1);


/*  assert (a.member(4));
  assert (!a.member(7));

  a.delete (3);
  assert (!a.member(3));
  assert (a.member(2));

*/

}
