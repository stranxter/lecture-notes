#include <cstdlib>
#include <iostream>

template <class T>
class Vector
{
    public:
    T *data;
    size_t size;

    Vector ()
    {
        data = nullptr;
        size = 0;
    }

    Vector (const Vector<T>& other)
    {
       this->data = new T [other.size];
       for (size_t i = 0; i < other.size; ++i)
       {
           this->data[i] = other.data[i];
       }
       this->size = other.size; 
    }

    void to_end (T x)
    {
        
        T *bigger_buffer = new T [size+1];
        for (size_t i = 0; i < size; i++)
        {
            bigger_buffer[i] = data[i];
        }
        bigger_buffer[size] = x;
        ++size;

        delete []data;
        data = bigger_buffer;

    }

    void push (T x)
    {
        T *bigger_buffer = new T [size+1];

        for (size_t i = 0; i < size; i++)
        {
            bigger_buffer[i+1] = data[i];
        }
        bigger_buffer[0] = x;
        ++size;

        delete []data;
        data = bigger_buffer;      
    }

    //IntVector operator + (IntVector);

    void operator += (T x)
    {
        to_end (x);
    }

    T& operator [] (size_t i)
    {
        return data[i];
    }

    Vector<T>& operator= (const Vector<T>& other)
    {
       if (this != &other)
       {
            delete []this->data; 

            this->data = new T [other.size];
            for (size_t i = 0; i < other.size; ++i)
            {
                this->data[i] = other.data[i];
            }
            this->size = other.size; 
       }
       return *this;
    }

    ~Vector ()
    {
        delete data;
    }

};

template <class T>
std::ostream& operator << (std::ostream& stream, Vector<T> v)
{
    for (size_t i = 0; i < v.size; i++)
    {
        stream << v.data[i] << " ";
    }
    return stream;
}

int main ()
{

    Vector<int> v;

    v += 1;
    v.to_end(2);
    v.to_end(3);
    v.push(4);

    std::cout << "[" << v << "]" << std::endl;
    std::cout << v[2] << std::endl;

    v[2] = 7;

    std::cout << "[" << v << "]" << std::endl;

    Vector<int> v2 (v); //v2.data = v.data

    std::cout << "v = " << v << std::endl;
    std::cout << "v2 = " << v2 << std::endl;

    v[0] = 100;

    std::cout << "v = " << v << std::endl;
    std::cout << "v2 = " << v2 << std::endl;

    v.push (7);

    std::cout << "v = " << v << std::endl;
    std::cout << "v2 = " << v2 << std::endl;

    Vector<int> v3;
    v3.push (0);

    //v3.operator= (v);
    v3 = v;
    std::cout << v3 << std::endl;
    v[0] = 777;
    std::cout << v3 << std::endl;

    //v3.operator=(v.operator=(v2));
    (v3 = v)[0] = 555;
    std::cout << v3 << std::endl;



}