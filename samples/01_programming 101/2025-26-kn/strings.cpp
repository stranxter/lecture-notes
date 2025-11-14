#include <iostream>


int countletters(const char *s)
{
    //....колко малки латински букви има в низа s
    int i = 0, let = 0;
    while (s[i] != 0)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            ++let;
        }
        ++i;
    }

    return let;
}


int main()
{
    char s[100]; //char *s

    std::cout << "Моля, въведете символен низ:";
    std::cin.getline(s,99);
   
    std::cout << "Брой букви в s=" << countletters(s) << std::endl;


    std::cout << s[1] << std::endl;
    std::cout << *(s+1) << std::endl;

    std::cout << (long)s << std::endl;
    std::cout << (long)(s+1) << std::endl;

    int ia[] = {1,2,3};

    std::cout << (long)ia << std::endl;
    std::cout << (long)(ia+1) << std::endl; //*(ia+1) <=> ia[1]

}