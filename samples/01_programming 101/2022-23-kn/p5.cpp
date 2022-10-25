#include <iostream>
#include <cstring>



void f (int x)
{
    x = 10;
}

void upperCase(char str[])
{
    int diff = 'a' - 'A';
    int len = strlen(str);

    for (int i =0; i < len; ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= diff;
        }
    }
}

int main()
{
    /*    
    int x = 0;
    f(x);
    std::cout << x << std::endl;
    */
    
    char str[255];

    std::cin.getline(str,255);

    upperCase(str);

    std::cout << str << std::endl;
}