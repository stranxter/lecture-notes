#include <iostream>
#include <fstream>


template <typename T>
class DynArray
{
    public:
    T *arr;
    unsigned int size;

    void init()
    {
        this->size = 0;
        this->arr = nullptr;    
    }

    void push_back(T x)
    {
        /*
            a:{
                arr -------------> [1] [2] [3]
                size: 3
            }
        */
    T* tmp = new T[this->size+1];
        /*
            a:{
                arr -------------> [1] [2] [3]
                size: 3
            }
            tmp ----------------> [13134] [756] [12313] [464745]
        */
    for(int i = 0; i < this->size; ++i)
    {
        tmp[i] = this->arr[i];
    }
        /*
            a:{
                arr -------------> [1] [2] [3]
                size: 3
            }
            tmp ----------------> [1] [2] [3] [464745]
        */
    tmp[this->size] = x;
    this->size++;
        /*
            a:{
                arr -------------> [1] [2] [3]
                size: 4
            }
            tmp ----------------> [1] [2] [3] [x]
        */
        delete []this->arr;
        this->arr = tmp;
        /*
            a:{
                arr --------\ ~~~~~~~~~~~~~~~~~~~
                size: 4      \
            }              |
            tmp ----------------> [1] [2] [3] [x]
        */
    }

    //c=a+b
    DynArray<T> operator+(DynArray<T> b)
    {
        DynArray<T> result;
        result.init();
        (result += *this) += b;

        return result;
    }

    DynArray<T>& operator+=(T x)
    {
        push_back(x);
        return *this;
    }

    //(a += b)
    DynArray<T>& operator+=(DynArray<T> b)
    {
        /*
            a:{
                arr -------------> [1] [2] [3] [4] [5] [+1] [+2] [+3]
                size: 5
            }
            b:{
                arr -------------> [1] [2] [3]
                size: 3
            }
        */

        T* tmp = new T[this->size+b.size];
        for(int i = 0; i < this->size; ++i)
        {
            tmp[i] = this->arr[i];
        }
        for(int i = this->size; i < this->size+b.size; ++i)
        {
            tmp[i] = b.arr[i-this->size];
        }

        this->size = this->size + b.size;
        delete []this->arr;
        this->arr = tmp;

        return *this;
    }

//    bool equals(DynArray<T> b)
    bool operator==(DynArray<T> b)
    {
        if(this->size != b.size)
        {
            return false;
        }
        for(int i = 0; i < this->size; ++i)
        {
            if(this->arr[i] != b.arr[i])
            {
                return false;
            }
        }
        return true;
    }

};


template<typename T>
std::ostream& operator<<(std::ostream& out,DynArray<T> arr)
{   //DynArray<T>* this;
    out << "{";
    for(int i = 0; i < arr.size; ++i)
    {
        out << arr.arr[i] << " ";
    }
    out << "}";

    return out;
}



int main()
{
    DynArray<int> a;
    a.init();

    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);
    a.push_back(50);

    std::cout << a;

    //remove_element(a,3);
    //printArray(a);

    DynArray<int> b;
    b.init();

    ((b+=10)+=20)+=30;
    int x = 0, y =5;

    std::cout << ((a += b) += 30);

    std::cout << (a == b) << std::endl;
    std::cout << (a == a) << std::endl;

    DynArray<int> c;
    c.init();
    c.push_back(10);
    c.push_back(20);
    c.push_back(30);
    std::cout << b;
    std::cout << c;
    std::cout << (b == c) << std::endl;

    c.push_back(10);
    std::cout << (b == c) << std::endl;

    DynArray<int> z;

    z = a + b;

    std::cout << "a=" << a << " thank you and good bye!\n";
    std::cout << b;
    std::cout << z;

    std::ofstream f("kalin.txt");

    f << z;

    std::cout << "\n\n\n\n\n";

    DynArray<DynArray<int>> m;
    std::cout << (((m+=a)+=b)+=c);

}