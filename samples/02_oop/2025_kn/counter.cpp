#include <iostream>
#include <cstring>



class Counter
{
    public:
    void inc()
    {
        ++currentValue;
    };
    
    unsigned value()
    {
        return currentValue;
    };

    void print()
    {
        std::cout << label << "=" << currentValue << std::endl;
    };

    Counter(const char *l)
    {
        strcpy(label,l);
        currentValue = 0;
        std::cout << "Counter " << label << " is being created.\n";
    }    
    Counter(const char *l, unsigned init)
    {
        strcpy(label,l);
        currentValue = init;
        std::cout << "Counter " << label << " is being created.\n";
    }
    Counter(double d)
    {
        strcpy(label,"Noname");
        currentValue = d;
        std::cout << "Counter " << label << " is being created.\n";
    }
   Counter()
    {
        strcpy(label,"Noname");
        currentValue = 0;    
        std::cout << "Counter " << label << " is being created.\n";
    }

    ~Counter()
    {
        std::cout << "Counter " << label << " is being released.\n";
    }

    private:
    unsigned currentValue;
    char label[50];

};



int main()
{

    Counter *c4 = new Counter("Dynamic Exmple");

    {
        Counter c1("Count Chickens", 10), 
                c2("Count Potatos"), 
                c3(5.5);
                

        c1.inc();
        c2.inc();
        c2.inc();


        c1.print();
        c2.print();


        c4->print();
        //c1 == c2, ++c1, ..
    }
    delete c4;

    c4 = new Counter("Another Example");
    delete c4;
    c4 = new Counter("Another Example 1");
    delete c4;
    c4 = new Counter("Another Example 2");
    delete c4;
    c4 = new Counter("Another Example 3");
    delete c4;
    c4 = new Counter("Another Example 4");
    delete c4;
    c4 = new Counter("Another Example 5");
    delete c4;

}