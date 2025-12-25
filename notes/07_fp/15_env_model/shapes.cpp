#include <iostream>
#include <functional>
#include <numbers>

struct Shape
{
    std::function<double()> area;
    std::function<double()> perimeter;
};

Shape createSquare(double a)
{
    return {[a]()->double{return a*a;},
            [a]()->double{return 4*a;}};
}

Shape createCircle(double r)
{
    return {[r]()->double{return std::numbers::pi*r*r;},
            [r]()->double{return 2*std::numbers::pi*r;}};
}

int main()
{
    Shape circle = createCircle(1),
          square = createSquare(1);
    std::cout << circle.area() << std::endl;
    std::cout << square.area() << std::endl;
}

