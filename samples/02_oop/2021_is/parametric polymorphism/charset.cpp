#include <iostream>
#include <cstring>
#include <fstream>

class CharSet 
{
    public:
    
    CharSet()
    {
        clear();
    }

    CharSet(const CharSet& other)
    {
        for (int i = 0; i < 26; ++i)
        {
            contents[i] = other.contents[i];
        }
    }

    CharSet(const char* s)
    {
        clear();  
        for (size_t i = 0; i < strlen(s); ++i)
        {
            contents[s[i]-'a']=true;
        }
    }

    CharSet(char c)
    {
        clear();
        contents[c-'a'] = true;
    }

    CharSet(unsigned int n)
    {
        clear();
        for (size_t i = 0; i < n; ++i)
        {
            contents[i]=true;
        }     
    }

    bool contents[26]; 

    void clear()
    {
        for (size_t i = 0; i < 26; ++i)
        {
            contents[i] = false;
        }
    }

    bool empty()
    {
        for (int i = 0; i < 26; ++i)
        {
            if (contents[i] == true)
            {
                return false;
            }
        } 
        return true;
    }
    void print()
    {
        std::cout << "{";
        for (int i = 0; i < 26; ++i)
        {
            if (contents[i] == true)
            {
                std::cout << (char)('a'+i) << " ";
            }
        }
        std::cout << "}" << std::endl;
    }

    CharSet setUnion(CharSet other)
    {
        CharSet result;
        for (int i = 0; i < 26; ++i)
        {
            result.contents[i] = contents[i] || other.contents[i];
        }
        return result;
    }

    bool operator==(CharSet other)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (contents[i] != other.contents[i])
            {
                return false;
            }
        }
        return true;
    }

};


CharSet operator+(CharSet s1, CharSet s2)
{
    CharSet result;
    for (int i = 0; i < 26; ++i)
    {
        result.contents[i] = s1.contents[i] || s2.contents[i];
    }
    return result;

}    

std::ostream& operator<< (std::ostream& out, CharSet s)
{
    out << "{";
    for (int i = 0; i < 26; ++i)
    {
        if (s.contents[i] == true)
        {
            out << (char)('a'+i) << " ";
        }
    }
    out << "}" << std::endl;   
    return out;
     
}

std::istream& operator>> (std::istream& in, CharSet& s)
{
    char input[100];
    in >> input;
    s.clear();
    for (size_t i = 0; i < strlen(input); ++i)
    {
        s.contents[input[i]-'a']=true;
    }
    return in;
}

void addA(CharSet s)
{
    s.contents[0] = true;
    std::cout << s;
}

int main()
{

    CharSet s5("hello"), s6('a'), s7("a"), s8((unsigned int)7);
    std::cout << s5;

    addA(s5);
    addA("hello");

    CharSet s1(s5),s2,s3,s4;

    std::cout << s1.empty() << std::endl; 
    std::cout << s2.empty() << std::endl;
    std::cout << s3.empty() << std::endl;

    s1.print();
    s2.print();
    s3.print();

    s1.setUnion(s4).print();

    if (s1 + s4 == s2)
    {

    } 
  
    std::cout << s1 << s2 << s3;

    std::cin >> s1;

    std::ofstream f1 ("myfile1.txt");
    std::ofstream f2 ("myfile2.txt");
    std::ifstream f3 ("myfile3.ivan");

    f1 << "Kalin" << std::endl << 2238237 << std::endl << 2323.1221 << std::endl << s1;

    //f3 << s1;
    f3 >> s1;


    std::cout << s1;
    
}