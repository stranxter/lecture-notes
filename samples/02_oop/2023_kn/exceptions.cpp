#include <vector>
#include <iostream>
#include <string>


class IncorrentCountException
{
    public:
    int x;
};

class IncorrentInputException
{
    public:
    size_t x;
};


std::vector<int> makeSomeVector()
{
    
    std::vector<int> result;
    int x;
    
    size_t count = 0;
    std::cin >> count;

    if(!std::cin)
    {
        throw IncorrentCountException{0};
    }

    for (size_t i = 0; i < count; ++i)
    {
        std::cin >> x;
        if (!std::cin)
        {
            throw IncorrentInputException{i};
        }
        result.push_back(x);
    }

    return result;
}

class A
{
    public:
    std::string s;
    ~A(){std::cout << "Destructing " << s << "\n";}
};

void h()
{
    A a{"object created in H"};
    throw "Oops!";
    std::cout << "H is still alive!\n";
}   

void g()
{
    A a{"Object created in G"};
    h();
    std::cout << "G is still alive!\n";
}

void f()
{
    A a{"object creates in F"};
    g();
    std::cout << "F is still alive!\n";
}

int main()
{

    std::vector<int> v;

    try
    {

        v = makeSomeVector();
        std::cout << "Still alive!\n";
        f();

    }
    catch(const IncorrentCountException& e)
    {
        std::cerr << "Logic for handling type 1 expections";
    }
    catch(const IncorrentInputException& e)
    {
        std::cerr << "Error in element " << e.x << "\n";
    }
    catch(const char* s)
    {
        std::cerr << s;
    }
    

    for(int x:v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}