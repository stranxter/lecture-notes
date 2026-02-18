#include <cstring>
#include <iostream>

char* strconcat(const char *s1, const char *s2)
{
    char *result = new char[strlen(s1)+strlen(s2)+1];
    strcpy(result,s1);
    strcat(result,s2);
    return result;
}

int main() 
{
    char s1[] = "Hello ";
    char s2[] = "World!";

    char *cat = strconcat(s1,s2);

    std::cout << cat << std::endl;

    delete cat;
}
 