#include <iostream>
#include <iomanip>

template <typename T>
using BinOp = T(*)(T,T);

//агрегиране на елементите на масив чрез двуместна операция
//(събиране, умножеснир и др.)
template <typename T>
T reduce(T arr[], unsigned size, BinOp<T> op, T null_val)
{
    T result = null_val;
    for (int i = 0; i < size; ++i)
    {
        result = op(result,arr[i]);
    }

    return result;
}


int plus(int x, int y)
{
    return x+y;
}

int mult(int x, int y)
{
    return x*y;
}

BinOp<int> choice (char op)
{
    switch (op)
    {
        case '+':return plus;
        case '*':return mult;
        
        default: return plus;
    }
}

using Op = int(*)(int);


void map(int arr[], unsigned size, Op op)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i] = op(arr[i]);
    }
}

int print(int x)
{
    std::cout << x << " ";
    return x;

}
int main()
{

    std::cout << choice('+')(1,2) << std::endl;
    //::cout << pow(5)(2) << std::endl;

    int a[] = {1,412,3562,47,8,76234,1245,124,235,36,4};
    double da[] = {1.0,2.0,3.5,4.7,5};

    map(a,11,print);
    std::cout << std::endl;
    map(a,11,[](int x)->int{std::cout << x << " "; return x;});
    std::cout << std::endl;

    std::cout << reduce<int>(a,11,[](int x, int y)->int{return x+y;},0) << std::endl;
    std::cout << reduce<int>(a,11,[](int x, int y)->int{return x*y;},1) << std::endl;
    std::cout << reduce<int>(a,11,[](int x, int y)->int{return std::min(x,y);},a[0]) << std::endl;

    std::cout << reduce<double>(da,11,[](double x, double y)->double{return x+y;},0.0) << std::endl;


/*

    int(*p)(int,int);

    p = plus;

    std::cout << p(2,3) << std::endl;

    p = mult;

    std::cout << p(2,3) << std::endl;

    std::cout << std::hex << ((long*)plus)[0] << std::endl;
*/

}


