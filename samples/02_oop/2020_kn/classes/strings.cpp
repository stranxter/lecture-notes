#include <iostream>
#include <cstring>
#include <cassert>

class String
{
    public:
    char str[255];
    //char *str;


    String (char *s)
    {
        init (s);
    }

    String ()
    {
        init ("");
    }

    String (char c)
    {
        init (c);
    }

    void init (const char *value)
    {
        strcpy (this->str,value);
    }

    void init (char c)
    {
        str[0] = c;
        str[1] = 0;
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

    /*
    int x = 1;
    y = x + 3;
    x += 1;
    */
    String operator += (char c)
    {
        assert (strlen (this->str) < 254);
        size_t len = strlen(this->str);
        this->str[len] = c;
        this->str[len+1] = 0;   
        return *this;
    }

    String operator += (String s)
    {
        assert (this->length() + s.length() < 255);
        strcat (this->str,s.str);
        return *this;
    }

    // A.operator @ (B)
    // A @ B

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

    char operator [] (size_t i)
    {
        return str[i];
    }

    //s + c
    String operator + (char c)
    { 
        assert (strlen (str) < 254);
        // X X X X X X X 0 ? ? ? ? ? ?
        // X X X X X X X c 0 ? ? ? ? ?
        String result;
        result.init (this->str);
        size_t len = strlen(result.str);
        result.str[len] = c;
        result.str[len+1] = 0;   
        return result;
    }
};

String operator + (char c, String s)
{
    String result (c);
    result += s;
    return result;
}

std::ostream& operator << (std::ostream& out, String s)
{
   out << s.str; 
   return out;
}

String toString (unsigned int x)
{
    String result;
    result.init("");
    if (x < 9)
    {
        result += ('0' + x);
    } else {
        while (x > 0)
        {
            //result = operator+ ('0' + x % 10,result);
            result = ('0' + x % 10) + result; //най-дясна цифра
            x /= 10;
        }
    }
    return result;
}

String reverse (String s)
{
    String result;
    result.init ("");

    for (int i = s.length()-1; i >= 0; i--)
    {
        result = result + s[i];
    }
    return result;
}

/*
    toUpper ('c').print ();
    toUpper ("hello").print ();
    toUpper (s1).print();

*/
String toUpper (String s)
{
    String result;
    result.init ("");

    for (size_t i = 0; i < s.length(); i++)
    {
       if (s[i] >= 'a' && s[i] <= 'z')
       {
           result += (s[i] + ('A'-'a'));
       } else {
           //result = result + s[i];
           result += s[i];
       }
    }
    return result;
}

void f (String s)
{

}

int main ()
{
    
    int x (5), y = 5;
    
    String s1 ("Hello"),
           s2 (" world!"),
           s4 ('c');

    String s3 (s1);

    //s3 = s1.concat (s2);
    //s1.operator + (s2)
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

    toUpper (s1).print();

    s1.print();

    s1 += 'Z';
    s1.print();

    reverse(s1).print();
    toString (1234).print();
    
    //operator << (std::ostream&, String s)
    operator << (operator << (std::cout, s1), "\n");
    std::cout << s1 << "\n";

    (s1 += 'U').print();

    toUpper ('c').print ();
    toUpper ("hello").print ();


};