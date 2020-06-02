#include <iostream>
#include <vector>
#include <functional>

template <class Iterator>
class Range
{
    public:

    Iterator begin()
    {
        return _begin;
    }
    Iterator end()
    {
        return _end;
    }

    Iterator _begin;
    Iterator _end;
};

template <class Iterator>
class MappedIterator
{
    public:

    Iterator original; //std::vector<int>::iterator
    using value_type = typename Iterator::value_type;
    std::function<value_type(value_type)> op;

    bool operator != (const MappedIterator& other)
    {
        return original != other.original;
    }

    MappedIterator& operator++()
    {
        ++original;
        return *this;
    }

    value_type operator *()
    {
        return op(*original);
    }

};

template <class Iterator>
class FilteredIterator
{
    public:

    Iterator original, original_end; 
    using value_type = typename Iterator::value_type;
    std::function<bool(value_type)> pred;

    FilteredIterator(Iterator _original,
                     Iterator _original_end,
                     std::function<bool(value_type)> _pred)
                        :original(_original), original_end(_original_end), pred(_pred)
    {
        ensurePredicate();
    }

    bool operator != (const FilteredIterator& other)
    {
        return original != other.original;
    }

    FilteredIterator& operator++()
    { 
        ++original;
        ensurePredicate();

        return *this;
    }

    value_type operator *()
    {
        return *original;
    }

    private:
    void ensurePredicate()
    {
        while (original != original_end && !pred(*original))
        {
            original++;
        }    
    }

};

template <class Val>
class MapAdaptor
{
    public:
    std::function<Val(Val)> op;
    template<class Iterator>
    using adapted_it = MappedIterator<Iterator>;

    template<class Iterator>
    Range<adapted_it<Iterator>> adapt(Range<Iterator> range)
    {

        return Range<adapted_it<Iterator>> {adapted_it<Iterator>{range.begin(),op},
                                            adapted_it<Iterator>{range.end(),op}};
    }
};

template <class Val>
class FilterAdaptor
{
    public:
    std::function<bool(Val)> pred;
    template <class Iterator>
    using adapted_it = FilteredIterator<Iterator>;

    template<class Iterator>
    Range<adapted_it<Iterator>> adapt(Range<Iterator> range)
    {

        return Range<adapted_it<Iterator>> {adapted_it<Iterator>{range.begin(),range.end(),pred},
                                            adapted_it<Iterator>{range.end(),range.end(),pred}};

    }

};

template <class Iterator, class Adaptor>
Range<typename Adaptor::template adapted_it<Iterator>> 
     operator |(Range<Iterator> range, 
                Adaptor adaptor)
{
    return adaptor.adapt(range);
}

int main()
{
    std::vector<int> vect = {1,1,1,2,3,4,5,5,5,5,5,5,6,7,8,8,9,10,7,7,7};

    Range<std::vector<int>::iterator> range = {vect.begin(), vect.end()};

    std::function<int(int)> inc = [](int x)->int{return x+1;};
    std::function<int(int)> square = [](int x)->int{return x*x;};
    std::function<bool(int)> even = [](int x)->bool{return x%2==0;};
    
    std::cout << std::endl;
    
    MapAdaptor<int> mapinc{inc};
    MapAdaptor<int> mapsquare{square};
    FilterAdaptor<int> filtereven{even};

    for (int x: range | filtereven | mapsquare | mapinc )
    {
        std::cout << x << std::endl;
    }

    return 0;
}