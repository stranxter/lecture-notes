#include <vector>
#include <iostream>
#include "../llist/llist.cpp"
#include <iterator>
#include <sstream>
#include <functional>

template <class I>
class MappedIterator
{

    public:

    using value_type = typename I::value_type;
    using maptype = std::function<value_type(const value_type&)>;

    MappedIterator(I _original, maptype f):original(_original), map(f)
    {}

    bool operator!=(const MappedIterator& other)
    {
        return original != other.original;
    }

    MappedIterator& operator++()
    {
        ++original;
        return *this;
    }

    value_type operator* ()
    {
        return map(*original);
    }
    
    private:
    I original;
    std::function<value_type(const value_type&)> map;

};


template <typename Iterator>
typename Iterator::value_type sum2(const Iterator& x, const Iterator& y)
{
    typename Iterator::value_type result = 0;
    for (Iterator it = x; 
         it != y; 
         ++it)
    {
        result += *it;
    }

    return result;
}

template <typename Container>
typename Container::value_type sum(Container &container)
{
    
    using value_type = typename Container::value_type;

    value_type result = 0;
    for (value_type element : container)
    {
        result += element;
    }

    return result;
}

int main()
{                                  
    std::vector<int> v = {1,2,3,4,5};
    std::cout << sum(v) << std::endl;
  
 
 
   using MappedVectorIt = MappedIterator<std::vector<int>::iterator>;

   std::function<int(const int&)> f = [](const int& x)->int{return x+1;};
   std::function<int(const int&)> f2 = [](const int& x)->int{return x*x;};

   std::cout << sum2(MappedVectorIt(v.begin(),f), 
                     MappedVectorIt(v.end(),f)) 
             << std::endl;


   std::cout << sum2(MappedVectorIt(v.begin(),f2), 
                     MappedVectorIt(v.end(),f)) 
             << std::endl;


    std::stringstream s ("2 2 3 3 ");
    std::istream_iterator<int> it(s);

   using MappedIstream = MappedIterator<std::istream_iterator<int>>;

    std::cout << sum2(MappedIstream(it,f2), 
                      MappedIstream(std::istream_iterator<int>(),f)) 
                << std::endl;


    std::istream_iterator<int> cinIt(std::cin);

    std::cout << sum2(MappedIstream(cinIt,f2), 
                      MappedIstream(std::istream_iterator<int>(),f)) 
                << std::endl;



/*
    LList<int> l;
    l.push(0); //7
    l.push(1); //6
    l.push(2); //5
    l.push(3); //4`
    l.push(4); //3
    l.push(5); //2 

    std::cout << sum<int,LList<int>>(l) << std::endl;
*/
    return 0;
}