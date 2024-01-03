#include <iostream>

char* concat(char* s1, char*s2)
{
    char* result = new char[strlen(s1) + strlen(s2) + 1];
    for (int i = 0; i < strlen(s1); ++i)
    {
        result[i] = s1[i];
    }

    for (int i = 0; i < strlen(s2); ++i)
    {
        result[i+strlen(s1)] = s2[i];
    }

    result[strlen(s1)+strlen(s2)] = 0;

    return result;
}

int main()
{
    char s1[] = "Hello ";
    char s2[] = "world";

    char *s3 = concat(s1,s2);
    std::cout << s3;
    delete s3;


}