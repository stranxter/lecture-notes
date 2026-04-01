#include <iostream>

#include "llist.cpp"
#include "dynarrayc.cpp"

int testlist()
{
    LList<int> l;

    l.push(10).push(20).push(30).push(40).push(50).push(60);

    l.insertAfter(100,2);

    l[1] = 1000;

    std::cout << l << std::endl;

    LList<int> l2(l);

    std::cout << l2 << std::endl;

    return 0;

}

std::function<double(double)> maxf(std::function<double(double)>f, 
                         std::function<double(double)>g)
{
    return [f,g](double x)->double {return std::max(f(x),g(x)); };
}

std::function<double(double)> maxall(DynArray<std::function<double(double)>> functions)
{
    std::function<double(double)> result = functions[0];
    for(int i = 1; i < functions.lenght(); ++i)
    {
        result = maxf(functions[i],result);
    }

    return result;

}


int testdynarray()
{
    DynArray<double> arr1 = 20, arr2;

    arr1.insert(1).insert(2).insert(3).insert(4).insert(5);

    arr2.insert(0);

    arr1.print();
    arr2.print();

    arr2 = arr1;

    arr2.insert(6);

    arr2.print();
    arr1.print();

    DynArray<double> *p = new DynArray<double>[10];
    delete []p;

    DynArray<double> arr3(5);

    //arr3 = arr2 = arr1;
    //arr3.operator=(arr2.operator=(arr1));


    std::ofstream f("data.txt");

    //arr3.input().print();

    //std::cout << arr1;

    std::cout << arr1[10];

    arr1[10] = 7;


    DynArray<std::function<double(double)>> fs;

    fs.insert([](double x)->double{return x*x;});
    fs.insert([](double x)->double{return x*x*x;});
    fs.insert([](double x)->double{return x;});

    std::cout << fs[1](10) << std::endl;

    std::cout << maxall(fs)(10) << " " << maxall(fs)(0.5) << std::endl;

    std::function<double(double)> maxf2 = fs.reduce(maxf,fs[0]);

    std::cout << maxf2(10) << " " << maxf2(0.5) << std::endl;

    return 0;
}

template <typename T>
void myprint(const T& l)
{
    for(int i = 0; i < l.size(); ++i)
    {
        std::cout << l[i] << " ";
    }
}

template <typename C>
void print(const C& c)
{
    for (typename C::value_type x : c)
    {
        std::cout << x << " ";
    }
}

void testListIterator()
{
    LList<int> l;
    l.push(10).push(20).push(30).push(40);

    /*
    ListIterator<int> il = l.begin();

    while (il != l.end())
    {
        std::cout << *il;
        ++il;
    }
    */

    for (int x : l)
    {
        std::cout << x << " ";
    }
}

void testDAIterator()
{
    DynArray<int> a;
    a.insert(10).insert(20).insert(30).insert(40);

    /*
    ListIterator<int> il = l.begin();

    while (il != l.end())
    {
        std::cout << *il;
        ++il;
    }
    */

    for (int x : a)
    {
        std::cout << x << " ";
    }
}

void testprinting()
{
    DynArray<int> a;
    a.insert(10).insert(20).insert(30).insert(40);
    LList<int> l;
    l.push(10).push(20).push(30).push(40);

    print(a);
    print(l);

}


int main()
{
    testlist(); 
    testdynarray();

    testListIterator();
    testDAIterator();

    return 0;
}