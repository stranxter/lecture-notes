#ifndef __MAPPEDITERATOR_HPP
#define __MAPPEDITERATOR_HPP

template <class Element, class Result>
using mapfn = Result (*)(const Element&);

template <class Iterator, class Element, class Result>
class MappedIterator
{
    public:
        MappedIterator(const Iterator& _or, mapfn<Element,Result> _f) : original(_or), f(_f) {}

        Result operator *()
        {
            return f(*original);
        }

        MappedIterator<Iterator,Element,Result>& operator ++()
        {
            ++original;
            return *this;
        };
        bool operator == (MappedIterator<Iterator, Element, Result> &it)
        {
            return original == it.original;
        }
        bool operator != (MappedIterator<Iterator, Element, Result> &it)
        {
            return original != it.original;
        }
    
    private:
        Iterator original;
        mapfn<Element, Result> f;
};

#endif
