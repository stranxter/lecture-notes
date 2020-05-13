#include <vector>
#include <iostream>
#include "classes/vector.cpp"

std::vector<int> inputArray(size_t n, std::istream &in)
{

    std::vector<int> result;
    for (size_t i = 0; i < n; ++i)
    {
        int x;
        in >> x;
        if (in)
        {
            result.push_back(x);
        } else {
            return result;
        }      
    }
    return result;

}

class A
{   
    public:
    A(int _x):x(_x) 
    {
        std::cout << "A("<< x <<")\n";
        if (x == 1)
            throw "Boo!";
    }
    ~A() 
    {
        std::cout << "~A("<<x<<")\n";
    }
    int x;

};


void print5 (const Vector<int>& v)
{   
    try
    {

        A a0(0);
        A a1(1);
        A a2(2);

        std::cout << "5th element = " << v[4] << std::endl;
        
        A a3(3);
        
        std::cout << "Thank you, everything was fine!";
    } catch (std::out_of_range ex)
    {
        std::cerr << "Your index was wrong:" << ex.what() << std::endl;
    } catch (...)
    {
        std::cerr << "Something else went wrong!\n";
    } 

}

int main()
{

 /*   std::vector<int> result = inputArray(10, std::cin);
    if (result.size() != 10)
    {
        std::cout << "Sorry, user, try again:";
    }

*/

    Vector<int> v;
    v.to_end(10);
    v.to_end(20);
    v.to_end(30);
    v.to_end(30);

    print5(v);
}