#include "dynarray.cpp"
#include "llist.cpp"
#include "range.h"

#include <iostream>
#include <fstream>
#include <iterator>


template <typename CollectionType>
bool find(const typename CollectionType::value_type& x, CollectionType& collection)
{

    /*
    for(CollectionType::Iterator it = collection.begin(); it != collection.end(); ++it)
    {
        if(*it == x)
        {
            return true;
        }
    }
    */

    for (auto element : collection)
    {
        if(element == x)
        {
            return true;
        }
    }

    return false;

}

struct Point
{
    int x;
    int y;
};

std::ostream& operator<<(std::ostream &out, const Point &p)
{
    out << p.x << " " << p.y << std::endl;
    return out;
}

std::istream& operator>>(std::istream &in, Point &p)
{
    in >> p.x >> p.y;

    return in;
}


struct PointFile
{
    std::istream &f;
    std::istream_iterator<Point> begin()
    {
        return std::istream_iterator<Point>(f);
    }
    std::istream_iterator<Point> end()
    {
        return std::istream_iterator<Point>();
    }

};

int main()
{
    LList<int> l;
    l.push(10); l.push(20); l.push(30); l.push(40);


    DynArray<double> a;
    a.push_back(10.1); a.push_back(20.1); a.push_back(30.1); a.push_back(40.1);


    std::cout << find(10,l) << std::endl;
    std::cout << find(15,l) << std::endl;

    std::cout << find(10.1,a) << std::endl;
    std::cout << find(15.1,a) << std::endl;


    std::ifstream data ("points.dat");

    std::istream_iterator<Point> end;

    for(std::istream_iterator<Point> it (data); it != end; ++it)
    {
        std::cout << *it;
    }
    std::cout << std::endl;

    data.clear();
    data.seekg(0);

    for(Point p : PointFile{data})
    {
        std::cout << p;
    }


    for(int x : IntRange{0,100,[](int x)->bool{return x%2 == 0;}})
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    for(int x : IntRange{100,200,[](int x)->bool{return x%5 == 0;}})
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;


    for(int x : IntRange{100,200,[](int x)->bool{return true;}})
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

}