#include <iostream>
#include <cstring>

class String 
{
    public:
    char *str;

    //s1.init();
    //s2.init()/
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
    size_t length ()
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

String toString (unsigned int x)
{
    String result;
    result.init ("");
    
    if (x < 10)
    {
        //result.operator= ('0'+x);
        result = result + ('0' + x);
        return result;
    }
    while (x > 0)
    {
        //A @ B
        //A.operator&(B)
        //result.operator+ ('0' + x%10);
        result = result +  ('0' + x%10);
        x /= 10;

    }

    return result;
}

String toUpper (String s)
{
    String result;
    result.init (s.str);

    for (size_t i = 0; i < result.length(); i++)
    {
        if (result[i]>= 'a' && result[i] <= 'z')
        {
            result[i] = result[i] + ('A'-'a');
        }
    }
    return result;
}

int main ()
{
    String s1, s2;

    s1.init ("Hello");
    s2.init (" world!");

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


    toUpper(s1).print();

    toString(12345).print();


/*
    std::cout << 1235;
    std::cout << 1235.988;
    std::cout << "Hello";
    std::cout << s1;
*/
}
