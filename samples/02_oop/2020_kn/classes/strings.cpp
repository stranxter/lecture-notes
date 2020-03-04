#include <iostream>
#include <cstring>
#include <cassert>

class String
{
    public:
    char str[255];

    void init (const char *value)
    {
        strcpy (this->str,value);
    }
    //String concat (String other)
    String operator + (String other)
    {
        assert (strlen(this->str) + 
                       strlen(other.str) <= 255);
        String result;
        result.init (this->str);
        strcat (result.str,other.str);
        return result;
    }  

    //if (i1 < i2) {....}
    //bool comparelt (String other)
    bool operator < (String other)
    {
        return strcmp (this->str, other.str) < 0;
    }

    bool equal (String other)
    {
        return strcmp (this->str, other.str) == 0;
    }

    //  if (s1.operator == (s2))
    // if (s1 == s2)
    bool operator == (String other)
    {
        return strcmp (this->str, other.str) == 0;
    }

    //s1 = s2
    void assign (String other)
    {
        strcpy (this->str,other.str);
    }

    size_t length ()
    {  
        return strlen (this->str);
    }

    void print ()
    {
        std::cout << "\"" << this->str << "\"" << std::endl;
    }

};

int main ()
{
    String s1,s2;

    s1.init ("Hello");
    s2.init (" world!");

    String s3;

    //s3 = s1.concat (s2);
    s3 = s1 + s2;

    s3.print ();

    //s3.assign (s1.concat (s2));

    //if (s1.equal(s2))
    if (s1 == s2)
    {
        std::cout << "The strings are equal!";
    }

    if (s1 < s2)
    {
        std::cout << "s1 < s2";
    }


};