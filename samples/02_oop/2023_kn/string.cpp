#include <iostream>
#include <cstring>


class String
{
    public:


    String()
    {

    }

    char *str;

    void init(const char *s)
    {
        str = new char[strlen(s)+1];
        strcpy(str,s);
    }

    String operator+(String other)
    {

        String result;
        result.str = new char[strlen(this->str)+strlen(other.str)+1];

        strcpy(result.str,this->str);
        strcat(result.str,other.str);

        return result;
    }

    //d = a * 4;
    String operator*(unsigned int n)
    {
        String result;
        result.init(this->str);

        while (n > 1)
        {
            result = result + *this;
            --n;
        }

        return result;
    }

    bool operator==(String other)
    {
        return strcmp(this->str,other.str)==0;
    }

};

std::ostream& operator<<(std::ostream& stream, String s)
{
  stream << "\"" << s.str << "\""; //operator<<(std::ostream&, const char*)

  return stream;
}


int main()
{

    String a("Hello"),b,c(" World!");

    //String d = a + b + c;

    String d;
    
    d = a + b + c; //a.operator+(b)

    d = a * 4;

    a = d;
   
    std::cout << a.str << std::endl;
    std::cout << d.str << std::endl;

    a.str[0] = '!';

    std::cout << a.str << std::endl;
    std::cout << d.str << std::endl;

    (std::cout << d) << "!" << std::endl;

    




}