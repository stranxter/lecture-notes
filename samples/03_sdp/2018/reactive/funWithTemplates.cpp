#include <iostream>

template <class T>
class FilterStream;

template <class T>
class MapStream;

template <class A, class B>
class SumStream;
template <class A, class B>
class ZipStream;

template <typename T>
class StreamBase
{
public:
  FilterStream<T> filter (bool(*pred)(int));
  MapStream<T> map (int(*f)(int));
  T print (unsigned int n, std::ostream& out =std::cout);
  template <class SecondStream>
  SumStream<T,SecondStream> sum (SecondStream s2);
  template <class SecondStream>
  ZipStream<T,SecondStream> zip (SecondStream s2, int (*comb)(int,int));

};

class RepeatStream : public StreamBase<RepeatStream>
{
public:

  RepeatStream (int e):element (e){}
  int operator * () {return element;}
  RepeatStream operator ++ ()
  {
    return *this;
  }

public:
  int element;
};


class AllInts : public StreamBase<AllInts>
{
public:

  AllInts ():crr (0){}
  int operator * () {return crr;}
  AllInts operator ++ ()
  {
    crr++;
    return *this;
  }

public:
  int crr;
};

template <class T>
class FilterStream : public StreamBase<FilterStream<T>>
{
public:
  FilterStream (bool(*_p)(int), T src):p(_p),source(src)
  {
    wind();
  };

  int operator * () {return *source;}

  FilterStream& operator ++ ()
  {
    ++source;
    wind();
    return *this;
  }

private:
  void wind ()
  {
    while (!p(*source))
    {
      ++source;
    }
  }
  bool(*p)(int);
  T source;
};

template <class T>
class MapStream : public StreamBase<MapStream<T>>
{
public:
  MapStream (int(*_f)(int), T src):f(_f),source(src)
  {

  }
  int operator * () {return f(*source);}

  MapStream& operator ++ ()
  {
    ++source;
    return *this;
  }

private:
  int(*f)(int);
  T source;
};


template <class A, class B>
class SumStream : public StreamBase<SumStream<A,B>>
{
public:
  SumStream (A src1, B src2):source1(src1), source2 (src2)
  {

  }
  int operator * () {return *source1 + *source2;}

  SumStream& operator ++ ()
  {
    ++source1;
    ++source2;
    return *this;
  }

private:
  A source1;
  B source2;
};


template <class A, class B>
class ZipStream : public StreamBase<ZipStream<A,B>>
{
public:
  ZipStream (A src1, B src2, int(*_comb)(int,int))
      :source1(src1), source2 (src2), comb(_comb)
  {

  }
  int operator * () {return comb(*source1,*source2);}

  ZipStream& operator ++ ()
  {
    ++source1;
    ++source2;
    return *this;
  }

private:
  A source1;
  B source2;
  int (*comb)(int,int);
};


template <class T>
FilterStream<T> StreamBase<T>::filter (bool(*pred)(int))
{
  return FilterStream<T>(pred,(T&)(*this));
}
template <class T>
MapStream<T> StreamBase<T>::map (int(*f)(int))
{
  return MapStream<T>(f,(T&)(*this));
}

template <class T>
T StreamBase<T>::print (unsigned int n, std::ostream &out)
{
  while (n-- > 0)
  {
    out << *((T&)(*this)) << " ";
    ++((T&)(*this));
  }

  return (T&)(*this);
}

template <class T>
template <class SecondStrem>
SumStream<T,SecondStrem> StreamBase<T>::sum (SecondStrem s2)
{
  return SumStream<T,SecondStrem> ((T&)(*this),s2);
}

template <class T>
template <class SecondStream>
ZipStream<T,SecondStream> StreamBase<T>::zip (SecondStream s2, int (*comb)(int,int))
{
  return ZipStream<T,SecondStream> ((T&)(*this),s2,comb);
}


bool even (int x) {return x % 2 == 0;}
bool endsWith2 (int x) {return x % 10 == 2;}
int plus1 (int x) {return x+1;}
int mult (int x, int y) {return x*y;}

int main ()
{
  AllInts ints;

  //отпечатване на числата, които се получават при
  //добавяме на 1 към първите 3 четни числа, които
  //завършват на цифрата 2. Следват следващите 3 такива
  //числа, но с добавена още 1 единица
  ints.filter(even)
      .filter(endsWith2)
      .map(plus1)
      .print(3,std::cout)
      .map(plus1)
      .print(3,std::cout);

  std::cout << std::endl;

  RepeatStream ones (1);

  ints.sum(ones).print(2);

  std::cout << std::endl;

  ones.sum(ones).print (5);

  std::cout << std::endl;

  ints.zip(ints,mult).print (5);
}
