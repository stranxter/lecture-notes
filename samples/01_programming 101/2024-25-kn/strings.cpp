#include <iostream>
#include <cstring>


void toUpper(char s[100])
{
    int n = 0;
    while(s[n] != 0)
    {
        if(s[n]>='a' && s[n]<='z')
        {
            s[n] -= 'a'-'A';
        }
        ++n;
    }
}

int main()
{

    //char s[100] = {'H','E','L','L','O','0','K','A','L','I','N',0};
    char s[100] = "Hello world!!!";
    char s2[100] = "Good bye!!!";

    //s2 = s;
    strcpy(s2,s); //s2=s
    if (strcmp(s2,s) > 0)
    {
        //...
    }

    std::cout << s << std::endl;
    std::cout << (int)'1' <<std::endl;

    /*
    std::cout << "Моля, въведете символен низ=";
    std::cin >> s;

    std::cout << "Вие въведохте=" << s << std::endl;

    int a, b, c;
    std::cin >> a;
    std::cin >> b >> c;

    std::cout << "a=" << a << ", b=" << b << ",c = " << c << std::endl;
    */


    std::cout << s[0] << std::endl;

    toUpper(s);
    std::cout << s << std::endl;

    return 0;
}