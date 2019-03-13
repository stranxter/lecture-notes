#include <iostream>
#include <cassert>

//#define debug 

template <typename T>
class Vector
{
public:

    Vector()
    {
#ifdef debug
        std::cout << "Create: " << (long)this << std::endl;
#endif
        elements = new T [0];
        nCapacity = 0;
    }

    Vector(const Vector<T> &original)
    {
#ifdef debug
        std::cout << "Copy: " << (long)&original << "->" << (long)this << std::endl;
#endif
        nCapacity = original.nCapacity;
        elements = new T[nCapacity];
        for (size_t i = 0; i < nCapacity; i++)
        {
            elements[i] = original.elements[i];
        }
    }
    // v2 = v1; //v2.operator=(v1)
    // v = v
    Vector<T>& operator=(const Vector<T> &original)
    {
        if (this != &original)
        {
#ifdef debug
            std::cout << "Assign: " << (long)&original << "->" << (long)this << std::endl;
#endif            

            delete []elements;
            nCapacity = original.nCapacity;
            elements = new T[nCapacity];
            for (size_t i = 0; i < nCapacity; i++)
            {
                elements[i] = original.elements[i];
            }
        }
        return *this;
    }
    // v3 = v1 + v2;
    // (v1 + v2).print();
    Vector<T> operator + (const Vector<T> &other) 
    {
        Vector<T> result (*this);
        //!!!много неефективно
        for (size_t i = 0; i < other.nCapacity; i++)
        {
            result.push (other.elements[i]);
        }
        return result;
    }
    Vector<T>& operator+=(const Vector<T> &other)
    {
        for (size_t i = 0; i < other.nCapacity; i++)
        {
            push(other.elements[i]);
        }
        return *this;
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
#ifdef debug
        std::cout << "Destroy: " << (long)this << std::endl;
#endif
        delete elements;
    }

    //v[1] = 12
    //v.operator[](1) = 12
    //x=v[1]

    T& operator[] (size_t i)
    {
        assert (i < nCapacity);
        return elements[i];
    }

    T operator[](size_t i) const
    {
        assert(i < nCapacity);
        return elements[i];
    }

    size_t size() const
    {
        return nCapacity;
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
Vector<T> map(const Vector<T> &original, T (*f)(T))
{
    Vector<T> result;
    for (size_t i = 0; i < original.size(); i++)
    {
        result.push(f (original[i]));
    }
    return result;
}

template <typename T>
using pred = bool (*) (T);

template <typename T>
Vector<T> filter(const Vector<T> &original, pred<T> p)
{
    Vector<T> result;
    for (size_t i = 0; i < original.size(); i++)
    {
        if (p(original[i]))
        {
            result.push (original[i]);
        }
    }
    return result;   
}

int p1 (int x)
{
    return x+1;
}

void test1 ()
{
    Vector<int> v1;

    v1.push(10);
    v1.push(20);
    v1.push(30);
    //вместимост 3
    v1.print();

    v1.push(40);

    //вместимост 4
    v1.print();

    // std::cout << "v1[1]=" << v1[1] << std::endl;

    std::cout << "Calling f:\n";
    f(v1);
    v1.print();

    Vector<int> v2;
}

void testAssignment ()
{
    Vector<int> v1;

    v1.push (10);
    v1.push (20);
    v1.push (30);

    Vector<int> v2;

    //v2 = v1;
    //v2.operator=(v1);
    (v2 = v1).print();

    Vector<int> v3;

    v3 = v2 = v1;
    //v3.operator=(v2.operator=(v1));

    (v1 + v1 + v1).print();

}

int sumv (const Vector<int>& vi)
{
    int sum = 0;
    for (size_t i = 0; i < vi.size(); i++)
    {
        sum += vi[i];
    }

    return sum;
}

bool even (int i)
{
    return i % 2 ==0;
}

void test3()
{
    Vector<int> v1;

    v1.push(10);
    v1.push(21);
    v1.push(31);

    std::cout << v1[1] << std::endl;

    //v1.operator[](10) = 60
    v1[2] = 60;
    v1.print();

    Vector<int> v2;
    v2.push (8);

    sumv(v1+v2);

    //<int>!!!
    filter<int> (v1+v2, [](int x)->bool{return x%2 == 0; }).print();
    map (filter (v1+v2, even),p1).print();
}

int main ()
{

    //test1();
    //testAssignment();
    test3();

    
    return 0;

/*    Vector<int> v3;

    v3 = map<int> (v1,p1);
    v3.print();
*/
}

