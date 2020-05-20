#include "../lists/llist.cpp"
#include "../classes/vector.cpp"
#include <iostream>

template <class Container>
typename Container::value_type sum(Container &container)
{
    typename Container::value_type sum = 0;

    for (typename Container::value_type x: container)
    {
        sum += x;
    }

    return sum;
}


int main()
{
    Vector<int> v;
    v.to_end(10);
    v.to_end(20);
    v.to_end(30);
   
    std::cout << sum(v) << std::endl;
   
    LList<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    
    std::cout << sum(l) << std::endl;

    int a[] = {1,2,3,4,5};


    return 0;
}