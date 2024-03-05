#include <iostream>
#include <cmath>
int g()
{
    std::cout << "G / 4" << std::endl;
    return 10;
}
int f()
{
    std::cout << "F / 9" << std::endl;
    std::cout << (g() > 30) << std::endl;
    std::cout << "F / 11" << std::endl;
    return 20;
}
void sayHello()
{
    std::cout << "Hello!" << std::endl;
}
bool isBiggerThan30(int x)
{
    /* Версия 1:
    if(x > 30)
    {
        return true;
    } else {
        return false;
    }
    */

    /* Версия 2:
    if(x > 30)
    {
        return true;
    }
    return false;
    */
   return x > 30;
    
}
bool isBetween30and40(int x)
{
    /*
    if(x >= 30)
    {
        if(x <= 40)
        {
            return true;
        } else {
            return false;
        }         
    } else {
        return false;
    }*/
    
    return x >= 30 && x <= 40;
}

int main()
{
    sayHello();
    std::cout << "MAIN / 16" << std::endl;
    f();
    sayHello();
    std::cout << "MAIN / 18" << std::endl;
    sayHello();
    std::cout << isBiggerThan30(30) << std::endl
              << isBiggerThan30(31) << std::endl;
    return 0;
}