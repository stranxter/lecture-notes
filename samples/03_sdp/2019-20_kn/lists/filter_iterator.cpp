#include "filter_iterator.h"

template <class Iterator, class ElemType>
FilterIterator<Iterator,ElemType>::FilterIterator
   (const Iterator &_start, 
    const Iterator &_end,
    bool (*_pred)(const ElemType &)) : start(_start),
                                       end(_end),
                                       pred(_pred)

{
    ensureNextIsOK();
}

template <class Iterator, class ElemType>
void FilterIterator<Iterator, ElemType>::ensureNextIsOK()
{
    while (start != end && !pred(*start))
    {
        ++start;
    }
}

template <class Iterator, class ElemType>
ElemType &FilterIterator<Iterator, ElemType>::operator*()
{
    return *start;
}

template <class Iterator, class ElemType>
FilterIterator<Iterator, ElemType>&
     FilterIterator<Iterator, ElemType>::operator++()
{

    ++start;
    ensureNextIsOK();
    return *this;
}

template <class Iterator, class ElemType>
bool FilterIterator<Iterator, ElemType>::operator==(const FilterIterator<Iterator, ElemType> &it) const
{
    return start == it.start && end == it.end;
}
template <class Iterator, class ElemType>
bool FilterIterator<Iterator, ElemType>::operator!=(const FilterIterator<Iterator, ElemType> &it) const
{
    return start != it.start || end != it.end;
}