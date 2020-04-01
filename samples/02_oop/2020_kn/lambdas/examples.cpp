#include <iostream>
#include <string>
#include <functional>


template <typename ResT , typename ElemT > 
using reduceFn = ResT (*) (ResT, ElemT);

template <typename ResT,typename ElemT> 
ResT reduce (ElemT arr[],
             size_t arrsize ,
             std::function<int(int)> f, 
             ResT init)
{
    ResT result = init;
    for (int i = 0; i < arrsize; i++) 
       result = f (result, arr[i]);
    return result; 
}

int countHello (int current_counter, std::string s)
{
    if (s == "Hello")
    {
        ++current_counter;
    }
    return current_counter;
}

int add (int current, int x)
{
    return current+x;
}


struct increase 
{
    increase (int _inc ): inc (_inc){} 
    
    int operator () (int x)
    {
        return x+inc; 
    }
    int inc; 

};

int main ()
{

    increase i (10);
    
    i(10);
    i(1);
    std::cout << i(300);


    std::string strings[] = {"Hello", "World", "Hello", "ABC", "Hello"};

    std::cout << reduce (strings,5,countHello,0) << std::endl;


    int arr[] = {1,2,3,4,5};


    //std::cout << reduce (arr,5,add,0) << std::endl;
    std::cout << reduce<int,int> (arr,5,[](int current, int x)->int{return current+x;},0) << std::endl;

    std::cout << ([](int current, int x)->int{return current+x;}) (1,2) << std::endl;


}