#include <iostream>

class CharSet 
{
    public:


    void clear()
    {
        for (int i=0; i < 26; ++i)
        {
            contents[i] = false;
        } 
    }

    CharSet()
    {
        clear();
    }

    //приемаме, че c е малка буква от л. азбука
    CharSet(char c)
    {
        clear();
        contents[c-'a'] = true;
    }

    //приемаме, че s е символен низ, съставен само от
    // малки букви от л. азбука
    CharSet(const char *s)
    {
        clear();
        for (int i = 0; i < strlen(s); ++i)
        {
            contents[s[i]-'a'] = true;
        }
    }


    bool contents[26]; 
    bool empty()
    {
        for (int i = 0; i < 26; i++)
        {
            if (contents[i])
            {
                return false;
            }
        } 
        return true;
    }

    CharSet operator+(CharSet other)
    {
        CharSet result;
        for (int i = 0; i < 26; ++i)
        {
            result.contents[i] = contents[i] || other.contents[i];
        }
        return result;
    }
};


int main()
{

    CharSet *cs = new CharSet('z');

    CharSet a,b,c;

    std::cout << a.empty();
    std::cout << b.empty();

    c = a.operator+(b);

    c = a + b;

    CharSet d("Hello");
    CharSet s('x');

    delete cs;

    cs = new CharSet('q');
}