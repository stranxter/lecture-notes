#include <iostream>
#include <iterator>
#include <fstream>

#include "list.cpp"
#include "dynarray.cpp"
#include "irange.h"

/*
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
*/

template <typename Container>
bool find(const typename Container::value_type& x, 
          Container &container)
{
    /*
    for(typename Container::Iterator it = container.begin(); 
        it != container.end(); ++it)
    {
        if(*it == x)
        {
            return true;
        };
    }
    */

    for(int current : container)
    {
        if(current == x)
        {
            return true;
        };

    }
    return false;
}


template <typename Container>
void print(Container &container)
{

    for(typename Container::value_type current : container)
    {

        std::cout << current << " ";

    }
    std::cout << std::endl;
}

struct Point
{
    int x;
    int y;
};


std::istream& operator>>(std::istream& in, Point &p)
{
    in >> p.x;
    in >> p.y;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Point &p)
{
    out << "{" << p.x << "," << p.y << "}";

    return out;
}

template <typename Iterator>
struct Series
{
    Iterator& _begin, _end;
    Iterator& begin(){return _begin;};
    Iterator& end(){return _end;};
};

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

    print(l);
    print(a);


    for(int i : IRange(100,200,[](int x)->bool{return true;}))
    {
        std::cout << i << " ";
    }

    std::cout << "========\n";

    for(int i : IRange(100,200,[](int x)->bool{return x%2 == 0;}))
    {
        std::cout << i << " ";
    }
    std::cout << "========\n";

    for(int i : IRange(100,200,[](int x)->bool{return x%5 == 0;}))
    {
        std::cout << i << " ";
    }
    std::cout << "========\n";


    std::ifstream in("data.dat");

    
    for(std::istream_iterator<int> it(in); it != std::istream_iterator<int>(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "========\n";


    std::ifstream in2("data2.dat");

    for(std::istream_iterator<double> it(in2); it != std::istream_iterator<double>(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "========\n";


    std::ifstream in3("data3.txt");

    for(std::istream_iterator<Point> it(in3); it != std::istream_iterator<Point>(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "========\n";

    std::istream_iterator<Point> start(in3);
    std::istream_iterator<Point> end;
    Series<std::istream_iterator<Point>> myFile{start,end};

    for (Point p : myFile)
    {
        std::cout << p;
    }

}


