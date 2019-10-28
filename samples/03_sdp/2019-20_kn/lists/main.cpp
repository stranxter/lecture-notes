#define DOCTEST_CONFIG_IMPLEMENT

#include "doctest.h"
#include "dllist.h"
#include "dllist.cpp"
#include "slist.cpp"

#include "tests.h"

/*
    Функции от високо ниво над итератори
*/
#include "sequence.hpp"
#include "filter_iterator.cpp"
#include "map_iterator.hpp"

template <class Iterator, class Element>
void map(Sequence<Iterator> seq,
         Element (*f)(const Element &))
{
    for (Element& e: seq)
    {
        e = f (e);
    }    
}

template <class Iterator, class Element>
Element reduce(Sequence<Iterator> seq,
               Element (*op)(const Element &, const Element &),
               Element null_val)
{
    Element accum = null_val;
    for (Element e : seq)
    {
        accum = op(accum, e);
    }
    return accum;
}

template <class Iterator, class Element>
Sequence<FilterIterator<Iterator,Element>> filter(Sequence<Iterator> &seq,
                          bool (*pred)(const Element &))
{

    return Sequence<FilterIterator<Iterator, Element>>
         (FilterIterator<Iterator, Element>(seq.begin(), seq.end(), pred),
          FilterIterator<Iterator, Element>(seq.end(), seq.end(), pred));
}

template <class Iterator, class Element>
Sequence<MapIterator<Iterator,Element>> mapf(Sequence<Iterator> seq,
                                             Element (*f)(const Element &))
{
    MapIterator<Iterator,Element> mappedIterBegin (seq.begin(), seq.end(), f);
    MapIterator<Iterator, Element> mappedIterEnd (seq.end(), seq.end(), f);

    return Sequence<MapIterator<Iterator, Element>> (mappedIterBegin, mappedIterEnd);
    
}

/*
    Изчислителни функции
*/

int plus(const int &x, const int &y)
{ return x + y; }

int inc(const int &x)
{ return x + 1; }

bool even(const int &x)
{ return x % 2 == 0; }

bool noteven(const int &x)
{ return x % 2 != 0; }

/*
    Тестове за итераторите
*/
#include "iter_tests.h"

int main ()
{
    // пускане на тестовете
    doctest::Context().run();
}


