#include "../classes/vector.cpp"
#include "../lists/llist.cpp"
#include <iostream>

template <class Container>
typename Container::value_type sum(Container v)
{
    typename Container::value_type sum = 0;
    for (typename Container::value_type element : v)
    {
        sum += element;
    }
    return sum;

}

int main()
{
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << sum(v) << std::endl;

    //    for (int i = 0; i < v.length(); ++i)
    for (int x : v)//for (Vector<int>::Iterator it = v.begin(); it != v.end() ; ++it);
    {

        //x = *it; 
        std::cout << x << std::endl;
    }


    LList<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    for (int x : l)//for (LList<int>::Iterator it = v.begin(); it != v.end() ; ++it);
    {

        //x = *it; 
        std::cout << x << std::endl;
    }

    std::cout << sum(l) << std::endl;

}


