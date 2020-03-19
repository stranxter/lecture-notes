#include <iostream>
#include <cstring>
#include <fstream>

class String 
{
    public:
    char *str;

    String ()
    {
        init ("");
    }
    
    String (const char *s)
    {
        init (s);
    }

    String (char c)
    {
        str = new char[2];
        str[0] = c;
        str[1] = 0;
    }

    String (const String &other)
    {
        str = new char [other.length() + 1];
        strcpy (str, other.str);
    }
    
    void init (const char *s)
    {
        str = new char[strlen(s)+1];
        strcpy (str,s);
    }

    //s1.print();
    void print ()
    {
        std::cout << str << std::endl;
    }

    String operator+ (char c)
    {
     
        String result;
        //this->str -----> a b c \0 ....  | + z
        result.str = new char [length() + 1 + 1];
        //X X X X X
        strcpy (result.str, str);
        //a b c \0 X
        result.str[this->length()] = c;
        //a b c z X
        result.str[this->length()+1] = 0;
        //newBuffer ---->  a b c z \0

        return result;

    }

    String operator+ (String other)
    {
        String result;
        result.str = new char[strlen(str)+strlen(other.str)+1];

        strcpy (result.str,str);
        strcat (result.str,other.str);

        return result;
    }
    //if (s1 == s2)
    bool operator== (String other)
    {
        return strcmp (str,other.str) == 0;
    }
    bool operator< (String other)
    {
        return strcmp (str,other.str) < 0;
    }
    size_t length () const
    {
        return strlen (str);
    }
    char& operator[] (size_t i)
    {      
        return str[i];
    }

    //result = '0' + x;
    //result.operator=('0'+x)
    String operator= (char c)
    {
        str = new char [2];
        str[0] = c;
        str[1] = 0;
        return *this;
    }
};

String operator+ (char c, String s)
{
    String result;

    result = c;
    result = result + s;
    return result;

}

String toString (unsigned int x)
{
    String result;
    
    if (x < 10)
    {
        //result.operator= ('0'+x);
        result = '0' + x;
        return result;
    }
    while (x > 0)
    {
        //A @ b
        //A.operator@(b)
        //result.operator+ ('0' + x%10);
        //b @ A
        //b.operator@(A)
        //A @ b
        //operator@ (A,b)
        result = ('0' + x%10) + result;
        x /= 10;

    }

    return result;
}

String toUpper (String s)
{
    String result = s.str;

    for (size_t i = 0; i < result.length(); i++)
    {
        if (result[i]>= 'a' && result[i] <= 'z')
        {
            result[i] = result[i] + ('A'-'a');
        }
    }
    return result;
}

std::ostream& operator<< (std::ostream& out, String s)
{
    out << s.str;
    return out;
}

std::istream& operator>> (std::istream& in, String& s)
{
    char c;
    do 
    {
        c = in.get();
        if (c != '\n')
        {
            s = s + c;
        }
    } while (c != '\n');

    return in;    
}


int main ()
{
    String s1 = "Hello", s2 = " world!";

    s1.print (); 

    String s3 = s1.operator+ (s2);  
    s3.print ();

    s1.operator+(s2).print();

    (s1 + s2).print ();

    //s3.operator=(s1+s2);
    s3 = s1 + s2;
    s3.print ();

    String s4 = s1;
    if (s1 == s4)
    {
        std::cout << "s1 == s2" << std::endl;
    } else 
    {
        std::cout << "s1 != s2" << std::endl;
    }

    if (s1 < s2)
    {
        std::cout << "s1 < s2" << std::endl;
    } else 
    {
        std::cout << "s1 < s2" << std::endl;
    }

    //s3.operator=(s1=s2)
    //s3.operator=(s1.operator=(s2))
    s3 = s1 = s2;
    (s1 = s2).print ();

    //operator<< (operator<< (std::cout,s1),std::endl);
    std::cout << s1 << std::endl;

    std::cout << toUpper(s1) << std::endl;

    std::cout << toString(12345) << std::endl;

    std::cout << "Please input a string:";
    std::cin >> s1;
    std::cout << "You hust entered: " << s1 << std::endl;

    String s4 = 'c';

}
