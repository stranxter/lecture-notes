#include <iostream>

template <class ElemType, class StreamType>
class FilterStream;

/*template <class T>
class MapStream;

template <class A, class B>
class SumStream;

template <class A, class B>
class ZipStream;

template <class A, class B>
class ZigZagStream;
*/
template <class ElemType,class StreamType>
class StreamBase
{
public:
  FilterStream<ElemType,StreamType> filter (bool(*pred)(ElemType));
  StreamType print (unsigned long n, std::ostream& out =std::cout);
  /*MapStream<T> map (long(*f)(long));
  template <class SecondStream>
  SumStream<T,SecondStream> sum (SecondStream s2);
  template <class SecondStream>
  ZipStream<T,SecondStream> zip (SecondStream s2, long (*comb)(long,long));
  template <class SecondStream>
  ZigZagStream<T,SecondStream> zigzag (SecondStream s2);
*/
};

/*
class RepeatStream : public StreamBase<RepeatStream>
{
public:

  RepeatStream (long e):element (e){}
  long operator * () {return element;}
  RepeatStream operator ++ ()
  {
    return *this;
  }

public:
  long element;
};
*/

template <class ElemType>
class Alllongs : public StreamBase<ElemType,Alllongs<ElemType>>
{
public:

  Alllongs (ElemType init):crr (init){}
  ElemType operator * () {return crr;}
  Alllongs operator ++ ()
  {
    crr++;
    return *this;
  }

public:
  ElemType crr;
};

template <class ElemType, class StreamType>
class FilterStream : public StreamBase<ElemType,FilterStream<ElemType,StreamType>>
{
public:
  FilterStream (bool(*_p)(ElemType), StreamType src):p(_p),source(src)
  {
    wind();
  };

  ElemType operator * () {return *source;}

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
  bool(*p)(ElemType);
  StreamType source;
};
/*
template <class T>
class MapStream : public StreamBase<MapStream<T>>
{
public:
  MapStream (long(*_f)(long), T src):f(_f),source(src)
  {

  }
  long operator * () {return f(*source);}

  MapStream& operator ++ ()
  {
    ++source;
    return *this;
  }

private:
  long(*f)(long);
  T source;
};

template <class A, class B>
class SumStream : public StreamBase<SumStream<A,B>>
{
public:
  SumStream (A src1, B src2):source1(src1), source2 (src2)
  {

  }
  long operator * () {return *source1 + *source2;}

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
  ZipStream (A src1, B src2, long(*_comb)(long,long))
      :source1(src1), source2 (src2), comb(_comb)
  {

  }
  long operator * () {return comb(*source1,*source2);}

  ZipStream& operator ++ ()
  {
    ++source1;
    ++source2;
    return *this;
  }

private:
  A source1;
  B source2;
  long (*comb)(long,long);
};

template <class A, class B>
class ZigZagStream : public StreamBase<ZigZagStream<A,B>>
{
public:
  ZigZagStream (A src1, B src2)
      :source1(src1), source2 (src2),streamOne(true)
  {

  }
  long operator * ()
  {
    return (streamOne?*source1:*source2);
  }


  ZigZagStream& operator ++ ()
  {
    if (streamOne)
      ++source1;
    else
      ++source2;
    streamOne = !streamOne;

    return *this;
  }

private:

  A source1;
  B source2;
  bool streamOne;
};

class AxisStream : public StreamBase<AxisStream>
{
public:
  AxisStream (long(*_f)(long), long _y0):f(_f),y(_y0)
  {

  }
  long operator * () {return y;}

  AxisStream& operator ++ ()
  {
    y = f(y);
    return *this;
  }

private:
  long(*f)(long);
  long y;
};
*/
template <class ElemType, class StreamType>
FilterStream<ElemType,StreamType> StreamBase<ElemType,StreamType>::filter (bool(*pred)(ElemType))
{
  return FilterStream<ElemType,StreamType>(pred,(StreamType&)(*this));
}

template <class ElemType, class StreamType>
StreamType StreamBase<ElemType,StreamType>::print (unsigned long n, std::ostream &out)
{

  while (n-- > 0)
  {
    out << *((StreamType&)(*this)) << " ";
    ++((StreamType&)(*this));
  }

  return (StreamType&)(*this);
}


/*

template <class T>
MapStream<T> StreamBase<T>::map (long(*f)(long))
{
  return MapStream<T>(f,(T&)(*this));
}


template <class T>
template <class SecondStrem>
SumStream<T,SecondStrem> StreamBase<T>::sum (SecondStrem s2)
{
  return SumStream<T,SecondStrem> ((T&)(*this),s2);
}

template <class T>
template <class SecondStream>
ZipStream<T,SecondStream> StreamBase<T>::zip (SecondStream s2, long (*comb)(long,long))
{
  return ZipStream<T,SecondStream> ((T&)(*this),s2,comb);
}

template <class T>
template <class SecondStream>
ZigZagStream<T,SecondStream> StreamBase<T>::zigzag (SecondStream s2)
{
  return ZigZagStream<T,SecondStream> ((T&)(*this),s2);
}

*/
bool even (long x) {return x % 2 == 0;}
bool endsWith2 (long x) {return x % 10 == 2;}
long plus1 (long x) {return x+1;}
long mult (long x, long y) {return x*y;}
long sqr (long x) {return x*x;}

bool pred (char x)
{
  return x > 'e';
}

int main ()
{
  Alllongs<char> longs ('a');

  longs.filter (pred).print (5);

  //отпечатване на числата, които се получават при
  //добавяме на 1 към първите 3 четни числа, които
  //завършват на цифрата 2. Следват следващите 3 такива
  //числа, но с добавена още 1 единица
  /*longs.filter(even)
      .filter(endsWith2)
      .map(plus1)
      .print(3,std::cout)
      .map(plus1)
      .print(3,std::cout);

  std::cout << std::endl;

  RepeatStream ones (1);

  longs.sum(ones).print(2);

  std::cout << std::endl;

  ones.sum(ones).print (5);

  std::cout << std::endl;

  longs.zip(longs,mult).print (5);

  std::cout << std::endl;

  longs.zigzag(longs.zip(longs,mult)).print (10);

  std::cout << std::endl;

  AxisStream axis (sqr,2);

  axis.print (4);

  std::cout << std::endl;

  (axis.sum(ones)).print (2);
*/

  return 0;
}
