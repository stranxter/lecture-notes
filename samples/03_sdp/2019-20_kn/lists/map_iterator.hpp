#ifndef __MAP_ITERATOR
#define __MAP_ITERATOR

template <class Iterator, class Element>
class MapIterator
{
    public:
    MapIterator (const Iterator &_start,
                 const Iterator &_end,
                 Element (*_f)(const Element &)):start(_start),end(_end), f(_f){}

    Element operator*()
    { return f (*start); }
    MapIterator<Iterator, Element>& operator++()
    { ++start; return *this; }
    bool operator==(const MapIterator<Iterator, Element> &it) const
    { return start == it.start && end == it.end; }
    bool operator!=(const MapIterator<Iterator, Element> &it) const
    { return start != it.start || end != it.end; }

    private:
    Iterator start;
    Iterator end;
    Element (*f)(const Element &);
};

#endif