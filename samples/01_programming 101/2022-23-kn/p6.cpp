#include <iostream>
#include <cstring>

int main()
{
    int lowerCount = 0,
        upperCount = 0;

    char str[255];

    std::cin.getline(str,255);

    for (int i = 0; i < 255 && str[i] != 0; ++i )
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            ++lowerCount;
        } 
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            ++upperCount;
        }
    }

    std::cout << "Lower = " << lowerCount << std::endl;
    std::cout << "Upper = " << upperCount << std::endl;
}