#include <iostream>
#include <vector>
#include <string>
#include "vector/vector.cpp"

int toInt (const char *s)
{  
    //1234q
    int result = 0;
    while (*s != 0)
    {
        char digit = s[0]; //0...9
        digit = (char)7.8;
        if (digit < '0' || digit > '9')
            return result;
        result += result*10 + (digit-'0');
    
        ++s;
    }

    return result;

}

class KalinError
{
    public:
    enum ErrorType {bad_mood_error, not_enough_cofee_error, some_other_error};
    ErrorType e;

};

template <class T>
std::vector<T> inputVector()
{

    std::vector<T> result;
    
    std::cout << "Please enter number of elements:";
    int n;
    std::cin >> n;
    if (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore();
        throw KalinError{KalinError::ErrorType::not_enough_cofee_error};
    }

    for (int i = 0; i < n; ++i)
    {
        T x = -7;
        std::cout << "Please enter element #" << i << ":";
        std::cin >> x;
        if (std::cin)
        {
            result.push_back(x);
        } else
        {   std::cin.clear();
            std::cin.ignore();
            throw "Icorrect element input!";
        }
                    
    } 

    return result;
}

class A
{
    public:
    A(int _x):x(_x)
    {
        std::cout << "Creating " << x << std::endl;
    };
    ~A()
    {
        std::cout << "Destroyng " << x << std::endl;
    };

    int x;
};


void programLogic()
{

    std::vector<int> v;

    while (v.size() == 0)
    {

        try
        {
            A a(1);
            A b(2);
            A c(3);
            v = inputVector<int>();
            std::cout << "Thank you for entering the data!\n";
            A d(4);
        } 
        catch (const char* s)
        {
            std::cout << "OOOPs, something went wrong, sorry! " 
                      << "Error message:" << s << std::endl;
        }

        std::cout << "Resulting vector size = " << v.size() << std::endl;
        
    }
         

    for (int x: v)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

}


int main()
{
    try
    {
        programLogic();
    }
    catch (const KalinError& e)
    {
        if (e.e == KalinError::ErrorType::not_enough_cofee_error)
        {
            std::cout << "Drink cofee!\n";
        }

    }   
    catch (int x)
    {
        std::cout << "Int exception\n";
    }

    //...v...
}