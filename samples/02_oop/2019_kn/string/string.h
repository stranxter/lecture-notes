#ifndef __STRING_H
#define __STRING_H

#include <cstring>
#include <iostream>

class String
{
public:
    String ();
    String (const char*);
    String (const String&);

    String operator + (const String&) const;
    String& operator += (const String&);

    char operator [] (size_t) const;


    String& operator = (const String&);
    bool operator != (const String&) const;
    ~String();

    friend std::ostream &operator<<(std::ostream &, const String &);

  private:
    char *str;
};

std::ostream& operator<<(std::ostream &, const String&);

#endif