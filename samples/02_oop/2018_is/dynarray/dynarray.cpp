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

  /*Array ()
  {

  }*/

  Array (const Array<T> &other)
  {/* Този метод ще бъде изпълнен автоматично
    при декларация на обект по следния начин:
    Array<X> a (b);
    където b също е обект от клас Array
    */

    buffer = new T[other._size];
    _size = other._size;

    for (int i = 0; i < _size; i++)
    {
      buffer[i] = other.buffer[i];
    }
  }

  Array (unsigned int x)
  {
    buffer = new T [x];
    for (int i = 0; i < x; i++)
    {
      buffer[i] = x;
    }
    _size = x;
  }

  Array (const char *s)
  {
    //buffer, _size
    _size = strlen (s) + 1;
    buffer = new T [_size];

    for (int i = 0; i < _size; i++)
    {
      buffer[i] = s[i];
    }
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

  void print (std::ostream& out)
  {
    out << "[";
    for (int i = 0; i < _size; i++)
    {
      out << buffer[i];
      out << " ";
    }
    out << "]";
  }

/*  void operator << (ostream& out)
  {
    print (out);
  }
*/
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

  ~Array ()
  {
    delete []buffer;
  }

  T* buffer;
  int _size;
};

template <class T>
void operator << (std::ostream& out, Array<T> a)
{
    a.print (out);
}

template <class T>
void f (const Array<T> &a)
{
  std::cout << a;
}

int main ()
{
  //Array<int> a = {1,2,3,4,5,6};
  Array<int> a;

  f(a);
  f<int>(7);

  a.insert (1);
  a.insert (2);
  a.insert (3);
  a.insert (4);
  a.insert (5);
  a.insert (6);

  assert (a.size () == 6);

  //a.print (std::cout)
  std::cout << a;

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

  b.print(std::cout);

  b = a;
  assert (a == b);

  b.insert (10);
  assert (a != b);
  assert (b.size () == a.size() + 1);

  b = a;
  a[0] = 10;
  assert (a[0] == 10);
  assert (b[0] == 1);

  Array<int> c = a;
  assert (c.size() == a.size());
  assert (c[1] == a[1]);
  a[1] =200;
  assert (c[1] != a[1]);

  Array<int> z = 4;
  assert (z.size() == 4);
  assert (z[3] == 4);

  Array<int> r = "Hello";
  assert (r.size () == 6);
  assert (r[0] == 'H');

  Array<Array<int>> iaa;

  iaa.insert (a);
  iaa.insert (b);
  iaa.insert (c);
  iaa.insert (r);
  iaa.insert (z);

  assert (iaa[2][0] == 10);

  std::cout << iaa;

  //Array<T> d = {1,2,3,4};


/*  assert (a.member(4));
  assert (!a.member(7));

  a.delete (3);
  assert (!a.member(3));
  assert (a.member(2));

*/



}
