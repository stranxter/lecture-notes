#include <iostream>
#include <cassert>

class CharSet
{   
    //!!!
    public:

    bool contents[26];

    //s1.init()
    //s2.init()
    void init ()
    //CharSet *this
    {
        for (size_t i = 0; i < 26; i++)
        {
            this->contents[i] = false;
        }
    }

    //s1.print() --->>> CALL print (&s1)
    //s2.print()
    void print ()
    {   //CharSet *this
        std::cout << "{";
        bool isFirst = true;
        for (size_t i = 0; i < 26; i++)
        {
            if (this->contents[i] == true)
            {
                if (!isFirst)
                {
                    std::cout << ", ";
                }
                std::cout << (char)('a' + i);
                isFirst = false;
            }
        }
        std::cout << "}" << std::endl;
    }

    void add (char c)
    {
        assert (c >= 'a' && c <= 'z');
        this->contents[c-'a'] = true;
    }

    void remove (char c)
    {
        assert (c >= 'a' && c <= 'z');
        this->contents[c-'a'] = false;
    }

    bool empty ()
    {
        for (size_t i = 0; i < 26; i++)
        {
            if (this->contents[i] == true)
            {
                return false;
            }
        }
        return true;
    }

    //setUnion (s1,s2)
    //s1.setUnion (s2)
    CharSet setUnion (CharSet other)
    {
        CharSet result;
        for (size_t i = 0; i < 26; i++)
        {
            result.contents[i] = this->contents[i] || other.contents[i];
        }
        return result;
    }

};

int main ()
{

    CharSet s1, s2;
    s1.init();
    s2.init();

    s1.add ('a');
    s1.add ('b');
    s2.add ('c');
    s2.add ('z');

    s1.print();
    s2.print();

    s1.setUnion (s2).print();

    return 0;
}
