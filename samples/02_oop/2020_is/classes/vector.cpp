#include <iostream>


class IntVector
{
    public:
    int *data;
    size_t size;

    IntVector ()
    {
        size = 0;
        data = nullptr;
    }

    IntVector (const IntVector& v)
    {
        this->size = v.size;
        this->data = new int [v.size];
        for (size_t i = 0; i < size; ++i)
        {
            this->data[i] = v.data[i];
        }
    }

    void push_back (int x)
    {
        //data -> [1,2,3,4,5,6,7,8]
        //size:8

        int *biggerBuffer = new int[size+1];
        for (size_t i = 0; i < size; ++i)
        {
            biggerBuffer[i] = data[i];
        }
        biggerBuffer[size] = x;
        ++size;
        
        delete data;      
        data = biggerBuffer;
    }

    void push (int x)
    {
        int *biggerBuffer = new int[size+1];
        for (size_t i = 0; i < size; ++i)
        {
            biggerBuffer[i+1] = data[i];
        }
        biggerBuffer[0] = x;
        ++size;
        
        delete data;      
        data = biggerBuffer;

    }

    IntVector operator+ (IntVector other)
    {
        IntVector result;

        result.data = new int [this->size + other.size];
        for (size_t i = 0; i < this->size; ++i)
        {
            result.data[i] = this->data[i];
        }
        for (size_t i = 0; i < other.size; ++i)
        {
            result.data[this->size+i] = other.data[i];
        }

        result.size = this->size + other.size;
        return result;
    }

    int& operator[] (size_t i)
    {
        return data[i];
    }

};
std::ostream& operator << (std::ostream& stream, IntVector v)
{
    for (size_t i = 0; i < v.size; ++i)
    {
        std::cout << v.data[i] << " ";
    }

    return stream;
}

void f (IntVector w)
{
    w[0] = 0;
    std::cout << w;
}

int main ()
{
    IntVector v;

    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    v.push(10);
    v.push(11);
    v.push(12); //[12,11,10,0,1,2]

    std::cout << v << std::endl;

    IntVector v2;
    v2.push_back(7);
    v2.push_back(8);
    v2.push_back(9);

    std::cout << "result = " << v.operator+(v2) << std::endl << v + v << std::endl;

    std::cout << v[3] << std::endl;

    v[3] = 17;

    std::cout << v[3] << std::endl;

    IntVector copied = v;

    std::cout << v[0] << std::endl;
    copied[0] = 999;
    std::cout << v[0] << std::endl;

    copied.push(9);
    std::cout << v << std::endl;

    IntVector v5;
    v5.push_back (200);
    v5.push_back (200);
    v5.push_back (200);
    v5.push_back (200);

    std::cout << v << std::endl;


    return 0;
}