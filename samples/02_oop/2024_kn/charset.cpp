#include <iostream>
#include <cassert>
#include <fstream>


class CharSet {

    public:

    bool contents[26]; 

    void insert(char c)
    {
        assert(c >= 'a' && c <= 'z');
        contents[c-'a'] = true;
    }

    void init()
    {
        for(int i = 0; i < 26; ++i)
        {
            contents[i]=false;
        }
    }

    bool empty() 
    {
        //this
        for (int i = 0; i < 26; i++) 
        {
            if (this->contents[i])
            {
                return false;
            } 
        }
        return true;
    }

    CharSet operator+(char c) const
    {
        CharSet result =  *this;

        result.insert(c);
        return result;
        
    } 

    CharSet& operator+=(char c)
    {
        this->insert(c);
        return *this;
    }

    CharSet operator+(CharSet other) const
    {   //this:
        CharSet result;
        for (int i = 0; i < 26; i++)
        {
            result.contents[i] = this->contents[i] || other.contents[i]; 
        }
        return result;
    }

};

std::ostream& operator<<(std::ostream& out, CharSet s)
{
    out << "{";
    for(int i = 0; i < 26; ++i)
    {
        if (s.contents[i])
        {
            out << (char)('a' + i) << " ";
        }
    }
    out << "}";
    return out;
}


int main()
{
    CharSet s1,s2;

    s1.init(); s2.init();

    s1 += 'a';
    s1 += 'b';
    s1 += 'c';
    
    s2 += 'c';
    s2 += 'd';

    std::ofstream f("set.txt");
    std::cout << s1+s2;
    f << s1+s2;



}