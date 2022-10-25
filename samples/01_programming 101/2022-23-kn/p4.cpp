#include <iostream>
#include <cstring>

int myLen (char s[])
{
    int i = 0;
    while(s[i] != '\0') 
    {
        ++i;
    }

    return i;
}

int main()
{
    char s1[100] = "Hello",
         s2[100] = "World";

    
    //strcpy(s1,s2);
    strcat(s1,s2);
    std::cout << strlen(s2) << std::endl;



}