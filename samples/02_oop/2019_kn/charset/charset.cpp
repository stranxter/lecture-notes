#include <iostream>
#include <cassert>
#include <cstring>

class CharSet
{
public:

    CharSet (const char* str)
    {   
        std::cout << "CharSet (char*)\n";
        clear ();
        for (size_t i = 0; i < strlen(str); i++)
        {
            add (str[i]);
        }
    }
    
    CharSet(char c)

    {
        std::cout << "CharSet (char)\n";
        clear();
        add(c);
    }

    CharSet(unsigned int c)
    {
        std::cout << "CharSet (int)\n";
        clear();
        for (unsigned int i = 0; i < c; i++)
        {
            add('a'+i);
        }
    }

    CharSet(const CharSet &original)
    {
        clear();
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (original.member(c))
            {
                add (c);
            }
        }
    }

    CharSet ()
    {
        clear();
    }

    bool member (char c) const
    {
        assert (c>='a' && c <= 'z');
        return set[c-'a'];
    }

    void add (char c)
    {
        assert(c >= 'a' && c <= 'z');
        set[c-'a'] = true;
    }

    void remove(char c)
    {
        assert(c >= 'a' && c <= 'z');
        set[c - 'a'] = false;
    }

     void print () const
     {
        std::cout << "--------" << (long)this << "-----\n";
         for (char c = 'a'; c <= 'z'; c++)
         {
             std::cout << c << ":";
             if (member (c))
             {
                 std::cout << "YES" << std::endl;
             } else {
                 std::cout << "NO" << std::endl;
             }
         }
     }

     void clear ()
     {
        for (char c = 'a'; c <= 'z'; c++)
        {
            remove(c);
        }
     }

  private:
    bool set[26];
};

class A
{
    public:
    int x;
};

void f (CharSet s)
{
    s.print();
}

int main ()
{

    const CharSet set1 ("abc"); 
    CharSet set2 ("def");
    CharSet set3 ('c');
    CharSet set4 ((unsigned int)4);

    CharSet set5 (set1);

    set1.print();
    set5.print();

  
    set1.print();
    f (set1);

    CharSet set6;
    set6.print();

}