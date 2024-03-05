#include <iostream>



struct MyStruct
{
    int x;
    int arr[5];
};


void f(int arr[5])
{
    arr[0] = 10;
}

void g(MyStruct s)
{
    s.arr[0] = 10;
}

int main()
{
    int test[5] = {0};
    int test2[5] = {0};
    f(test);
    std::cout << test[0] << std::endl;   


    MyStruct s,s2;
    s.arr[0] = 0;

    s2 = s;

    f(s.arr);
    std::cout << s.arr[0] << std::endl;   

    s.arr[0] = 0;
    g(s);
    std::cout << s.arr[0] << std::endl;   
}