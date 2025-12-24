#include <iostream>
#include <functional>

std::function<int(int)> counter(int init)
{
    int count = init;
    return [count](int step) mutable ->int{count+=step; return count;};
}

int main()
{
    std::function<int(int)> c1 = counter(0),
                            c2 = counter(100);

    c1(1);c1(1);c1(1);
    std::cout<<c1(1)<<std::endl;
    c2(5);c2(5);
    std::cout<<c2(5)<<std::endl;
}