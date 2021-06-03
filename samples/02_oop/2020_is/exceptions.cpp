#include <stdexcept>
#include <iostream>
#include <vector>

std::vector<int> readArray(size_t n, std::istream &in)
{
    std::vector<int> result;

    for (int i = 0; i < n; ++i)
    {
        int x;
        in >> x;
        if (in)
            result.push_back(x);
        else 
            return result;
    }

    return result;
}

class A
{
    public:
    int x;
    A(int _x):x(_x) 
    {
        std::cout << "A(" << x << ")\n";
        if (x == 1)
        {
            throw "Boo!";
        }
    }
    ~A() 
    {
        std::cout << "~A(" << x << ")\n";
    }
};

void f ()
{
    std::cout << "Will thrown an exception now\n";
    throw A(100);
}


int main()
{
 // std::vector<int> arr = readArray(10, std::cin);

    try
    {
        A a0(0);
        //A a1(1);
        A a2(2);

        f();

        A a3(3);
        A a4(4);
    
    }
    catch(...)
    {
        std::cout << "Ooops!\n";
    } 

    std::cout << "Yayyy!\n";
    

} 