#include <iostream>
#include <cassert>

template <typename T>
class Vector
{
public:

    Vector()
    {
        elements = new T [1];
        nCapacity = 1;
    }

    void push (T x) 
    {
        //приемаме, че масивът, сочен от 
        //elemennts е инициализиран и има вместимост точно
        //nCapacity елемента (int elements[nCapacity]);

        T* newElements = new T [nCapacity +1];
        for (size_t i = 0; i < nCapacity; i++)
        {
            newElements[i] = elements[i];
        }
        newElements[nCapacity] = x;

        delete []elements;
        elements = newElements;
        nCapacity++;


    }
    void print () 
    {
        std::cout << "[";
        
        for (size_t i = 0; i < nCapacity; i++)
        {
            std::cout<< elements[i];
            if (i < nCapacity-1)
            {
                std::cout << ",";
            }
        }
        std::cout << "]\n";
    }

    void change (size_t index, T newValue)
    {
        assert (index >= 0 && index < nCapacity);
        elements[index] = newValue;
    }

    ~Vector ()
    {
        delete elements;
    }

  private:
    T* elements;
    size_t nCapacity;
};

void f (Vector<int> v)
{
    v.change (2,90);
    v.print();
}

template <typename T>
Vector<T> map (Vector<T> original, T (*f) (T))
{
    Vector<T> result;
    return result;   
}

int p1 (int x)
{
    return x+1;
}

int main ()
{

    Vector<int> v1;

    v1.push(10);
    v1.push(20);
    v1.push(30);
    //вместимост 3
    v1.print ();

    v1.push(40);

    //вместимост 4
    v1.print ();

   // std::cout << "v1[1]=" << v1[1] << std::endl;

    f (v1);
    v1.print();

    return 0;

    Vector<int> v2;

    v2 = v1;

    Vector<int> v3;

    v3 = map<int> (v1,p1);
    v3.print();

}