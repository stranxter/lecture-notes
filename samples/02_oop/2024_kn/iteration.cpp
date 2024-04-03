#include <iostream>

#include "list.cpp"
#include "dynarray.cpp"


template <typename Container>
bool find(const typename Container::value_type& x, Container &container)
{
    for(int i = 0; i < container.size(); ++i)
    {
        if(container[i] == x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    List<int> l;
    l.push(10);l.push(20);l.push(30);

    std::cout << find(20,l) << std::endl;
    std::cout << find(40,l) << std::endl;

    DynArray<int> a;
    a += 10; a += 20; a += 30;
    std::cout << find(20,a) << std::endl;
    std::cout << find(40,a) << std::endl;
}


