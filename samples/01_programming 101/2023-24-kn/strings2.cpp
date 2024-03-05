#include <iostream>
#include <cstring>

int myStrlen(char s[])
{
    int count = 0;
    while(s[count]!=0)    //'\0' == 0
    {
        ++count;
    }

    return count;
}

void myStrcpy(char s1[], char s2[])
{
    int count = 0;
    while(s2[count]!=0)
    {
        s1[count]=s2[count];
        ++count;
    }
    s1[count]=0;
}

void myStrcat(char s1[], char s2[])
{
    int endOfS1 = myStrlen(s1);
    int count = 0;
    while(s2[count]!=0)
    {
        s1[count+endOfS1]=s2[count];
        ++count;
    }
    s1[count+endOfS1]=0;   
}

void toLowerCase(char s[])
{
    int count = 0;
    while(s[count] != 0)
    {
        if(s[count] >= 'A' && s[count] <= 'Z')
        {
            s[count] -= ('A' - 'a');
        }
        ++count;
    }
}

void myIntCpy(int a, int b)
{
    a = b;
}

bool isPalindrom(char s[])
{
    int size = myStrlen(s);
    int i = 0;
    for(int i = 0; i < size/2; ++i)
    {
        if(s[i]!=s[size-i-1])
        {
            return false;
        }
    }
    
    return true;
}

int main()
{


    int x = 5, y = 6;
    std::cout << "x=" << x << std::endl
              << "y=" << y << std::endl;

    myIntCpy(x,y);
    std::cout << "x=" << x << std::endl
              << "y=" << y << std::endl;

    char s1[255] = "Hello world!",
         s2[255] = "Have a nice day!";

    //s1 > s1

    std::cout << "myStrlen=" << myStrlen(s1) << std::endl
              << "strlen=" << strlen(s1) << std::endl;

    std::cout << strcmp(s1,s2) << std::endl;

    std::cout << "s1 =" 
              << s1
              << std::endl
              << "s2 ="
              << s2
              << std::endl;
    strcat(s1,s2);
    std::cout << "s1 =" 
              << s1
              << std::endl
              << "s2 ="
              << s2
              << std::endl;
    //strcpy(s1,s2); // s1 = s2
    myStrcpy(s1,s2);
    std::cout << "s1 =" 
              << s1
              << std::endl
              << "s2 ="
              << s2
              << std::endl;
    std::cout << "s1 =" 
              << (long)s1
              << std::endl
              << "s2 ="
              << (long)s2
              << std::endl;

    toLowerCase(s2);
    std::cout << "TLC(s2) =" 
              << s2
              << std::endl;

    std::cout << strlen(s1) << std::endl;

    std::cout << "pal=" << isPalindrom("abcba") << std::endl;
}
