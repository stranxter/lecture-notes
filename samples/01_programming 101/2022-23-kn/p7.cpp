#include <iostream>
#include <cstring>

void strUpperCopy(char s1[], char s2[])
{
    int upperCount = 0;
    for(int i = 0; i < strlen(s2); ++i)
    {
        if (s2[i] >= 'A' && s2[i] <= 'Z')
        {
            s1[upperCount] = s2[i];
            ++upperCount;
        }
    }

    s2[upperCount] = 0;
}

int main()
{
    char str[255], str2[255];

    std::cin.getline(str,255);
    strUpperCopy(str2,str);
    std::cout << str2 << std::endl;

    //aBcDFGHi -> BDFGH

}