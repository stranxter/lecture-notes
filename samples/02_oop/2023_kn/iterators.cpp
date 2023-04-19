#include "vector/vector.cpp"
#include "list/llist.cpp"

#include <iostream>

template <typename Collection>
typename Collection::elem_type sum (const Collection& collection)
{
    typename Collection::elem_type acc = 0;
        
    for (typename Collection::elem_type e : collection)
    {
        acc += e;
    }

/*    for (Collection::iterator = collection.begin(); it != collection.end(); ++it)
    {
        acc += *it;
        *it = 2;
    }
*/
    return acc;
}

int main()
{
    int arr[] = {1,2,3};
   Vector<int> v(arr,3);

    LList<double> l;
    l.push(0.1);
    l.push(0.2);
    l.push(0.3);

    std::cout << sum(v) << std::endl;
    std::cout << sum(l) << std::endl;


    std::cout << sum<LList<double>>(l) << std::endl;

}