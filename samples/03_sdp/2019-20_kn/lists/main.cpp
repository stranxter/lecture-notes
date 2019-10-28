#define DOCTEST_CONFIG_IMPLEMENT

#include "doctest.h"
#include "dllist.h"
#include "dllist.cpp"
#include "slist.cpp"
#include "filter_iterator.cpp"

#include "tests.h"
/*
    Функции от високо ниво над итератори
*/

template <class Iterator, class ElType>
void map(const Iterator &start,
         const Iterator &end,
         ElType (*f)(const ElType &))
{
    Iterator i = start;

    while (i != end)
    {
        *i = f(*i);
        ++i;
    }
}

template <class Iterator, class ElType>
ElType reduce(const Iterator &start,
              const Iterator &end,
              ElType (*op)(const ElType &, const ElType &),
              ElType null_val)
{
    Iterator i = start;

    ElType accum = null_val;

    while (i != end)
    {
        accum = op(accum, *i);
        ++i;
    }

    return accum;
}

//двойка от еднотипни полета
template <class T>
using couple = std::pair<T,T>;

template <class Iterator, class ElType>
couple<FilterIterator<Iterator, ElType>> filter(const Iterator &start,
                                                const Iterator &end,
                                                bool (*pred)(const ElType &))
{
    couple <FilterIterator<Iterator, ElType>> result =
        //итератор към начлото на филтрирания интервал
        {FilterIterator<Iterator, ElType>(start, end, pred),
         //итератор към края на филтрирания интервал
         FilterIterator<Iterator, ElType>(end, end, pred)};

    return result;
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


