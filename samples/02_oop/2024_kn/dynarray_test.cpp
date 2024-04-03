
#include "dynarray.cpp"

int main()
{

    DynArray<int> a,b,c;
    DynArray<int> newArrayCopyOfOtherArray(a);

    a += 10;
    a += 20;

    b = a;
    std::cout << a;
    std::cout << b;

    a.arr[0] = 40;
    std::cout << a;
    std::cout << b;

    DynArray<double> *parray = new DynArray<double>[10];
    delete []parray;
    //DynArray<double> arrays[10];

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