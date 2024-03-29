#include <iostream>

enum Coutries {bulgaria=1, serbia=2, nmacenodia=4, greece=8, romania=16, turkey=32};

struct Student
{
    int fn;
    unsigned char family;
};

int main()
{

    Student kalin {42860, serbia | bulgaria| turkey};

    //00000010
    //00000001
    //00010000

    //00010011

    if(kalin.family & nmacenodia != 0)
    {
    
    }

    std::cout << (int)nmacenodia << std::endl;

    char c = 5; //00000101
                //00000100 -> mask   //00000100

    char mask = 1 << 2;

               //00000101
               //00000100 -> mask  
               //00000100

               //00000001
               //00000100 -> mask  
               //00000000

    
    if((c & mask) != 0)
    {
        std::cout << "Yes!";
    }

             //00000101
             //   |
             //00010000
             //00010101

    c = c | mask;

    mask = 1 << 4;

}