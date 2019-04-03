#include "string.h"

String::String()
{
    str = new char[1];
    str[0] = 0;
}

String::String(const char *s)
{
    str = new char [strlen(s)+1];
    strcpy (str,s);
}

String::String(const String &other)
{
    str = new char [strlen(other.str)+1];
    strcpy (str,other.str);
}

String::~String()
{
    delete []str;
}

bool String::operator!=(const String &other) const
{

    return strcmp (str,other.str) != 0;
}

String& String::operator=(const String &other)
{
    if (this != &other)
    {
        delete str;
        str = new char[strlen(other.str)+1];
        strcpy (str,other.str);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const String &s)
{
    out << s.str;
    return out;
}

String String::operator+(const String &other) const
{
  
    String result (*this);
    result += other;
    return result;
}

String& String::operator+=(const String &other)
{
    
    char *save = str;
    str = new char[strlen(save) + strlen(other.str) + 1];
    strcpy(str, save);
    strcat(str, other.str);
    delete save;

    return *this;
}

char String::operator[](size_t i) const
{
    assert (i < strlen (str));
    //TODO optimize this!!!!!!!!

    return str[i];
}