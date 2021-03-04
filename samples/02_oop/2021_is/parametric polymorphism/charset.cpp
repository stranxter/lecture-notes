#include <iostream>

class CharSet 
{
    public:
    
    bool contents [26]; 

    bool empty ()
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
};


int main()
{

    CharSet s1{{false,true}},
            s2{{true,true}},
            s3{{false}},
            s4{{true,false,false,true}};

    std::cout << s1.empty() << std::endl; 
    std::cout << s2.empty() << std::endl;
    std::cout << s3.empty() << std::endl;


    s1.print();
    s2.print();
    s3.print();

    s1.setUnion(s4).print();
    
    
}