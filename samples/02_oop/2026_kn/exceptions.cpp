#include <iostream>
#include <exception>


class OOMException : public std::exception
{
    public:
    const char* what() const noexcept override
    {
        return "Ouf of memory excption!";
    }
};

class BadTypeExction : public std::exception
{
    public:
    const char* what() const noexcept override
    {
        return "Expect unsigned number!";
    }
};

struct arr
{
    unsigned *data;
    unsigned size, capacity;

    arr(unsigned _capacity)
    {
        capacity = _capacity;
        data = new unsigned[capacity];
        size = 0;
    }

    arr& push_back(int x)
    {
        if(size >= capacity)
        {
            throw OOMException();
        }
        if(x < 0)
        {
            throw BadTypeExction();
        }
        data[size++] = x;
        return *this;
    }

    void print()
    {
        for(unsigned i = 0; i < size; ++i)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

class VeryHeavyResource
{
    public:
    VeryHeavyResource() {std::cout<<"Resource allocated!\n";++i;}
    ~VeryHeavyResource() {std::cout<<"Resource DEallocated!\n";}

    private:
    static int i;
};

int VeryHeavyResource::i = 0;

void input(arr &a)
{
    VeryHeavyResource r;
    int x;
    std::cout << "Data, please...";
    std::cin >> x;
    a.push_back(x);
    std::cout << "Thank you!\n";
}

int main()
{
    arr a(2);

    try{
        //a.push_back(1).push_back(2).push_back(3).push_back(4);
        input(a);
        input(a);
        input(a);
        input(a);
        input(a);
/*        
    } catch (const OOMException&){
        std::cerr << "Out of memory exceptio!\n" << std::endl;
    } catch (const BadTypeExction&)
    {
        std::cout << "Only unasigned number accepted.\n";
    }
*/  }catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;        
    }

    a.print();

    std::cout << "Success!\n";
}
