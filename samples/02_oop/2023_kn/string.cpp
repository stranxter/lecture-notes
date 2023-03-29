#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <iostream>
#include <cstring>

class String
{

    private:

    char *str;
    void copy(const char *other)
    {
        this->str = new char [strlen(other)+1];
        strcpy(str,other);

    }

    public:

    String()
    {
        str = new char;
        *str  = 0;
    }

    String(const char *s)
    {
        str = new char [strlen(s)+1];
        strcpy(str,s);
    }

    String& operator+=(const String& other)
    {
        *this = *this + other;

        return *this;
    }


    String operator+(const String& other) const
    {

        char *r = new char[strlen(this->str)+strlen(other.str)+1];
        
        strcpy(r,this->str);
        strcat(r,other.str);

        String result;
        delete result.str;
        result.str = r;

        return result;
    }

    //d = a * 4;
    String operator*(unsigned int n) 
    {
        String result(this->str);

        while (n > 1)
        {
            result = result + *this;
            --n;
        }

        return result;
    }

    bool operator==(const String& other) const
    {
        return strcmp(this->str,other.str)==0;
    }

    bool operator!=(const String &other) const
    {
        return !(*this == other);
    }
    String& operator=(const String &other) 
    {
        //s3 = (s1.operator=(s2));

        //this->str     |     other.str
        if (this != &other)
        {
            delete this->str;
            copy(other.str);
        }

        return *this;
    }

    String(String &other)
    {
        copy(other.str);

    }

    ~String()
    {
        delete []str;
    }

    char& operator[](unsigned int i)    //UNSAFE TBD
    {
        return str[i];
    }

    friend std::ostream& operator<<(std::ostream& stream, String s);

};

std::ostream& operator<<(std::ostream& stream, String s)
{
  stream << "\"" << s.str << "\""; //operator<<(std::ostream&, const char*)

  return stream;
}


String makeSuperString()
{
    String result("Super String");

    return result;
}


TEST_CASE("Test Concatenation")
{   
    String a("Hello"), b("World"), c("HelloWorld");

    CHECK((a+b==c));

    a = "123";
    b = "456";

    a += b;
    CHECK(a=="123456");

    a += a;
    CHECK(a=="123456123456");
}

TEST_CASE("Test Copy Contructor")
{
    String a("Hello"),b(a);

    CHECK(a==b);

    a[0] = 'z';

    CHECK(a!=b);
}

TEST_CASE("Test Assignment")
{
    String a("Hello"),b;

    b = a;

    CHECK(a==b);

    a[0]='z';

    CHECK(a!=b);
}

int main()
{
    doctest::Context().run();
}