#include <vector>
#include <iostream>
#include <functional>
#include <stdexcept>

template <class I>
class Range
{
    public: 

    I begin()
    {
        return _begin;
    }

    I end()
    {
        return _end;
    }

    I _begin;
    I _end;
};

template <class I>
class MappedIterator
{
    public:

    I original;
    using value_type = typename I::value_type;

    std::function<value_type(value_type)> op;

    MappedIterator& operator++()
    {
        ++original;
        return *this;
    }

    bool operator!=(const MappedIterator& other)
    {
        return original != other.original;
    }

    value_type operator*()
    {
        return op(*original);
    }

};

template <class I>
class FilteredIterator
{
    public:

    I original, original_end;
    using value_type = typename I::value_type;

    FilteredIterator(const I& _original,
                     const I& _original_end,
                     std::function<bool(value_type)> _pred):original(_original), original_end(_original_end),pred(_pred)
                     {
                         ensurePredicate();
                     }

    std::function<bool(value_type)> pred;

    FilteredIterator& operator++()
    {
        if (original == original_end)
        {
            throw std::out_of_range("End of range reached!");
        }
     
        ++original;
        ensurePredicate();

        return *this;
    }

    bool operator!=(const FilteredIterator& other)
    {
        return original != other.original;
    }

    value_type operator*()
    {
        if (original == original_end)
        {
            throw std::out_of_range("Reading end of range!");
        }
        return *original;
    }

    private:
    void ensurePredicate()
    {
        while (original != original_end && !pred(*original))
        {
            ++original;
        }                              
    }

};

template <class value_type>
class MapAdaptor
{
    public:
    std::function<value_type(value_type)> op;

    template<class It>
    using adapted_it = MappedIterator<It>;
    
    template<class It>
    Range<MappedIterator<It>> adapt (Range<It> range)
    {
        
        Range<adapted_it<It>> newrange = {adapted_it<It>({range.begin(),op}),
                                      adapted_it<It>({range.end(),op})}; 
        return newrange;
    }
};

template <class value_type>
class FilterAdaptor
{
    public:
    std::function<bool(value_type)> pred;

    template<class It>
    using adapted_it = FilteredIterator<It>;

    template<class It>
    Range<FilteredIterator<It>> adapt (Range<It> range)
    {
        Range<adapted_it<It>> newrange = {adapted_it<It>({range.begin(),range.end(),pred}),
                                        adapted_it<It>({range.end(),range.end(),pred})}; 
        return newrange;
    }
};


template<class It, class Adaptor>
Range<typename Adaptor::template adapted_it<It>> operator | (Range<It> range, Adaptor adaptor)
{
    return adaptor.adapt(range);
}

int main()
{

    std::vector<int> v = {1,1,1,2,3,5,7,9,11,4,5,6,7,8,9,10,11,11,11,11,11,11,11};

    Range<std::vector<int>::iterator> range = {v.begin(),v.end()};

    std::function<int(int)> sq = [](int x)->int{return x*x;};
    std::function<int(int)> plusone = [](int x)->int{return x+1;};
    std::function<bool(int)> even = [](int x)->bool{return x%2 == 0;};

    MapAdaptor<int> makesquare{sq};
    MapAdaptor<int> inc{plusone};

    FilterAdaptor<int> filtereven{even};

    //??? makesquare{sq};

    //range | makesquare // adapt_map(range,sq)

    for (int x : range | filtereven | makesquare | inc)
    {
        std::cout << x << std::endl;
    }

}