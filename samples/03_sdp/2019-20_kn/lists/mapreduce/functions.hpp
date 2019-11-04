#ifndef __FUNCTIONS_HPP
#define __FUNCTIONS_HPP

#include "sequence.hpp"
#include "mappediterator.hpp"

template <class Iterator, class Element, class Result>
Sequence<MappedIterator<Iterator, Element, Result>> 
       map(Sequence<Iterator> seq,
           mapfn<Element,Result> f)
{
    MappedIterator<Iterator, Element, Result> mibegin(seq.begin(), f);
    MappedIterator<Iterator, Element, Result> miend(seq.end(), f);

    return Sequence<MappedIterator<Iterator, Element, Result>>(mibegin, miend);
}

template <class Iterator, class Element>
Element reduce (Sequence<Iterator> seq,
                Element (*op)(const Element&, const Element&),
                Element null_val)
{
    Element accum = null_val;
    for (Element x : seq)
    {
        accum = op (accum,x);
    }

    return accum;
}

template <class Iterator, class Element>
Sequence<FilterIterator<Iterator, Element>>
            filter(Sequence<Iterator> seq,
                filterfn<Element> p)
{
    FilterIterator<Iterator, Element> fibegin(seq.begin(), seq.end(), p);
    FilterIterator<Iterator, Element> fiend(seq.end(), seq.end(), p);

    return Sequence<FilterIterator<Iterator, Element>>(fibegin, fiend);
}

#endif