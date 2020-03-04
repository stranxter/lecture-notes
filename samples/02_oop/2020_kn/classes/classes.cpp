#include <iostream>

class CharSet 
{    
    public:
    //предтсвяне

    bool contents [26];
    
    //операции
    
    void init ()
    {
        //CharSet *this = ...;
        for (int i = 0; i < 26; i++)
        {
            this->contents[i] = false;
        }
    }
    bool empty ()
    {
        //CharSet *this = ...;
        for (int i = 0; i < 26; i++) 
        {
            if (this->contents[i])
                return false;
        }
        return true;
    }
    CharSet setUnion (CharSet b)
    {
        CharSet result;
        for (int i = 0; i < 26; i++)
        {
            result.contents[i] = this->contents[i] || 
                                 b.contents[i];
        }
        return result;        
    }
};

bool empty_old (CharSet* mythis)
{
    //.... mythis->contents ...
    return false;
}

int main ()
{

    CharSet s1, s2;

//    empty_old (&s1);
//    empty_old (&s2);

    s1.init ();
    //init (&s1);
    s2.init();
    //init (&s2);

    s1.contents[0] = true;
    //s2.contents[0] = false;

    std::cout << s1.empty () << std::endl;
    std::cout << s2.empty () << std::endl;

    CharSet ab = s1.setUnion (s2);
    
}
