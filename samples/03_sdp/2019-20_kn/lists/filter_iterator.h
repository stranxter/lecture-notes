#ifndef __FILTER_ITERATOR
#define __FILTER_ITERATOR

template <class Iterator, class ElemType>
class FilterIterator
{
    public:
        FilterIterator(const Iterator &_start,
                       const Iterator &_end,
                       bool (*_pred)(const ElemType&) );

        ElemType &operator*();
        FilterIterator<Iterator, ElemType> & operator ++();
        bool operator==(const FilterIterator<Iterator, ElemType> &) const;
        bool operator!=(const FilterIterator<Iterator, ElemType> &) const;
    private:
        Iterator start;
        Iterator end;
        bool (*pred)(const ElemType &);

        void ensureNextIsOK ();
};

#endif