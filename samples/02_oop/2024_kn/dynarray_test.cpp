
#include "dynarray.cpp"



DynArray<int> makeArray(unsigned int size)
{
    DynArray<int> a(size);
    for (unsigned int i = 0; i < size; i++)
    {
        a += i;
    }
    return a;
}

int main()
{

    DynArray<int> a(makeArray(5)),b,c;
    b = std::move(c);


    DynArray<int> newArrayCopyOfOtherArray(a);

    a += 10;
    a += 20;

    try
    {
        std::cout << a[-1] << std::endl;    
        std::cout << a[2] << std::endl;    
    }
    catch(array_exception_out_of_bounds &e)
    {
        std::cerr << e.msg << '\n';
    }
    catch(array_exception_out_of_memory &e)
    {
        std::cerr << e.msg << '\n';
    }
    

    b = a;
    std::cout << a;
    std::cout << b;

    a.arr[0] = 40;
    std::cout << a;
    std::cout << b;

    DynArray<double> *parray = new DynArray<double>[10];
    delete []parray;
    //DynArray<double> arrays[10];


    DynArray<int> d(std::move(a));

/*
    DynArray<int> a,b;
    DynArray<int> c(10);

    DynArray<double> *parray = new DynArray<double>[10];

    std::cout << *parray;

    
    std::cout << a;
    a += 1;
    a += 2;
    b += 3;
    b += 4;

    std::cout << a;

    a = b + b; //{1,2,3,4,3,4}

    std::cout << a;

    if (a == b)
    {
        std::cout << "Yes!";
    }
   */

    //a = b;
     
}