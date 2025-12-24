#include <iostream>
#include <functional>

struct Counter
{
  std::function<int(int)> inc;
  std::function<int()> get;
};
std::function<Counter()> counter(int init)
{
  return [count = init]() mutable -> Counter 
        {
           return { [&count](int step) -> int { count += step; return count; },
                    [&count]() -> int { return count; } };
  };
}
int main()
{
    std::function<Counter()> c1 = counter(0),
                             c2 = counter(100);

    c1().inc(1);c1().inc(1);c1().inc(1);c1().inc(1);
    std::cout<<c1().get()<<std::endl;
    c2().inc(5);c2().inc(5);c2().inc(5);
    std::cout<<c2().get()<<std::endl;
}